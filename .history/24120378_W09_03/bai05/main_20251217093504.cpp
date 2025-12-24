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
};

class Disk
{
private:
    string name;

public:
    Disk(const string &n = "", long cap)
    {
        name = n;
    }
    Disk::~Disk() {}
};