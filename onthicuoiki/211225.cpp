#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
using namespace std;

/* ================= EXCEPTIONS ================= */
class FileNotFoundException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "File not found.";
    }
};

class NullReferenceException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Null reference.";
    }
};

class InvalidDataException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid data format.";
    }
};

/* ================= BASE CLASS ================= */
class MachDien
{
protected:
    string maSo;

public:
    MachDien(string ms = "") : maSo(ms) {}
    virtual ~MachDien() = default;

    string getTen() const { return maSo; }

    virtual double getDienTro() const = 0;
    virtual double getTriGia() const = 0;
    virtual void nhap(istream &is) = 0;
    virtual void xuat(ostream &os) const = 0;
};

ostream &operator<<(ostream &os, const MachDien &md)
{
    md.xuat(os);
    return os;
}

/* ================= MACH DON ================= */
class MachDon : public MachDien
{
private:
    double dienTro{};
    double triGia{};

public:
    MachDon(string ms = "") : MachDien(ms) {}

    double getDienTro() const override { return dienTro; }
    double getTriGia() const override { return triGia; }

    void nhap(istream &is) override
    {
        is >> triGia >> dienTro;
        is.ignore();
        if (dienTro <= 0 || triGia < 0)
            throw InvalidDataException();
    }

    void xuat(ostream &os) const override
    {
        os << "MachDon - " << maSo << "\n";
        os << triGia << " " << dienTro << "\n";
    }
};

/* ================= MACH PHUC ================= */
class MachPhuc : public MachDien
{
protected:
    vector<MachDien *> dsCon; // KHÔNG sở hữu
public:
    MachPhuc(string ms = "") : MachDien(ms) {}
    virtual ~MachPhuc() = default;

    void themMachCon(MachDien *m)
    {
        if (!m)
            throw NullReferenceException();
        dsCon.push_back(m);
    }

    int soMachDon() const
    {
        int cnt = 0;
        for (auto m : dsCon)
            if (dynamic_cast<MachDon *>(m))
                cnt++;
        return cnt;
    }
};

/* ================= NOI TIEP ================= */
class MachNoiTiep : public MachPhuc
{
public:
    MachNoiTiep(string ms = "") : MachPhuc(ms) {}

    double getDienTro() const override
    {
        double sum = 0;
        for (auto m : dsCon)
            sum += m->getDienTro();
        return sum;
    }

    double getTriGia() const override
    {
        double sum = 0;
        for (auto m : dsCon)
            sum += m->getTriGia();
        return sum;
    }

    void nhap(istream &) override {}

    void xuat(ostream &os) const override
    {
        os << "Mach Noi Tiep - " << maSo << "\n";
        os << "Tong tro: " << getDienTro() << "\n";
        os << "Tri gia: " << getTriGia() << "\n";
        for (auto m : dsCon)
            m->xuat(os);
    }
};

/* ================= SONG SONG ================= */
class MachSongSong : public MachPhuc
{
public:
    MachSongSong(string ms = "") : MachPhuc(ms) {}

    double getDienTro() const override
    {
        double sum = 0;
        for (auto m : dsCon)
            sum += 1.0 / m->getDienTro();
        if (sum == 0)
            throw InvalidDataException();
        return 1.0 / sum;
    }

    double getTriGia() const override
    {
        double sum = 0;
        for (auto m : dsCon)
            sum += m->getTriGia();
        return sum * 1.1;
    }

    void nhap(istream &) override {}

    void xuat(ostream &os) const override
    {
        os << "Mach Song Song - " << maSo << "\n";
        os << "Tong tro: " << getDienTro() << "\n";
        os << "Tri gia: " << getTriGia() << "\n";
        os << "So mach don: " << soMachDon() << "\n";
        for (auto m : dsCon)
            m->xuat(os);
    }
};

/* ================= MAIN ================= */
int main()
{
    try
    {
        ifstream fin("data.txt");
        if (!fin)
            throw FileNotFoundException();

        vector<MachDien *> danhSach;

        string loai;
        while (getline(fin, loai))
        {
            if (loai.empty())
                continue;

            if (loai.find("MachDon") != string::npos)
            {
                string ma;
                getline(fin, ma);
                MachDon *md = new MachDon(ma);
                md->nhap(fin);
                danhSach.push_back(md);
            }
        }

        for (auto m : danhSach)
            cout << *m << "\n";

        for (auto m : danhSach)
            delete m;
    }
    catch (exception &e)
    {
        cout << "Loi: " << e.what() << endl;
    }
}
