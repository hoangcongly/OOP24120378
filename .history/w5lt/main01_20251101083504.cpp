#include "b01.h"

int main()
{
    Address a1("123 Xa Lo Ha Noi", "Hanoi", "Vietnam");
    Student s("Nguyen Van B", "24120001", 3.2, a1);
    s.display();

    cout << endl;
    Address a2("45 Vo Nguyen Giap", "Ho Chi Minh", "Viet Nam");
    ExchangeStudent ex("Tran Thi A", "EX001", 3.8, a2, "France", 6);
    ex.display();

    cout << "Cap nhat thoi gian thanh 12 thang:\n";
    ex.updateDuration(12);
    ex.display();

    Student *p = &ex;
    p->display();

    return 0;
}