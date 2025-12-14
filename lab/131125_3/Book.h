#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
private:
    static int autoID;
    string m_maSo;
    string m_tuaSach;
    string m_tacGia;
    int m_ISBN;
    string m_theLoai;
    bool tinhTrang;

public:
    Book(const string &tuasach,
         const string &tacgia,
         int ISBN,
         const string &theloai = "",
         bool tinhTrang = true);
    Book(const string &maSo,
         const string &tuaSach,
         const string &tacGia,
         int ISBN,
         const string &theLoai,
         bool tinhTrang);
    Book(const Book &other);
    ~Book();

    string getMaSo() const;
    string getTuaSach() const;
    string getTacGia() const;
    int getISBN() const;
    string getTheLoai() const;
    bool getTinhTrang() const;

    void setTinhTrang(bool tt);
    void printInfo() const;
};

int Book::autoID = 1;
Book ::Book(const string &tuasach,
            const string &tacgia,
            int ISBN,
            const string &theloai,
            bool tinhtrang) : m_tuaSach(tuasach), m_tacGia(tacgia), m_ISBN(ISBN), m_theLoai(theloai), tinhTrang(tinhtrang)
{
    m_maSo = "Book" + std::to_string(autoID++);
}
Book::Book(const string &maSo,
           const string &tuaSach,
           const string &tacGia,
           int ISBN,
           const string &theLoai,
           bool tinhTrang) : m_maSo(maSo), m_tuaSach(tuaSach), m_tacGia(tacGia), m_ISBN(ISBN), m_theLoai(theLoai), tinhTrang(tinhTrang)
{
    autoID++;
}
Book::Book(const Book &other)
    : m_tuaSach(other.m_tuaSach), m_tacGia(other.m_tacGia), m_ISBN(other.m_ISBN), m_theLoai(other.m_theLoai), tinhTrang(other.tinhTrang)
{
    m_maSo = "Book" + std::to_string(autoID++);
}
Book::~Book() {}

string Book::getMaSo() const { return m_maSo; }
string Book::getTuaSach() const { return m_tuaSach; }
string Book::getTacGia() const { return m_tacGia; }
int Book::getISBN() const { return m_ISBN; }
string Book::getTheLoai() const { return m_theLoai; }
bool Book::getTinhTrang() const { return tinhTrang; }
void Book::setTinhTrang(bool tt) { tinhTrang = tt; }
void Book::printInfo() const
{
    cout << "Ma so: " << m_maSo
         << " | Tua sach: " << m_tuaSach
         << " | Tac gia: " << m_tacGia
         << " | ISBN: " << m_ISBN
         << " | The loai: " << m_theLoai
         << " | Tinh trang: " << (tinhTrang ? "Con trong thu vien" : "Dang duoc muon")
         << endl;
}
