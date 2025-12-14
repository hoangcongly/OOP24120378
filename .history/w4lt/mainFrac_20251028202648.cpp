#include <iostream>
#include "Fraction.h" // Bao gồm tệp header của bạn

using namespace std;

// Hàm trợ giúp để in kết quả bool (true/false)
void printTest(const char *testName, bool result)
{
    cout << "  " << testName << ": " << (result ? "THANG CONG (Passed)" : "THAT BAI (Failed)") << endl;
}

int main()
{
    cout << "--- KIEM TRA HAM TAO (Constructor) & TOAN TU << ---" << endl;
    Fraction f_default;      // 0/1
    Fraction f_int(5);       // 5/1
    Fraction f_frac(12, 18); // 12/18 -> rut gon -> 2/3
    Fraction f_copy(f_frac); // 2/3
    Fraction f_neg(10, -5);  // 10/-5 -> rut gon -> -2/1
    Fraction f_neg2(-9, -3); // -9/-3 -> rut gon -> 3/1

    cout << "  Mac dinh (0/1): " << f_default << endl;
    cout << "  So nguyen (5): " << f_int << endl;
    cout << "  Phan so (12/18): " << f_frac << endl;
    cout << "  Sao chep (copy f_frac): " << f_copy << endl;
    cout << "  Mau so am (10/-5): " << f_neg << endl;
    cout << "  Ca hai am (-9/-3): " << f_neg2 << endl;

    cout << "\n--- KIEM TRA TOAN TU SO HOC (+, -, *, /) ---" << endl;
    Fraction a(1, 2); // 1/2
    Fraction b(1, 3); // 1/3
    cout << "  Cho a = " << a << ", b = " << b << endl;
    cout << "  a + b = " << (a + b) << " (Mong doi: 5/6)" << endl;
    cout << "  a - b = " << (a - b) << " (Mong doi: 1/6)" << endl;
    cout << "  a * b = " << (a * b) << " (Mong doi: 1/18)" << endl;
    cout << "  a / b = " << (a / b) << " (Mong doi: 3/2)" << endl;

    cout << "\n--- KIEM TRA TOAN TU SO HOC (voi so nguyen) ---" << endl;
    cout << "  a + 2 = " << (a + 2) << " (Mong doi: 5/2)" << endl;
    cout << "  a - 1 = " << (a - 1) << " (Mong doi: -1/2)" << endl;
    cout << "  a * 3 = " << (a * 3) << " (Mong doi: 3/2)" << endl;
    cout << "  a / 2 = " << (a / 2) << " (Mong doi: 1/4)" << endl;

    cout << "\n--- KIEM TRA TOAN TU SO SANH (==, !=, >, <, >=, <=) ---" << endl;
    Fraction c(3, 6); // 3/6 -> rut gon -> 1/2
    cout << "  Cho a = " << a << ", b = " << b << ", c = " << c << endl;
    printTest("a == c (1/2 == 1/2)", a == c);
    printTest("a != b (1/2 != 1/3)", a != b);
    printTest("a > b (1/2 > 1/3)", a > b);
    printTest("b < a (1/3 < 1/2)", b < a);
    printTest("a >= c (1/2 >= 1/2)", a >= c);
    printTest("b <= a (1/3 <= 1/2)", b <= a);

    cout << "\n--- KIEM TRA TOAN TU SO SANH (voi so nguyen) ---" << endl;
    Fraction d(4, 1); // 4/1
    cout << "  Cho d = " << d << endl;
    printTest("d == 4", d == 4);
    printTest("d > 3", d > 3);
    printTest("d < 5", d < 5);
    printTest("d != 5", d != 5);

    cout << "\n--- KIEM TRA TOAN TU GAN (=, +=, *=) ---" << endl;
    Fraction x(1, 1);
    cout << "  x bat dau = " << x << endl;
    x += Fraction(3, 4);
    cout << "  x += 3/4 -> x = " << x << " (Mong doi: 7/4)" << endl;
    x *= Fraction(2, 1);
    cout << "  x *= 2 -> x = " << x << " (Mong doi: 14/4 -> 7/2)" << endl;
    x = Fraction(5, 1);
    cout << "  x = 5 -> x = " << x << " (Mong doi: 5)" << endl;

    cout << "\n--- KIEM TRA TOAN TU TANG/GIAM (++, --) ---" << endl;
    Fraction k(1, 4);
    cout << "  k bat dau = " << k << endl;
    cout << "  ++k (Prefix): " << ++k << " (Mong doi: 5/4)" << endl;
    cout << "  k hien tai = " << k << endl;
    cout << "  k++ (Postfix): " << k++ << " (Mong doi: 5/4)" << endl;
    cout << "  k hien tai = " << k << " (Mong doi: 9/4)" << endl;
    cout << "  --k (Prefix): " << --k << " (Mong doi: 5/4)" << endl;
    cout << "  k-- (Postfix): " << k-- << " (Mong doi: 5/4)" << endl;
    cout << "  k hien tai = " << k << " (Mong doi: 1/4)" << endl;

    cout << "\n--- KIEM TRA XU LY NGOAI LE (LOI) ---" << endl;
    cout << "  1. Tao phan so 5/0: ";
    Fraction err1(5, 0);
    cout << "     Gia tri mac dinh: " << err1 << " (Mong doi: 0/1)" << endl;

    cout << "  2. Chia cho 0 ( (1/2) / 0 ): ";
    Fraction zero(0, 1);
    Fraction err2 = a / zero; // a = 1/2
    cout << "     Gia tri mac dinh: " << err2 << " (Mong doi: 0/1)" << endl;

    cout << "\n--- KIEM TRA TOAN TU NHAP (>>) ---" << endl;
    Fraction f_in;

    cout << "  Nhap mot phan so (vi du: 3/4): ";
    cin >> f_in;
    cout << "  Ban da nhap: " << f_in << endl;

    cout << "  Nhap mot so nguyen (vi du: 8): ";
    cin >> f_in;
    cout << "  Ban da nhap: " << f_in << endl;

    cout << "  Nhap phan so co mau bang 0 (vi du: 9/0): ";
    cin >> f_in;
    cout << "  Ban da nhap: " << f_in << " (Mong doi: 0/1)" << endl;

    return 0;
}