import math

def KTDK(n):
    if n%2!=0:
        return False
    s= str(n)
    return len(s)==len(set(s))

mang= list()
def cau1(begin, end):
    for i in [begin, end]:
        if KTDK(i)==True:
            mang.add(i)
print(mang.len())


            
