#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include "SLList.h"

template <class T>
struct Term
{
    T coef;  // he so
    int exp; // so mu
    Term() : coef(0), exp(0) {}
    Term(const T &c, int e) : coef(c), exp(e) {}
};

template <class T = long long>
class Polynomial
{
private:
    SLList<Term<T>> _terms;
    void nomarlize();

public:
    Polynomial();
    Polynomial(const T &coef, int exp = 0);
    Polynomial(const SLList<Term<T>> &terms);
    Polynomial(const Polynomial<T> &other);
    Polynomial<T> &operator=(const Polynomial<T> &other);
    ~Polynomial();

    Polynomial<T> operator+(const Polynomial<T> &poly);
    Polynomial<T> operator-(const Polynomial<T> &poly);
    Polynomial<T> operator*(const Polynomial<T> &poly);
    Polynomial<T> operator/(const Polynomial<T> &poly);
    Polynomial<T> operator%(const Polynomial<T> &poly);

    bool operator==(const Polynomial<T> &poly) const;
    bool operator!=(const Polynomial<T> &poly) const;

    int degree() const;
    Polynomial<T> derivative() const; // dao ham
    T evaluate(const T &x) const;

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Polynomial<U> &p);

    template <class U>
    friend std::istream &operator>>(std::istream &is, Polynomial<U> &p);

    template <class U>
    friend bool readFromFileExpr(const char *filename, Polynomial<U> &p);
};
