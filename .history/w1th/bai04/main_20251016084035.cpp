#include "SinhVien.h"

int main()
{
    SinhVien sv1;
    sv1.Xuat();
    SinhVien sv2("1363001");
    sv2.Xuat();
    SinhVien sv3("1363002", "Nguyen Van A", 7, 8.5);
    sv3.Xuat();
    SinhVien sv4("1363003", "Tran Thi B", 8, 9.5, 12, 3, 1996);
    sv4.Xuat();
    NgayThang n(30, 2, 1996);
    SinhVien sv5("1363004", "Ngo Van C", 5, 6, n);
    sv5.Xuat();
    SinhVien sv6(sv5);
    sv6.Xuat();
}