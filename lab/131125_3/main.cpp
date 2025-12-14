#include "Book.h"
#include "Member.h"

int main()
{
    Book b1("Dac Nhan Tam", "Dale Carnegie", 12345);
    Book b2("Sherlock Holmes", "Doyle", 11111);

    Member m1("Nguyen Van A", "01/01/2000");
    Member m2("Tran Thi B", "02/02/2001");

    m1.MuonSach(&b1);
    m2.MuonSach(&b2);

    m1.inThongTin();
    m2.inThongTin();

    // Test operator=
    m1 = m2;

    cout << "\nSau khi gán m1 = m2:\n";
    m1.inThongTin();

    return 0;
}
