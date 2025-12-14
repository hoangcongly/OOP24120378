import math
import itertools
import matplotlib.pyplot as plt
n=4
items= ['A', 'B', 'C', 'D', 'E']
print("Fomular:", math.factorial(n))
all_perms= list(itertools.permutations(items))
print("Count: ", len(all_perms))