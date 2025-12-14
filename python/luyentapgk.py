import math
import itertools

# B_man=18
# B_ngot=12
# Tong_banh=B_man+B_ngot
# so_banh_can_chon=5
# U_total= math.comb(Tong_banh, so_banh_can_chon)
# total_vipham=0
# dsvipham=["CHIMAN","CHINGOT"]
# for r in range(1,len(dsvipham)+1):
#     for combo in itertools.combinations(dsvipham, r):
#         term=0
#         if r==1:
#             if combo[0]=="CHIMAN":
#                 term=math.comb(B_man, so_banh_can_chon)
#                 total_vipham+=term
#             elif combo[0]=="CHINGOT":
#                 term=math.comb(B_ngot,so_banh_can_chon)
#                 total_vipham+=term
#         elif r==2:
#             term==0
#             total_vipham-=term
# result= U_total-total_vipham
# print(result)

# chieudaiPIN=4
# dsvipham=[{0,1,2,3,4,5}, {6,7,8,9}]
# total_vipham=0
# all_digit=range(0,10)
# U_total=len(all_digit)**chieudaiPIN
# for r in range(1, len(dsvipham)+1):
#     for combo in itertools.combinations(dsvipham,r):
#         intersect= combo[0]
#         for s in combo[1:]:
#             intersect= intersect.intersection(s)
#         term= len(intersect)**chieudaiPIN
#         if r%2==1:
#             total_vipham+=term
#         else:
#             total_vipham-=term
# result= U_total-total_vipham
# print(result)

count=0
for num in range(10000,99999):
    s=str(num)
    if num%2==1:
        if len(s)==len(set(s))+1:
            count+=1
print(count)

    