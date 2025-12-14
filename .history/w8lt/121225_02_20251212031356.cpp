#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Expr
{
public:
    virtual double evaluate() const = 0;
    virtual string toInfix() const = 0;
    virtual ~Expr() {}
};

class Number : public Expr
{
private:
    double value;

public:
    Number(double x): value(x){}
    double evaluate() const override {return value;}
    string toInfix() const override {return to_string(value);}
};

class Op: public Expr
{
private:
    char op;
    Expr *l, *r;
public:
    Op(char c, Expr*left, Expr*right): op(c), l(left), r(right){}
    ~Op()
    {
        delete l;
        delete r;
    }
    double evaluate() const override
    {
        double a= l->evaluate();
        double b= r->evaluate();
        switch (op)
        {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        default:
            break;
        }
    }
    string toInfix() const override
    {
        return "("+ l->toInfix() + op + r->toInfix() + ")";
    }
};