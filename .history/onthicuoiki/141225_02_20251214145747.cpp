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
        os << "- Chat don: " << ten
           << " | KL=" << kl
           << " | Doc=" << doc
           << " | HoatTinh=" << hoatTinh << endl;
    }
};

class ChatHonHop : public Chat
{
private:
    vector<Chat *> dsCon;

public:
    ChatHonHop(string ten = "") : Chat(ten) {}
    virtual ~ChatHonHop()
    {
        for (auto p : dsCon)
        {
            delete p;
        }
    }
    void themChat(Chat *c)
    {
        if (!c)
            throw NullReferenceException();
        dsCon.push_back(c);
    }
    int demChatDon() const override
    {
        int sum = 0;
        for (auto p : dsCon)
        {
            sum += p->demChatDon();
        }
        return sum;
    }
    void xuat(ostream &os, int level = 0) const override
    {
        for (int i = 0; i < level; ++i)
            os << "  ";
        os << "+ Hon hop: " << ten << endl;
        for (auto p : dsCon)
            p->xuat(os, level + 1);
    }
};

class HonHopPhanung : public ChatHonHop
{
public:
    HonHopPhanung(string ten = "") : ChatHonHop(ten) {}
    double khoiLuong() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->khoiLuong();
        }
        return s;
    }
    double hamLuongDoc() const override
    {
        double mx = 0;
        for (auto p : dsCon)
        {
            mx = max(mx, p->hamLuongDoc());
        }
        return mx;
    }
    double hamLuongHoatTinh() const override
    {
        double tong = 0, kl = 0;
        for (auto p : dsCon)
        {
            tong += p->hamLuongHoatTinh() * p->khoiLuong();
            kl += p->khoiLuong();
        }
        return (kl == 0) ? 0 : tong / kl;
    }
    void nhap(istream &is) override;
};

class HonHopTrungHoa : public ChatHonHop
{
public:
    HonHopTrungHoa(string ten = "") : ChatHonHop(ten) {}
    double khoiLuong() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->khoiLuong();
        }
        return s;
    }
    double hamLuongDoc() const override
    {
        return 0;
    }
    double hamLuongHoatTinh() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->hamLuongHoatTinh();
        }
        return s * 0.8;
    }
    void nhap(istream &is) override;
};

class HonHopXucTac : public ChatHonHop
{
public:
    HonHopXucTac(string ten = "") : ChatHonHop(ten) {}
    double khoiLuong() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->khoiLuong();
        }
        return s;
    }
    double hamLuongDoc() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p.hamLuongDoc();
        }
        return dsCon.empty() ? 0 : s / dsCon.size();
    }
    double hamLuongHoatTinh() const override
    {
        double mx = 0;
        for (auto p : dsCon)
            mx = max(mx, p->hamLuongHoatTinh());
        double kq = mx * 1.5;
        return (kq > 100) ? 100 : kq;
    }
    void nhap(istream&is) override;
};

Chat*taoChatTheoLoai(const string& type)
{
    if(type=="DON") return new ChatDon();
    if(type=="PHANUNG") return new HonHopPhanung();
    if(type=="TRUNGHOA") return new HonHopTrungHoa();
    if(type=="XUCTAC") return new HonHopXucTac();
    throw InvalidDataException();
} 

void HonHopPhanUng::nhap(istream&is)
{
    int n;
    is >> ten >> n;
    if(n<0) throw InvalidDataException();
    for(int i=0; i< n; i++)
    {
        string type;
        is>> type ;
        
    }
}