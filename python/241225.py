import networkx as nx
import matplotlib.pyplot as plt

class Graph:
    def __init__(self, matrix):
        self.adj_matrix= matrix
        self.num_vertices= len(matrix)
        
    def __str__(self):
        result=""
        for row in self.adj_matrix:
            result+=" ".join(map(str, row))+"\n"
        return result
    
    def draw(self):
        G= nx.Graph()
        G.add_nodes_from(range(self.num_vertices))
        for i in range(self.num_vertices):
            for j in range(i+1, self.num_vertices):
                if self.adj_matrix[i][j]==1:
                    G.add_edge(i,j)
        pos= nx.spring_layout(G)
        nx.draw(G, pos, with_labels=True,
                node_color="skyblue",
                node_size=800,
                font_size=14)
        plt.title("Do thi bieu dien tu ma tran ke")
        
    def bfs(self, start):
        visited=set()
        queue=[]
        visited.add(start)
        queue.append(start)
        print("---BFS bat dau tu dinh ", start, "---")
        while queue:
            u= queue.pop(0)
            print("Tham dinh ", u)
            for v in range(self.num_vertices):
                if self.adj_matrix[u][v]==1 and v not in visited:
                    visited.add(v)
                    queue.append(v)
                    print(f"Di chuyen ({u}, {v})")
        print("Ket thuc BFS\n")

    def _dfs_recursive(self, u, visited):
        visited.add(u)
        print("tham dinh: ", u)
        for v in range(self.num_vertices):
            if self.adj_matrix[u][v]==1 and v not in visited:
                print(f"Di chuyen ({u}, {v})")
                self._dfs_recursive(v, visited)
    
    def dfs(self, start):
        visited=set()
        print("--- DFS bat dau tu dinh", start, "---")
        self._dfs_recursive(start, visited)
        print("--- Ket thuc DFS ---\n")
matrix = [
    [0, 1, 1, 0, 0, 0],
    [1, 0, 1, 1, 0, 0],
    [1, 1, 0, 0, 1, 0],
    [0, 1, 0, 0, 1, 1],
    [0, 0, 1, 1, 0, 0],
    [0, 0, 0, 1, 0, 0]
]

g = Graph(matrix)

print("Ma tran ke cua do thi:")
print(g)
g.draw()
g.bfs(0)
g.dfs(0)