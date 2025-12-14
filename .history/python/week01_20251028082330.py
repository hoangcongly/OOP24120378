from sympy import FiniteSet
from math import sqrt
from matplotlib import pyplot as plt

from matplotlib_venn import venn2

odd_number_set = {1,3,5,7,9,11,13,15,17,19}
prime_number_set = {2,3,5,7,11,13,17,19}
venn2([odd_number_set, prime_number_set], set_labels=('Odd Numbers', 'Prime Numbers'))
plt.show()