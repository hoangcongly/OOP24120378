class Solution:
    def countComponents(self, n:int, edges: list[list[int]])->int:
        graph={i:[] for i in range(n)}
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        visited= set()
        components=0
        def dfs(u):
            visited.add(u)
            for v in graph[u]:
                if v not in visited:
                    dfs(v)
        for i in range(n):
            if i not in visited:
                dfs(i)
                components+=1
        return components
n = 5
edges = [[0, 1], [1, 2], [3, 4]]

# Bước 1: Tạo đối tượng (Khởi tạo class)
sol = Solution() 

# Bước 2: Gọi hàm từ đối tượng vừa tạo
ket_qua = sol.countComponents(n, edges)

print(f"Số thành phần liên thông (số cụm) là: {ket_qua}")
