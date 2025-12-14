import math
import itertools
def prime_number_factor(n):
    list_prime= set()
    temp_n=n
    if(n%2==0):
        list_prime.add(2)
        while n%2==0:
            temp_n=temp_n//2
    d=3
    while(d*d<=temp_n):
        if(temp_n%d==0):
            list_prime.add(d)
            while(temp_n%d==0):
                temp_n=temp_n//d
        d=d+2
    if(temp_n>1):
        list_prime.add(temp_n)
    return list_prime

def count_coprime_upto(x, prime_factors):
    inveser_count=0
    for i in range(1, len(prime_factors)+1):
        all_combos= itertools.combinations(prime_factors,i)
        for combo in all_combos:
            divisor=1
            for j in combo:
                divisor*= j
            if(i%2==1):
                inveser_count+= x//divisor
            else: inveser_count-= x//divisor
    return x- inveser_count

