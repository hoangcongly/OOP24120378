import math
import itertools

B_man=18
B_ngot=12
Tong_banh=B_man+B_ngot
so_banh_can_chon=5
cacloaibanhman=[f'Mặn {i+1}' for i in range(B_man)]
cacloaibanhngot=[f'Ngọt {i+1}' for i in range(B_ngot)]
cacloaibanh= cacloaibanhman+cacloaibanhngot
count=[0]
def muabanh(start_idx, current):
    if len(current)==so_banh_can_chon:
        coman=False
        congot=False
        for banh in current:
            if banh.startswith('Mặn'):
                coman=True
            elif banh.startswith('Ngọt'):
                congot=True
            if coman and congot:
                break
        if coman and congot:
            count[0]+=1
        return
    for i in range(start_idx, Tong_banh):
        current.append(cacloaibanh[i])
        muabanh(i+1, current)
        current.pop()
muabanh(0, [])
print(count[0])

    