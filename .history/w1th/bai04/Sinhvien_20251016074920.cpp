#include "SinhVien.h"

SinhVien:: SinhVien()
{
    const char* default_mssv="xxxxxxx";
    MSSV= new char[strlen(default_mssv)+1];
    strcpy(MSSV, default_mssv);
    const char* default_name
}