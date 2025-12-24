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
