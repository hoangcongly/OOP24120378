from sympy import FiniteSet
from math import sqrt
from matplotlib import pyplot as plt

roots_set={x for x in range(-50,50) if x**2+x-6==0}
expected_roots= {-3,2}
print ("roots_set: ", roots_set)
print ("Equal to expected_roots?: ", roots_set==expected_roots)