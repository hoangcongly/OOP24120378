from sympy import FiniteSet
from math import sqrt
from matplotlib import pyplot as plt

small_set= FiniteSet(1,2)
large_set= FiniteSet(1,2,3,4)
print("small con large: ", small_set.is_subset(large_set))
