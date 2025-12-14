from sympy import FiniteSet
from math import sqrt
from matplotlib import pyplot as plt

value_set = FiniteSet(1,2,5,7)
cartesian_product= value_set**2
for pair in cartesian_product:
    print(pair)