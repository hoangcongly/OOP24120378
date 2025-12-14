#include "Polynomial.h"

template <class T>
void Polynomial<T>::nomarlize()
{
    Polynomial<Term<T>> merged;
    for (auto it = _terms.begin(); it != _terms.end(); ++it)
    {
        Term<T> cur = *it;
        if (cur.coef == 0)
            continue;
        bool found = false;
        for (auto jt = merged.begin(); jt != merged.end(); ++jt)
        {
            if (jt->exp == cur.exp)
            {
                jt->coef += cur.coef;
                found = true;
                break;
            }
        }
        if (!found)
        {
            if (merged.empty())
            {
                merged.push_back(cur);
            }
            else
            {
                bool inserted = false;
                for (auto jt = merged.begin(); jt != merged.end(); ++jt)
                {
                    if (cur.exp > jt->exp)
                    {
                        merged.insert(jt, cur);
                        inserted = true;
                        break;
                    }
                }
                if (!inserted)
                {
                    merged.push_back(cur);
                }
            }
        }
    }
    _terms.Clear();
    for (auto jt = merged.begin(); jt != merged.end(); ++jt)
    {
        if (jt->coef != 0)
            _terms.push_back(*jt);
    }
}

Polynomial<T> Polynomial<T>::operator+(const Polynomial<T> &poly)
{
    Polynomial<T> res;
    auto itA = _terms.begin();
    auto itB = poly.terms.begin();
    auto endA = _terms.end();
    auto endB = poly._terms.end();
    while (itA != endA || itB != endB)
    {
    }
}