#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FSObject
{
protected:
    string name;

public:
    FSObject(const string &n = "")
    {
        name = n;
    }
    virtual ~FSObject() = default;
    virtual long getSize() const = 0;
    virtual string getName() const = 0;
    virtual void print(int indent = 0) = 0;
};

class File : public FSObject
{
private:
    long sizeB;

public:
    File(const string &n = "", const long &s = 0) : FSObject(n)
    {
        sizeB = s;
    }
    long getSize() const override
    {
        return sizeB;
    }
    void print(int indent = 0) override
    {
        cout << string(indent, ' ') << name << " (" << sizeB << " B)" << endl;
    }
};

class Folder : public FSObject
{
protected:
    vector<FSObject *> children;

public:
    Folder(const string &name = "") : FSObject(name) {}
    ~Folder()
    {
        for (auto c : children)
        {
            delete c;
        }
    }
    void add(FSObject *obj)
    {
        children.push_back(obj);
    }
    long getSize() const override
    {
        long total = 0;
        for (auto obj : children)
        {
            total += obj->getSize();
        }
        return total;
    }
    void print(int indent = 0) const
    {
        cout << string(indent, ' ')
             << "[" << name << "]" << endl;

        for (auto obj : children)
            obj->print(indent + 4);
    }
    void count(int &filecount, int &foldercount) const
    {
        foldercount++;
        for (auto c : children)
        {
            if (auto f = dynamic_cast<Folder *>(c))
            {
                f->count(filecount, foldercount);
            }
            else
                filecount++;
        }
    }
    Folder *findFolder(const string &fname)
    {
        if (name == fname)
            return this;
        for (auto c : children)
        {
            if (auto f = dynamic_cast<Folder *>(c))
            {
                Folder *res = f->findFolder(fname);
                if (res)
                    return res;
            }
        }
        return nullptr;
    }
};

int main()
{
    Folder *C = new Folder("C:");

    Folder *baitap = new Folder("Bai tap");
    baitap->add(new File("BT1.doc", 123456));

    Folder *baitapC = new Folder("Bai tap C");
    baitapC->add(new File("BT2.cpp", 1280));
    baitap->add(baitapC);
    baitap->add(new File("BT2.xls", 23456));

    Folder *lythuyet = new Folder("Ly thuyet");
    lythuyet->add(new File("Ch1.ppt", 34567));

    C->add(baitap);
    C->add(lythuyet);

    /* ===== In cây thư mục ===== */
    cout << "CAY THU MUC:\n";
    C->print();

    /* ===== Đếm ===== */
    int files = 0, folders = 0;
    C->count(files, folders);
    cout << "\nSo thu muc: " << folders << endl;
    cout << "So tap tin: " << files << endl;

    /* ===== Tính dung lượng thư mục ===== */
    string fname = "Bai tap";
    Folder *f = C->findFolder(fname);
    if (f)
        cout << "\nDung luong '" << fname << "': "
             << f->getSize() << " B\n";
    else
        cout << "Khong tim thay thu muc\n";

    delete C;
    return 0;
}