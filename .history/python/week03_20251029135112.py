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

labels= ["|A| (+2)", "|B| (+3)", "|C| (+5)", "|A giao B| (+6)", "|A giao C| (+10)", "|B giao C| (+15)", "|A giao B giao C| (+30)"]
values= [N//2, N//3, N//5, N//6, N//10, N//15, N//30]

plt.figure()
plt.bar(range(len(values)), values)
plt.xticks(range(len(values)), labels, rotation=30, ha="right")
plt.title("Cac thanh phan trong Inclusion-Exclusion")
plt.tight_layout()
plt.show()