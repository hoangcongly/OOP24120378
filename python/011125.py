import math

def KTDK(n):
    if n%2!=0:
        return False
    s= str(n)
    return len(s)==len(set(s))

mang= list()
def cau1(begin, end):
    for i in range(begin, end+1):
        if KTDK(i)==True:
            mang.append(i)

cau1(100,999)
print(len(mang))
print(mang)

            
