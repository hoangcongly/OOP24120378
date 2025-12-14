#include <iostream>
#include "Fraction.h" // Phải có tệp "Fraction.h" của bạn

using namespace std;

int main()
{
    cout << "--- Kiem tra Ham tao (Constructor) va rutgon() ---" << endl;
    Fraction f1;       // Mặc định
    Fraction f2(6, 8); // Tự động rút gọn -> 3/4
    Fraction f3(5);    // Số nguyên
    Fraction f4 = f2;  // Sao chép

    cout << "f1 (mac dinh): " << f1 << endl;
    cout << "f2 (6/8): " << f2 << endl;
    cout << "f3 (5): " << f3 << endl;
    cout << "f4 (sao chep f2): " << f4 << endl;

    cout << "\n--- Kiem tra Phep toan (+, -, *, /) ---" << endl;
    cout << f2 << " + " << f3 << " = " << (f2 + f3) << endl; // 3/4 + 5/1 = 23/4
    cout << f2 << " - " << f3 << " = " << (f2 - f3) << endl; // 3/4 - 5/1 = -17/4
    cout << f2 << " * " << f4 << " = " << (f2 * f4) << endl; // 3/4 * 3/4 = 9/16
    cout << f2 << " / " << f4 << " = " << (f2 / f4) << endl; // 3/4 / 3/4 = 1

    cout << f2 << " + 2 = " << (f2 + 2) << endl; // 3/4 + 2 = 11/4
    cout << f2 << " / 2 = " << (f2 / 2) << endl; // 3/4 / 2 = 3/8

    cout << "\n--- Kiem tra Phep so sanh (>, <, ==) ---" << endl;
    if (f2 > Fraction(1, 2))
        cout << f2 << " > 1/2" << endl;
    if (f3 == 5)
        cout << f3 << " == 5" << endl;
    if (f2 != f3)
        cout << f2 << " != " << f3 << endl;

    cout << "\n--- Kiem tra Phep gan (=, +=, *=) ---" << endl;
    f1 = f3;
    cout << "f1 sau khi f1 = f3: " << f1 << endl;
    f1 += f2;                                       // 5/1 + 3/4
    cout << "f1 sau khi f1 += f2: " << f1 << endl;  // 23/4
    f1 *= Fraction(1, 2);                           // 23/4 * 1/2
    cout << "f1 sau khi f1 *= 1/2: " << f1 << endl; // 23/8

    cout << "\n--- Kiem tra (++, --) ---" << endl;
    cout << "f2 hien tai: " << f2 << endl;      // 3/4
    cout << "++f2 (Prefix): " << ++f2 << endl;  // 7/4
    cout << "f2 sau ++: " << f2 << endl;        // 7/4
    cout << "f2++ (Postfix): " << f2++ << endl; // Vẫn in 7/4
    cout << "f2 sau ++: " << f2 << endl;        // Đã thành 11/4

    cout << "\n--- Kiem tra Xu ly loi ---" << endl;
    cout << "Tao phan so 5/0: ";
    Fraction f_err(5, 0); // Sẽ in ra lỗi
    cout << "Gia tri f_err: " << f_err << endl;
    cout << "Phep chia 3/0: ";
    cout << f3 / f1.Fraction(0, 1) << endl;

    cout << "\n--- Kiem tra Nhap (>>) ---" << endl;
    Fraction f_in;
    cout << "Nhap mot phan so (dang a/b): ";
    cin >> f_in;
    cout << "Ban da nhap: " << f_in << endl;

    cout << "Nhap mot so nguyen: ";
    cin >> f_in;
    cout << "Ban da nhap: " << f_in << endl;

    cout << "Nhap phan so co mau bang 0 (vd 9/0): ";
    cin >> f_in;
    cout << "Ban da nhap: " << f_in << endl;

    return 0;
}