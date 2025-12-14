from math import comb
import matplotlib.pyplot as plt
import numpy as np

for r in range (1,8):
    total=sum((-1)**(k+1)*comb(r,k) for k in range(1, r+1))
    print(f"r={r:<2}-> Tong= {total}")

def pascal_triangle(n):
    """Tao danh sach cac hang cua tam giac pascal"""
    tri= []
    for i in range(n):
        row= [comb(i,k) for k in range(i+1)]
        tri.append(row)
    return tri
print(pascal_triangle(5))

for r in range (1,16):
    total= sum(comb(r, k) for k in range(r+1))
    print (f"r={r:<2}-> Tong= {total}")