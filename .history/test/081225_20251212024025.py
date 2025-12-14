import numpy as np
from openai import OpenAI

client = OpenAI()

# -------------------------------------------
# 1. Load document
# -------------------------------------------
def load_document(path):
    with open(path, "r", encoding="utf-8") as f:
        return f.read()

# -------------------------------------------
# 2. Split into chunks
# -------------------------------------------
def split_text(text, chunk_size=300, overlap=50):
    chunks = []
    start = 0
    while start < len(text):
        end = start + chunk_size
        chunks.append(text[start:end])
        start = end - overlap
    return chunks

# -------------------------------------------
# 3. Embedding
# -------------------------------------------
def embed(text):
    response = client.embeddings.create(
        model="text-embedding-3-small",
        input=text
    )
    return np.array(response.data[0].embedding)

# -------------------------------------------
# 4. Build vector store
# -------------------------------------------
def build_vector_store(chunks):
    vectors = []
    for c in chunks:
        vectors.append(embed(c))
    return vectors

# -------------------------------------------
# 5. Cosine similarity
# -------------------------------------------
def cosine_similarity(a, b):
    return np.dot(a, b) / (np.linalg.norm(a) * np.linalg.norm(b) + 1e-9)

# -------------------------------------------
# 6. Retrieve top-k chunks
# -------------------------------------------
def retrieve(query, chunks, vectors, k=3):
    q_vec = embed(query)
    scores = []

    for i, v in enumerate(vectors):
        score = cosine_similarity(q_vec, v)
        scores.append((score, chunks[i]))

    scores.sort(reverse=True, key=lambda x: x[0])

    return [chunk for _, chunk in scores[:k]]

# -------------------------------------------
# 7. Generate answer (LLM)
# -------------------------------------------
def generate_answer(query, retrieved):
    context = "\n\n".join(retrieved)

    prompt = f"""
Bạn là trợ lý AI. Dựa vào tài liệu sau đây, hãy trả lời câu hỏi:

Context:
{context}

Question:
{query}

Trả lời rõ ràng, chính xác, chỉ dựa trên thông tin có trong context.
"""

    response = client.chat.completions.create(
        model="gpt-4o-mini",
        messages=[{"role": "user", "content": prompt}]
    )

    return response.choices[0].message.content
