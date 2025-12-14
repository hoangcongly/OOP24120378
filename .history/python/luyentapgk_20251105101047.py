import math
import itertools

B_man=18
B_ngot=12
Tong_banh=B_man+B_ngot
so_banh_can_chon=5
def count_divisible_upto(N, divisors):
    total=0
    for r in range(1, len(divisors)+1):
        for combo in itertools.combinations(divisors,r):
            

    