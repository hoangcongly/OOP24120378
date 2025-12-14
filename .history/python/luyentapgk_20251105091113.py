import math
import itertools

sotaotoida=6
socamtoida=8
count=0
for tao in range(sotaotoida+1):
    for cam in range(socamtoida+1):
        if tao==0 and cam==0:
            continue
        else:
            count+=1
print(count)