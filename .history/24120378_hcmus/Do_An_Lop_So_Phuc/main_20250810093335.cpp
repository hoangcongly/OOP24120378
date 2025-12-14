/*
Hãy xây dựng lớp số phức có thể thực hiện các phép toán số học thông qua các toán tử sau: +, -, *, /, ==, !=.
*/

#include "So_Phuc.h"

int main() {
    SoPhuc a, b;
    cout << "Nhap so phuc a:\n";
    cin >> a;
    cout << "Nhap so phuc b:\n";
    cin >> b;

    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";

    cout << "a + b = " << a + b << "\n";
    cout << "a - b = " << a - b << "\n";
    cout << "a * b = " << a * b << "\n";
    cout << "a / b = " << a / b << "\n";

    cout << "a == b ? " << (a == b ? "true" : "false") << "\n";
    cout << "a != b ? " << (a != b ? "true" : "false") << "\n";

    return 0;
}
