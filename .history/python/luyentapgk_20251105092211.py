import math
import itertools

LoaiKem=["Kem Dua", "Kem1", "Kem2", "Kem3", "Kem4", "Kem5", "Kem6", "Kem7", "Kem8", "Kem9"]
n=len(LoaiKem)
k=3
resultall=[]
def muakem(start_idx, current):
    if len(current)==k:
        final=",".join(current)
        resultall.append(final)
        return
    for i in range(start_idx, n):
        current.append(LoaiKem[i])
        muakem(i+1, current)
        current.pop()
muakem(0,[])
cokemdua=0
for kem in resultall:
    if "Kem Dua" in kem:
        cokemdua+=1
print(cokemdua)
    