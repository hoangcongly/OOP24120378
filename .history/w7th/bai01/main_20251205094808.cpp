#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

class NhanVien
{
protected:
    char hoTen[100];
    char diaChi[100];

public:
    NhanVien()
    {
        hoTen[0] = '\0';
        diaChi[0] = '\0';
    }
    virtual ~NhanVien() {}
    virtual bool laXuatSac() const = 0;
    virtual void xuat(ostream &os) const = 0;
    friend ostream &operator<<(ostream &os, const NhanVien &nv)
    {
        nv.xuat(os);
        return os;
    }
};

class NhanVienThuKy : public NhanVien
{
private:
    char chungChiNgoaiNgu[100];
    int soBaoCao;

public:
    NhanVienThuKy() : soBaoCao(0)
    {
        chungChiNgoaiNgu[0] = '\0';
    }

    bool laXuatSac() const override
    {
        return soBaoCao >= 12;
    }

    void xuat(ostream &os) const override
    {
        os << "Thu ky: " << hoTen
           << " (" << diaChi << ") "
           << "[" << chungChiNgoaiNgu << "] "
           << "<" << soBaoCao << ">";
    }

    friend istream &operator>>(istream &is, NhanVienThuKy &nv)
    {
        char line[256];
        is.getline(line, 256);
        char *s = line;
        while (*s == ' ')
            s++;

        sscanf_s(s,
                 " %[^(] (%[^)]) [%[^]] ] <%d>",
                 nv.hoTen, (unsigned)100,
                 nv.diaChi, (unsigned)100,
                 nv.chungChiNgoaiNgu, (unsigned)100,
                 &nv.soBaoCao);

        return is;
    }
};

class NhanVienKyThuat : public NhanVien
{
private:
    char chungChiNganh[100];
    int soSangKien;

public:
    NhanVienKyThuat() : soSangKien(0)
    {
        chungChiNganh[0] = '\0';
    }

    bool laXuatSac() const override
    {
        return soSangKien >= 6;
    }

    void xuat(ostream &os) const override
    {
        os << "Ky thuat: " << hoTen
           << " (" << diaChi << ") "
           << "[" << chungChiNganh << "] "
           << "<" << soSangKien << ">";
    }

    friend istream &operator>>(istream &is, NhanVienKyThuat &nv)
    {
        char line[256];
        is.getline(line, 256);
        char *s = line;
        while (*s == ' ')
            s++;
        sscanf_s(s,
                 " %[^(] (%[^)]) [%[^]] ] <%d>",
                 nv.hoTen, (unsigned)100,
                 nv.diaChi, (unsigned)100,
                 nv.chungChiNganh, (unsigned)100,
                 &nv.soSangKien);

        return is;
    }
};

class CongTy
{
private:
    NhanVien *ds[100];
    int n;

public:
    CongTy() : n(0) {}
    ~CongTy()
    {
        for (int i = 0; i < n; i++)
        {
            delete ds[i];
        }
    }

    void docFile(const char *filename)
    {
        ifstream fin(filename);
        char line[256];
        if (!fin)
        {
            cout << "khong mo duoc file " << filename << endl;
            return;
        }
        char tag[16];
        while (fin >> tag)
        {
            if (strncmp(tag, "nvtk:", 5) == 0)
            {
                NhanVienThuKy *p = new NhanVienThuKy;
                fin >> *p;
                ds[n++] = p;
            }
            else if (strncmp(tag, "nvkt:", 5) == 0)
            {
                NhanVienKyThuat *p = new NhanVienKyThuat;
                fin >> *p;
                ds[n++] = p;
            }
            else
            {
                fin.ignore(1000, '\n');
            }
        }
    }

    void xuatTatCa() const
    {
        for (int i = 0; i < n; i++)
            cout << *ds[i] << endl;
    }

    void xuatNhanVienXuatSac() const
    {
        for (int i = 0; i < n; i++)
            if (ds[i]->laXuatSac())
                cout << *ds[i] << endl;
    }
};

int main()
{
    CongTy ct;

    ct.docFile("input.txt");
    cout << "===== DANH SACH NHAN VIEN =====\n";
    ct.xuatTatCa();
    return 0;
}
