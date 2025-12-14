from sympy import FiniteSet
from math import sqrt
from matplotlib import pyplot as plt

all_numbers= FiniteSet(*range(10))
prime_numbers= FiniteSet(2,3,5,7)
odd_numbers= FiniteSet(1,3,5,7,9)
odd_primes= prime_numbers.intersect(odd_numbers)
probability= len(odd_primes)/len(all_numbers)
print("Odd primes: ", odd_primes)
print("probability: ", probability)