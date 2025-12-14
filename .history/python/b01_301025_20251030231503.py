import math
import itertools

def get_prime_factors(n):
    factors= set()
    temp_n = n
    while temp_n%2==0:
        factors.add(2)
        temp_n=temp_n//2
    d=3
    while d*d<=temp_n:
        if temp_n%d==0:
            factors.add(d)
            while temp_n%d==0:
                temp_n=temp_n//d
        d=d+2
    if(temp_n>1):
        factors.add(temp_n)
    return list(factors)

def count_coprime_up_to(x, prime_factors):
    k= len(prime_factors)
    inverse_count=0# so luong so nguyen to KHONG cung nhau voi n
    for subset_size in range(1,k+1):
        all_combos= itertools.combinations(prime_factors, subset_size)
        for combo in all_combos:
            divisor=1
            for factor in combo:
                divisor*=factor
            if(subset_size%2==1):
                inverse_count+=x//divisor
            else: 
                inverse_count-=x//divisor

    return x-inverse_count

def solve(a,b,n):
    if n==1:
        return b-a+1
    prime_factors= get_prime_factors(n)
    count_b= count_coprime_up_to(b, prime_factors)
    count_a= count_coprime_up_to(a-1, prime_factors)

    return count_b-count_a
    