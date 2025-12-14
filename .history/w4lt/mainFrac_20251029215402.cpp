#include "Fraction.h"

using namespace std;

int main()
{
    cout << "Kiem tra Constructor & Output (<<)" << endl;
    Fraction<int> f1;
    Fraction<int> f2(5);
    Fraction<int> f3(22, 7);
    Fraction<int> f4(10, 2);

    cout << "f1 (mac dinh): " << f1 << endl;
    cout << "f2 (tu so 5): " << f2 << endl;
    cout << "f3 (22/7): " << f3 << endl;
    cout << "f4 (10/2 rut gon): " << f4 << endl;

    cout << "\nKiem tra typecasting(int) va (float) " << endl;
    cout << "f3 (22/7) la: " << f3 << endl;

    int i_val = f3;
    float f_val = f3;

    cout << "(int) cua f3: " << i_val << endl;
    cout << "(float) cua f3: " << f_val << endl;

    Fraction<int> f_half(1, 2);
    cout << "\nf_half (1/2) la: " << f_half << endl;
    cout << "(int) cua f_half: " << (int)f_half << endl;
    cout << "(float) cua f_half: " << (float)f_half << endl;

    cout << "\nKiem tra Phep toan (+, -, *, /)" << endl;
    Fraction<int> a(1, 2);
    Fraction<int> b(1, 3);

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;
    cout << "a + 1 = " << (a + 1) << endl;

    cout << "\n--- 4. Kiem tra So sanh (>, ==, !=, <=) ---" << endl;
    cout << "a > b (1/2 > 1/3): " << boolalpha << (a > b) << endl;
    cout << "a < b (1/2 < 1/3): " << (a < b) << endl;
    cout << "f2 == f4 (5 == 5): " << (f2 == f4) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a <= (1/2): " << (a <= Fraction<int>(1, 2)) << endl;

    cout << "\nKiem tra Toan tu Gan (=, +=, *=)" << endl;
    Fraction<int> c;
    c = a;
    cout << "c = a: " << c << endl;
    c += b;
    cout << "c += b (1/3): " << c << endl;
    c *= f2;
    cout << "c *= f2 (5): " << c << endl;

    cout << "\n Kiem tra(++, --)" << endl;
    cout << "c hien tai: " << c << endl;
    cout << "++c (tien to): " << (++c) << endl;
    cout << "c hien tai: " << c << endl;
    cout << "c++ (hau to): " << (c++) << endl;
    cout << "c hien tai: " << c << endl;
    cout << "--c (tien to): " << (--c) << endl;

    cout << "\nKiem tra Input (>>)" << endl;
    Fraction<int> f_in;
    cout << "Vui long nhap mot phan so: ";
    cin >> f_in;
    cout << "Ban da nhap: " << f_in << endl;

    cout << "Tao phan so 5/0:" << endl;
    Fraction<int> f_err(5, 0);
    cout << "Gia tri cua f_err: " << f_err << endl;

    cout << "\nLay a / 0:" << endl;
    Fraction<int> f_res = a / f1;
    cout << "Ket qua a / 0: " << f_res << endl;

    return 0;
}