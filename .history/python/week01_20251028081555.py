from sympy import FiniteSet
from math import sqrt
from matplotlib import pyplot as plt

set_a= FiniteSet(1,2,3)
set_b= FiniteSet(3,4,5,6)
print("union: ", set_a.union(set_b))
print("Intersection: ", set_a.intersect(set_b))