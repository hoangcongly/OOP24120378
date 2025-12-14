from sympy import FiniteSet
from math import sqrt
from matplotlib import pyplot as plt

number_set= FiniteSet(3,5,7)
print(number_set)
print("cardinality: ", len(number_set))
print("3 in set?: ", 3 in number_set)
print("9 in set?: ", 9 in number_set)