#include "QuanLyThi.h"
#include <iostream>
using namespace std;

int main() {
    // ===== Test GiangVien =====
    GiangVien gv1("GV01", "Nguyen Van A", "CNTT", "0123456789", "a@gmail.com", "P101");
    gv1.hienThi();
    cout << "--------------------------\n";

    // ===== Test CanBoCoiThi =====
    CanBoCoiThi cb1("CB01", "Tran Thi B", "Toan", "0987654321", "b@gmail.com", "P102");
    CanBoCoiThi cb2("CB02", "Le Van C", "Ly", "0912345678", "c@gmail.com", "P103");
    cb1.hienThi();
    cb2.hienThi();
    cout << "--------------------------\n";

    // ===== Test LichThi =====
    vector<CanBoCoiThi> dsCB = {cb1};
    LichThi lt1("L01", "Lap trinh OOP", "2025-06-01", "08:00", "A201", 55, false, gv1, dsCB);
    lt1.themCanBo(cb2);
    lt1.hienThi();
    cout << "--------------------------\n";

    // ===== Test KyThi =====
    KyThi ky1("K2025", "2", 2025, {lt1}, false);
    ky1.hienThi();
    cout << "--------------------------\n";

    // ===== Test KinhPhi =====
    KinhPhi kp1("L01", 50000, 55, 200000, 300000, false);
    kp1.hienThi();
    cout << "--------------------------\n";

    // ===== Test PhanCongCoiThi =====
    PhanCongCoiThi pc;
    pc.themCanBo(cb1);
    pc.themCanBo(cb2);
    pc.hienThi();

    cout << "Xoa CB01..." << endl;
    pc.xoaCanBo("CB01");
    pc.hienThi();

    cout << "Phan cong can bo vao lich thi..." << endl;
    pc.phanCong(lt1, {cb1, cb2});
    lt1.hienThi();

    return 0;
}
