#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee
{
private:
    string maNV;
    string hoTen;
    float hSLuong;
public:
    Employee(string ma, string ten, float hsl)
    {
        maNV= ma;
        hoTen=ten;
        hSLuong= hsl;
    }
    virtual float tinhLuong()=0;
    virtual void hienThi()
    {
        cout << "Ma NV: " << maNV
             << ", Ho ten: " << hoTen
             << ", Luong: " << tinhLuong() << " VND" << endl;
    }
    float getHSLuong() const
    {
        return hSLuong;
    }
    string layTen() 
    {
        return hoTen;
    }
    float layLuong()
    {
        return tinhLuong();
    }
};

class OfficeEmployee: public Employee {
private:
    int soNgayLam;
public:
    OfficeEmployee(string manv, string ten, float hsl,int ngay)
        : Employee(manv, ten, hsl)
        {
            soNgayLam= ngay;
        }
    float tinhLuong() override
    {
        return getHSLuong()*730000+soNgayLam*100000;
    }
};

class ProductionEmployee : public Employee {
private:
    int soSanPham;
public: 
    ProductionEmployee(string ma, string ten, float hsl, int sosp)
        : Employee(ma,ten,hsl)
        {
            soSanPham = sosp;
        }
    float tinhLuong() override
    {
        return soSanPham*50000;
    }
};

int main()
{
    int n;
    vector<Employee*> ds;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string loai,ma,ten;
        float hsl;
        cout << "\n---- Nhan vien thu " << i+1 << " ----\n";
        cout << "Loai (vanphong/sanxuat): ";
        cin >> loai;
        cout << "Ma nhan vien: ";
        cin >> ma;
        cout << "Ho va ten nhan vien: ";
        cin.ignore();
        getline(cin, ten);
        cout << "He so luong: ";
        cin >> hsl;
        if(loai== "vanphong")
        {
            int ngay;
            cout <<"So ngay lam viec: ";
            cin >> ngay;
            ds.push_back(new OfficeEmployee(ma,ten,hsl,ngay));
        }
        else if(loai=="sanxuat")
        {
            int sp;
            cout << "So san pham: ";
            cin >> sp;
            ds.push_back(new ProductionEmployee(ma,ten,hsl,sp));
        }
        else 
        {
            cout << "Loai khong hop le. Bo qua.\n";
        }
    }
    float tongLuong=0;
    for(int i=0; i<ds.size(); i++)
    {
        tongLuong+=ds[i]->tinhLuong();
    }
    cout << "\nTong luong cong ty: " << tongLuong << endl;
    Employee* caonhat=ds[0];
    for(int i=1; i<ds.size(); i++)
    {
        if(ds[i]->layLuong()>caonhat->layLuong())
        {
            caonhat= ds[i];
        }
    }
    cout << "Nhan vien co luong cao nhat la: ";
    caonhat->hienThi();
    for(int i=0; i< ds.size()-1; i++)
    {
        for(int j=i+1; j<ds.size(); j++)
        {
            if(ds[j]->layLuong()>ds[i]->layLuong())
            swap(ds[i],ds[j]);
        }
    }
    for(int i=0; i<ds.size(); i++)
    {
        ds[i]->hienThi();
    }
    for(int i=0; i<ds.size(); i++)
    {
        delete ds[i];
    }
    return 0;
}