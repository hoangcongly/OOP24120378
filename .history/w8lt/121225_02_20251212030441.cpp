#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Expr
{
public:
    virtual double evaluete() const = 0;
    virtual string toInfix() const = 0;
    virtual ~Expr() {}
};

class Number : public Expr
{
private:
    double value;

public:
};