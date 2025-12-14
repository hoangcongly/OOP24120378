#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "Book.h"
using namespace std;

class Member
{
private:
    static int autoid;
    string m_MSThanhVien;
    string m_hoTen;
    string m_NgaySinh;

    vector<Book *> m_DSDaMuon;

public:
    Member(const string &hoten = "", const string &ngaysinh = "");
    Member(const Member &other);
    ~Member();
    bool MuonSach(Book *b);
    bool TraSach(Book *b);
    Member &operator=(const Member &other);
    string getMS() const { return m_MSThanhVien; }
    string getTen() const { return m_hoTen; }
    string getNgaySinh() const { return m_NgaySinh; }

    void inThongTin() const;
};

int Member::autoid = 1;
Member::Member(const string &hoTen, const string &ngaySinh)
    : m_hoTen(hoTen),
      m_NgaySinh(ngaySinh)
{
    m_MSThanhVien = "TV" + std::to_string(autoid++);
}

Member::Member(const Member &other) : m_hoTen(other.m_hoTen), m_NgaySinh(other.m_NgaySinh), m_DSDaMuon(other.m_DSDaMuon)
{
    m_MSThanhVien = "TV" + std::to_string(autoid++);
}

Member::~Member() {}

bool Member::MuonSach(Book *b)
{
    if (b->getTinhTrang())
    {
        b->setTinhTrang(false);
        m_DSDaMuon.push_back(b);
        return true;
    }
    return false;
}

bool Member::TraSach(Book *b)
{
    for (auto it = m_DSDaMuon.begin(); it != m_DSDaMuon.end(); it++)
    {
        if (*it == b)
        {
            m_DSDaMuon.erase(it);
            b->setTinhTrang(true);
            return true;
        }
    }
    return false;
}

Member &Member::operator=(const Member &other)
{
    if (this != &other)
    {
        m_hoTen = other.m_hoTen;
        m_NgaySinh = other.m_NgaySinh;
        m_DSDaMuon = other.m_DSDaMuon;
        m_MSThanhVien = other.m_MSThanhVien;
    }
    return *this;
}

void Member::inThongTin() const
{
    cout << "Thanh vien: " << m_MSThanhVien
         << " | Ten: " << m_hoTen
         << " | Ngay sinh: " << m_NgaySinh
         << " | So sach dang muon: " << m_DSDaMuon.size()
         << endl;
}
