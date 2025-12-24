import networkx as nx
import matplotlib.pyplot as plt

class Graph:
    def __init__(self, matrix):
        self.adj_matrix= matrix
        self.num_vertices= len(matrix)
    
    def __str__(self):
        if not self.adj_matrix:
            return "Do thi rong."
        matrix_str= ""
        for row in self.adj_matrix:
            matrix_str+= " ".join(map(str, row))+"\n"
        return matrix_str
    
    def draw(self):
        if self.num_vertices==0:
            print("Khong ve do thi rong.")
            return 
        G= nx.Graph()
        nodes = range(self.num_vertices)
        G.add_nodes_from(nodes)
        for i in range(self.num_vertices):
            for j in range(i+1, self.num_vertices):
                if self.adj_matrix[i][j]==1:
                    G.add_edge(i,j)
        print("Dang ve do thi...")
        pos = nx.spring_layout(G)
        nx.draw(G, pos, with_labels=True, node_color='skyblue',node_size=800, edge_color='gray', font_size=16, font_weight='bold' )
        plt.title("Hinh anh truc quan cua do thi")
        plt.show()

    def bfs(self, start_vertex):
        if start_vertex>= self.num_vertices:
            print("Loi: Dinh bat dau khong ton tai.")
            return 
        print(f"---Bat dau BFS tu dinh {start_vertex} ---")
        queue=[start_vertex]
        visited= {start_vertex}
        print(f"Tham dinh {start_vertex}")
        while queue:
            current_vertex= queue.pop(0)
            for neighbor in range(self.num_vertices):
                if self.adj_matrix[current_vertex][neighbor]==1 and neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
                    print(f" -> Di chuyen qua canh ({current_vertex}, {neighbor})")
                    print(f"Tham dinh {neighbor}")
        print("--- Ket thuc BFS ---\n")
    
    def _dfs_recursive(self, vertex, visited):
        """Ham de chay thuat toan dfs bang de quy"""
        visited.add(vertex)
        print(f"Tham dinh {vertex}")
        for neighbor in range(self.num_vertices):
            if self.adj_matrix[vertex][neighbor]==1 and neighbor not in visited:
                print(f" ---> Di chuyen qua canh ({vertex}, {neighbor})")
                self._dfs_recursive(neighbor, visited)
    
    def dfs(self, start_vertex):
        if start_vertex>=self.num_vertices:
            print("Loi: dinh bat dau khong ton tai.")
            return
        print(f"--- Bat dau DFS tu dinh {start_vertex} ---")        
        visited=set()
        self._dfs_recursive(start_vertex, visited)
        print("--- Ket thuc dfs ---\n")
