#include "HocSinh.h"

HocSinh::SL_HocSinh = 0;
HocSinh *HocSinh::DS_HocSinh[MAX_HS];
int HocSinh::NextMS = 2312001;

HocSinh::HocSinh()
{
    hoTen = nullptr;
}