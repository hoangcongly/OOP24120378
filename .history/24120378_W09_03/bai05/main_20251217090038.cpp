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
    virtual void print(int indent) = 0;
};