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
    virtual void print() = 0;
};

class File : public FSObject
{
private:
    long sizeKB;

public:
    File(const string &n = "", const long &s = 0) : FSObject(n)
    {
        sizeKB = s;
    }
    long getSize() const override
    {
        return sizeKB;
    }
    void print() override
    {
        cout << "[" << name << "]" << endl;
    }
};