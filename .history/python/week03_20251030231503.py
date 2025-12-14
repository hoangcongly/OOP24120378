# from math import comb
# import matplotlib.pyplot as plt
# import numpy as np

# for r in range (1,8):
#     total=sum((-1)**(k+1)*comb(r,k) for k in range(1, r+1))
#     print(f"r={r:<2}-> Tong= {total}")

# def pascal_triangle(n):
#     """Tao danh sach cac hang cua tam giac pascal"""
#     tri= []
#     for i in range(n):
#         row= [comb(i,k) for k in range(i+1)]
#         tri.append(row)
#     return tri
# print(pascal_triangle(5))

# for r in range (1,16):
#     total= sum(comb(r, k) for k in range(r+1))
#     print (f"r={r:<2}-> Tong= {total}")

# N=1000
# labels= ["|A| (+2)", "|B| (+3)", "|C| (+5)", "|A giao B| (+6)", "|A giao C| (+10)", "|B giao C| (+15)", "|A giao B giao C| (+30)"]
# values= [N//2, N//3, N//5, N//6, N//10, N//15, N//30]

# plt.figure()
# plt.bar(range(len(values)), values)
# plt.xticks(range(len(values)), labels, rotation=30, ha="right")
# plt.title("Cac thanh phan trong Inclusion-Exclusion")
# plt.tight_layout()
# plt.show()

from itertools import combinations 
from math import gcd

def lcm(a, b):
    return a*b//gcd(a,b)

def count_divisible_upto(N, divisors):
    total=0
    for r in range(1, len(divisors)+1):
        for combo in combinations(divisors, r):
            L= combo[0]
            for x in combo[1:]:
                L=lcm(L,x)
            term= N//L 
            total += term if (r%2==1) else -term
    return total
print("<=200 chia het 3 hoac 7 hoac 9: ", count_divisible_upto(200, [3,7,9]))


