#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FSObject
{
protected:
    string name;

public:
    FSObject(const string &n = "") : name(n) {}
    virtual ~FSObject() = default;

    virtual long getSize() const = 0;
    virtual string getName() const { return name; }
    virtual void print(int indent = 0) const = 0;

    virtual void count(int &filecount, int &foldercount) const = 0;
    virtual FSObject *findFolder(const string &fname) = 0;
};

class File : public FSObject
{
private:
    double sizeB;

public:
    File(const string &n = "", double s = 0) : FSObject(n), sizeB(s) {}

    double getSize() const override
    {
        return sizeB;
    }

    void print(int indent = 0) const override
    {
        cout << string(indent, ' ')
             << name << " (" << sizeB << " B)" << endl;
    }

    void count(int &filecount, int &foldercount) const override
    {
        filecount++;
    }

    FSObject *findFolder(const string &) override
    {
        return nullptr;
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
            delete c;
    }

    void add(FSObject *obj)
    {
        children.push_back(obj);
    }

    double getSize() const override
    {
        double total = 0;
        for (auto obj : children)
            total += obj->getSize();
        return total;
    }

    void print(int indent = 0) const override
    {
        cout << string(indent, ' ')
             << "[" << name << "]" << endl;
        for (auto obj : children)
            obj->print(indent + 4);
    }

    void count(int &filecount, int &foldercount) const override
    {
        foldercount++;
        for (auto c : children)
            c->count(filecount, foldercount);
    }

    FSObject *findFolder(const string &fname) override
    {
        if (name == fname)
            return this;
        for (auto c : children)
        {
            FSObject *res = c->findFolder(fname);
            if (res)
                return res;
        }
        return nullptr;
    }
};

int main()
{
    Folder *C = new Folder("C:");

    Folder *baitap = new Folder("Bai tap");
    baitap->add(new File("BT1.doc", 123.456));

    Folder *baitapC = new Folder("Bai tap C");
    baitapC->add(new File("BT2.cpp", 1.280));
    baitap->add(baitapC);
    baitap->add(new File("BT2.xls", 23.456));

    Folder *lythuyet = new Folder("Ly thuyet");
    lythuyet->add(new File("Ch1.ppt", 34.567));

    C->add(baitap);
    C->add(lythuyet);
    C->print();
    int files = 0, folders = 0;
    C->count(files, folders);
    cout << "\nSo thu muc: " << folders << endl;
    cout << "So tap tin: " << files << endl;

    string fname = "Bai tap";
    FSObject *f = C->findFolder(fname);
    if (f)
        cout << "\nDung luong '" << fname << "': "
             << f->getSize() << " B\n";
    else
        cout << "Khong tim thay thu muc\n";

    delete C;
    return 0;
}