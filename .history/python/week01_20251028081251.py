from sympy import FiniteSet
from math import sqrt
from matplotlib import pyplot as plt

small_set= FiniteSet(1,2)
large_set= FiniteSet(1,2,3,4)
print("small con large: ", small_set.is_subset(large_set))
print("large cha small: ", large_set.is_superset(small_set))
power_set= large_set.powerset()
print("number of subsets: ", len(power_set))
print(power_set)