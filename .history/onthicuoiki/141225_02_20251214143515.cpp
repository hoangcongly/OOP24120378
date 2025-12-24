#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

class FileNotFoundException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "file not found";
    }
};

class NullReferenceException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Null reference";
    }
};

class InvalidDataException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid data format";
    }
};

class LogicException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Logic error";
    }
};

class Chat
{
protected:
    string ten;

public:
    Chat(string ten = "") : ten(ten) {}
    virtual ~Chat() = default;
    string getTen() const { return ten; }
    virtual double khoiLuong() const = 0;
    virtual double hamLuongDoc() const = 0;
    virtual double hamLuongHoatTinh() const = 0;
    virtual int demChatDon() const = 0;
    virtual void nhap(istream &is) = 0;
    virtual void xuat(ostream &os, int level = 0) const = 0;
};

ostream &operator<<(ostream &os, const Chat &c)
{
    c.xuat(os, 0);
    return os;
}

class ChatDon : public Chat
{
private:
    double kl;
    double doc;
    double hoatTinh;

public:
    ChatDon() : kl(0), doc(0), hoatTinh(0) {}
    double khoiLuong() const override { return kl; }
    double hamLuongDoc() const override { return doc; }
    double hamLuongHoatTinh() const override { return hoatTinh; }
    int demChatDon() const override { return 1; }
    void nhap(istream &is) override
    {
        is >> ten >> kl >> doc >> hoatTinh;
        if (is.fail())
            throw InvalidDataException();
        if (doc < 0 || doc > 100 || hoatTinh < 0 || hoatTinh > 100)
            throw LogicException();
    }
    void xuat(ostream &os, int level = 0) const override
    {
        for (int i = 0; i < level; i++)
        {
            os << "\t";
        }
        os << "TEN SON: " << ten << " | Khoi Luong: " << khoiLuong << " | Ham luong doc: " << hamLuongDoc << " | Ham luong hoat tinh: " << hamLuongHoatTinh << endl;
    }
};