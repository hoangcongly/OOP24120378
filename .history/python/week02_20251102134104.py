import math
import itertools
import matplotlib.pyplot as plt

n=4
items=['A','B','C', 'D']

print("Fomular: ", math.factorial(n))
all_perm= list(itertools.permutations(items))
print("Count: ", len(all_perm))
print("First 5 permutations:", all_perm[:5])