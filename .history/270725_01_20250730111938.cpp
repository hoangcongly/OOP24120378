/*
📚 Bài tập: Quản lý thư viện sách
🎯 Mô tả bài toán:
Bạn cần xây dựng hệ thống quản lý thư viện với các loại sách khác nhau:

1. class Book (trừu tượng):
Thuộc tính chung:

maSach, tenSach, tacGia, giaTien

Phương thức ảo:

virtual void hienThi()

virtual float tinhGia() → có thể thay đổi cách tính theo từng loại

virtual string loaiSach() → trả về "Giáo khoa", "Tham khảo", "Truyện"

2. Các lớp kế thừa:
class Textbook (Sách giáo khoa)
Thuộc tính: monHoc, capLop

Giá tính: giaTien × 0.9 nếu thuộc lớp dưới 6

class ReferenceBook (Sách tham khảo)
Thuộc tính: linhVuc, soTrang

Giá: giaTien + soTrang × 500

class Novel (Truyện)
Thuộc tính: theLoai, namXuatBan

Nếu xuất bản sau năm 2020, giảm 10% giá
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
protected:
    string maSach;
    string tenSach;
    string tacGia;
    double giaTien;
public:
    Book(string ma, string tens, string tg, double gia)
    {
        maSach=ma;
        tenSach=tens;
        tacGia=tg;
        giaTien=gia;
    }
    virtual double tinhGia()=0;
    virtual void hienThi() {
        cout << "Ma sach: " << maSach
             << ", Tieu de: " << tenSach
             << ", Tac gia: " << tacGia
             << ", Gia: " << tinhGia() << " VND\n";
    }
    virtual string loaiSach()=0;
    double layGia()  
    {
        return tinhGia();
    }
    string layTheLoai()
    {
        return loaiSach();
    }
    virtual ~Book(){} 
};

class TextBook : public Book {
private: 
    string monHoc;
    int capLop;
public:
    TextBook(string ma, string tens, string tg, double gia, string mon, int cap)
    : Book(ma,tens,tg,gia)
    {
        monHoc=mon;
        capLop=cap;
    }
    double tinhGia() override 
    {
        if(capLop<6) 
        {
            return giaTien*0.9;
        }
    return giaTien;
    }
    string loaiSach() override
    {
        return "Sach giao khoa";
    }
};

class ReferenceBook: public Book {
private: 
    string linhVuc;
    double soTrang;
public:
    ReferenceBook(string ma, string tens, string tg, double gia, string linhvuc, double sotr)
    : Book(ma, tens,tg,gia)
    {
        linhVuc=linhvuc;
        soTrang=sotr;
    }
    double tinhGia() override
    {
        return giaTien+soTrang*500;
    }
    string loaiSach() override
    {
        return "Sach tham khao";
    }
};

class Novel: public Book {
private:
    string theLoai;
    int namXB;
public:
    Novel(string ma, string tens, string tg, double gia, string tl, int namxb)
    : Book(ma, tens, tg, gia)
    {
        theLoai= tl;
        namXB=namxb;
    }
    double tinhGia() override
    {
        if(namXB>2020)
        {
            return giaTien-giaTien*0.1;
        }
        return giaTien;
    }
    string loaiSach() override
    {
        return "Sach tham khao";
    }
};

int main()
{
    vector<Book*> thuVien;
    thuVien.push_back(new TextBook("T01", "Toan 5", "Nguyen Van A", 45000, "Toan", 5));
    thuVien.push_back(new ReferenceBook("R01", "Cong nghe AI", "Le Van B", 120000, "CNTT", 200));
    thuVien.push_back(new Novel("N01", "Vu tru song song", "Pham Thi C", 85000, "Khoa hoc vien tuong", 2023));

    double tongGia=0;
    for(auto b: thuVien)
    {
        tongGia+= b->layGia();
    }
    cout << "\nTong gia tri thu vien: " << tongGia << " VND\n";
    Book *maxBook = thuVien[0];
    for(auto b: thuVien)
    {
        
    }
}