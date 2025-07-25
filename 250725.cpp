/*
Lớp Book: mã sách, tên, tác giả, năm XB.
Lớp Reader: mã độc giả, họ tên, ngày sinh.
Lớp BorrowCard: mã mượn, ngày mượn, ngày trả, mã sách, mã độc giả.
Yêu cầu:
Nhập/xuất danh sách.
In thẻ mượn quá hạn (so với ngày hiện tại).
Đếm số sách một độc giả đã mượn.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Date{
private:
    int day;
    int month;
    int year;
public:
    bool operator<(const Date&other) const// tra ve true neu ngay date truoc ngay other
    {
        if(year!= other.year) return year< other.year;
        if(month != other.month) return month < other.month;
        return day< other.day;
    }
    static Date parse(const string&s)
    {
        Date d;
        sscanf(s.c_str(), "%d/%d/%d", &d.day,&d.month,&d.year);
        return d;
    }
};
class Book
{
private:
    string bookID;
    string title;
    string author;
    int year;
public:
    void input()
    {
        cout << "Ma sach: ";
        cin >> bookID;
        cin.ignore();
        cout << "Ten sach: ";
        getline(cin, title);
        cout << "Tac gia: ";
        getline(cin, author);
        cout << "Nam xuat ban: ";
        cin >> year;
    }
    void output() const
    {
        cout << "Ma: " << bookID
            << " | Ten: " << title
            << " | Tac gia: " << author
            << " | Nam: " << year << endl;
    }
    string getBookID() const 
    {
        return bookID;
    }
};
class Reader
{
private:
    string readerID;
    string name;
    string birth;
public:
    void input()
    {
        cout << "Ma doc gia: "; cin >> readerID;
        cin.ignore();
        cout << "Ho ten: "; getline(cin, name);
        cout << "Ngay sinh (dd/mm/yyyy): "; getline(cin, birth);
    }
    void output() const
    {
        cout << "Ma: " << readerID
            << " | Ten: " << name
            << " | Ngay sinh: " << birth << endl;
    }
    string getReaderID() const
    {
        return readerID;
    }
};
class borrowCard {
private:
    string cardID;
    string bookID;
    string readerID;
    string borrowDate;
    string returnDate;
public:
    void input()
    {
        cout << "Ma the muon: "; cin >> cardID;
        cout << "Ma sach: "; cin >> bookID;
        cout << "Ma doc gia: "; cin >> readerID;
        cout << "Ngay muon (dd/mm/yyyy): "; cin >> borrowDate;
        cout << "Ngay tra (dd/mm/yyyy): "; cin >> returnDate;
    }
     void output() const {
        cout << "Ma the: " << cardID
             << " | Sach: " << bookID
             << " | Doc gia: " << readerID
             << " | Muon: " << borrowDate
             << " | Tra: " << returnDate << endl;
    }
    bool isOverdue(const string& currentDateStr) const
    {
        Date returnD= Date::parse(returnDate);
        Date today= Date::parse(currentDateStr);
        return returnD<today;
    }
    string getReaderID() const
    {
        return readerID;
    }
    string getReturnDate() const
    {
        return returnDate;
    }
};
// ===== MAIN FUNCTION =====
int main() {
    int nBooks, nReaders, nCards;
    vector<Book> books;
    vector<Reader> readers;
    vector<borrowCard> cards;

    cout << "\nNhap so luong sach: "; cin >> nBooks;
    for (int i = 0; i < nBooks; ++i) {
        cout << "Nhap thong tin sach thu " << i + 1 << ":\n";
        Book b;
        b.input();
        books.push_back(b);
    }

    cout << "\nNhap so luong doc gia: "; cin >> nReaders;
    for (int i = 0; i < nReaders; ++i) {
        cout << "Nhap thong tin doc gia thu " << i + 1 << ":\n";
        Reader r;
        r.input();
        readers.push_back(r);
    }

    cout << "\nNhap so luong the muon: "; cin >> nCards;
    for (int i = 0; i < nCards; ++i) {
        cout << "Nhap thong tin the muon thu " << i + 1 << ":\n";
        borrowCard c;
        c.input();
        cards.push_back(c);
    }

    // --- In danh sach sach ---
    cout << "\n===== DANH SACH SACH =====\n";
    for (const auto& b : books)
        b.output();

    // --- In danh sach doc gia ---
    cout << "\n===== DANH SACH DOC GIA =====\n";
    for (const auto& r : readers)
        r.output();

    // --- In danh sach the muon ---
    cout << "\n===== DANH SACH THE MUON =====\n";
    for (const auto& c : cards)
        c.output();

    // --- Tim the muon qua han ---
    string currentDate = "25/07/2025";
    cout << "\n===== CAC THE MUON QUA HAN (truoc " << currentDate << ") =====\n";
    for (const auto& c : cards)
        if (c.isOverdue(currentDate))
            c.output();

    // --- Dem so sach ma 1 doc gia da muon ---
    string targetReaderID;
    cout << "\nNhap ma doc gia can kiem tra: ";
    cin >> targetReaderID;
    int count = 0;
    for (const auto& c : cards)
        if (c.getReaderID() == targetReaderID)
            ++count;
    cout << "==> Doc gia " << targetReaderID << " da muon " << count << " sach.\n";

    return 0;
}






