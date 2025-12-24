# def read_graph_from_file(filename):
#     """
#     Đọc ma trận liên kề từ file và trả về list of lists
#     """
#     matrix = []
#     try:
#         with open(filename, 'r') as file:
#             for line in file:
#                 row = [int(val) for val in line.strip().split()]
#                 matrix.append(row)
#     except FileNotFoundError:
#         print(f"Loi: Khong tim thay file '{filename}'")
#     return matrix


# example_matrix = read_graph_from_file(r'D:\OOP\python\graph_example.txt')
# print("Ma tran ke doc tu file:")
# for row in example_matrix:
#     print(row)

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
            matrix_str+= " ".join(map(str,row))+"\n"
        return matrix_str
    def draw(self):

        
        