#include "Polynomial.h"
#include <stdexcept>

template <class T>
void Polynomial<T>::nomarlize()
{
    SLList<Term<T>> merged;
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

template <class T>
Polynomial<T>::Polynomial() {}

template <class T>
Polynomial<T>::Polynomial(const T &coef, int exp)
{
    if (coef != 0)
    {
        Term<T> t(coef, exp);
        _terms.push_back(t);
    }
    nomarlize();
}

template <class T>
Polynomial<T>::Polynomial(const SLList<Term<T>> &terms)
    : _terms(terms)
{
    nomarlize();
}

template <class T>
Polynomial<T>::Polynomial(const Polynomial<T> &other)
    : _terms(other._terms) {}

template <class T>
Polynomial<T> &Polynomial<T>::operator=(const Polynomial<T> &other)
{
    if (this != &other)
    {
        _terms = other._terms;
    }
    return *this;
}

template <class T>
Polynomial<T>::~Polynomial() {}

template <class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T> &poly)
{
    Polynomial<T> res;
    SLList<Term<T>> &rt = res._terms;
    auto itA = _terms.begin();
    auto itB = poly._terms.begin();
    auto endA = _terms.end();
    auto endB = poly._terms.end();

    while (itA != endA || itB != endB)
    {
        if (itA == endA)
        {
            rt.push_back(*itB);
            ++itB;
        }
        else if (itB == endB)
        {
            rt.push_back(*itA);
            ++itA;
        }
        else
        {
            if (itA->exp > itB->exp)
            {
                rt.push_back(*itA);
                ++itA;
            }
            else if (itA->exp < itB->exp)
            {
                rt.push_back(*itB);
                ++itB;
            }
            else
            {
                Term<T> t(itA->coef + itB->coef, itA->exp);
                rt.push_back(t);
                ++itA;
                ++itB;
            }
        }
    }
    res.nomarlize();
    return res;
}

template <class T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial<T> &poly)
{
    Polynomial<T> negB;
    for (auto it = poly._terms.begin(); it != poly._terms.end(); ++it)
    {
        Term<T> t(-it->coef, it->exp);
        negB._terms.push_back(t);
    }
    return *this + negB;
}

template <class T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T> &poly)
{
    Polynomial<T> res;
    for (auto it = _terms.begin(); it != _terms.end(); ++it)
    {
        for (auto jt = poly._terms.begin(); jt != poly._terms.end(); ++jt)
        {
            Term<T> t(it->coef * jt->coef, it->exp + jt->exp);
            res._terms.push_back(t);
        }
    }
    res.nomarlize();
    return res;
}

template <class T>
Polynomial<T> Polynomial<T>::operator/(const Polynomial<T> &poly)
{
    if (poly._terms.empty())
    {
        throw std::runtime_error("Polynomial division by zero");
    }
    Polynomial<T> R = *this;
    Polynomial<T> Q;
    while (!R._terms.empty() && R.degree() >= poly.degree())
    {
        Term<T> leadR = R._terms.front();
        Term<T> leadB = poly._terms.front();

        T coefQ = leadR.coef / leadB.coef;
        int expQ = leadR.exp - leadB.exp;

        Polynomial<T> Tpoly(coefQ, expQ); // T(x) = coefQ * x^expQ

        Q = Q + Tpoly;
        R = R - Tpoly * poly;
    }

    Q.nomarlize();
    return Q;
}

template <class T>
Polynomial<T> Polynomial<T>::operator%(const Polynomial<T> &poly)
{
    if (poly._terms.empty())
        throw std::runtime_error("Polynomial mod by zero");
    Polynomial<T> Q = *this / poly;
    Polynomial<T> R = (*this) - Q * poly;
    R.nomarlize();
    return R;
}

template <class T>
bool Polynomial<T>::operator==(const Polynomial<T> &poly) const
{
    if (_terms.size() != poly._terms.size())
    {
        return false;
    }
    int n = _terms.size();
    for (int i = 0; i < n; i++)
    {
        if (_terms[i].exp != poly._terms[i].exp)
            return false;
        if (_terms[i].coef != poly._terms[i].coef)
            return false;
    }
    return true;
}

template <class T>
bool Polynomial<T>::operator!=(const Polynomial<T> &poly) const
{
    return !(*this == poly);
}

template <class T>
int Polynomial<T>::degree() const
{
    if (_terms.empty())
    {
        return -1;
    }
    return _terms.front().exp;
}

template <class T>
Polynomial<T> Polynomial<T>::derivative() const
{
    Polynomial<T> res;

    for (auto it = _terms.begin(); it != _terms.end(); ++it)
    {
        if (it->exp > 0)
        {
            Term<T> t(it->coef * (T)it->exp, it->exp - 1);
            res._terms.push_back(t);
        }
    }

    res.nomarlize();
    return res;
}

template <class T>
T Polynomial<T>::evaluate(const T &x) const
{
    T result = 0;
    for (auto it = _terms.begin(); it != _terms.end(); ++it)
    {
        T power = 1;
        for (int i = 0; i < it->exp; ++i)
            power = power * x;
        result = result + it->coef * power;
    }
    return result;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Polynomial<T> &p)
{
    if (p._terms.empty())
    {
        os << "0";
        return os;
    }

    bool first = true;

    for (auto it = p._terms.begin(); it != p._terms.end(); ++it)
    {
        T c = it->coef;
        int e = it->exp;

        if (c == 0)
            continue;
        if (first)
        {
            if (c < 0)
                os << "-";
            first = false;
        }
        else
        {
            if (c < 0)
                os << "-";
            else
                os << "+";
        }
        T absC = (c < 0 ? -c : c);
        if (e == 0)
        {
            os << absC;
        }
        else
        {
            if (absC != 1)
                os << absC;
            os << "x";
            if (e != 1)
            {
                os << "^";
                os << e;
            }
        }
    }
    return os;
}

template <class T>
std::istream &operator>>(std::istream &is, Polynomial<T> &p)
{
    int n;
    is >> n;
    if (!is)
    {
        return is;
    }
    p._terms.Clear();
    for (int i = 0; i < n; i++)
    {
        T c;
        int e;
        is >> c >> e;
        Term<T> t(c, e);
        p._terms.push_back(t);
    }
    p.nomarlize();
    return is;
}

// Đọc P từ file có 1 dòng biểu thức hoàn chỉnh, VD:
//   3x^4 - 2x + 5
//   -x^3+7x-1
// KHÔNG dùng <string>
template <class T>
bool readFromFileExpr(const char *filename, Polynomial<T> &p)
{
    FILE *f = std::fopen(filename, "r");
    if (!f)
        return false;

    char line[1024];
    if (!std::fgets(line, sizeof(line), f))
    {
        std::fclose(f);
        return false;
    }
    std::fclose(f);

    // Xóa đa thức cũ
    p._terms.Clear();

    int i = 0;

    // Hàm nhỏ để skip khoảng trắng
    auto skipSpaces = [&](void)
    {
        while (line[i] != '\0' && std::isspace((unsigned char)line[i]))
            ++i;
    };

    // Hàm đọc một số nguyên (dấu đã xử lý bên ngoài)
    auto readInt = [&](long long &val) -> bool
    {
        bool hasDigit = false;
        val = 0;
        while (line[i] >= '0' && line[i] <= '9')
        {
            hasDigit = true;
            val = val * 10 + (line[i] - '0');
            ++i;
        }
        return hasDigit;
    };

    while (true)
    {
        skipSpaces();
        if (line[i] == '\0' || line[i] == '\n')
            break;

        // 1) Dấu +/-
        int sign = +1;
        if (line[i] == '+')
        {
            sign = +1;
            ++i;
        }
        else if (line[i] == '-')
        {
            sign = -1;
            ++i;
        }

        skipSpaces();

        // 2) Đọc hệ số (nếu có)
        long long coefAbs = 0;
        bool hasCoefDigits = false;

        if (line[i] >= '0' && line[i] <= '9')
        {
            hasCoefDigits = readInt(coefAbs);
        }

        // 3) Kiểm tra có 'x' không
        bool hasX = false;
        int exp = 0;

        skipSpaces();

        if (line[i] == 'x' || line[i] == 'X')
        {
            hasX = true;
            ++i;
            exp = 1; // mặc định

            // nếu không có phần số nào trước đó, nghĩa là hệ số 1
            if (!hasCoefDigits)
                coefAbs = 1;

            skipSpaces();

            if (line[i] == '^')
            {
                ++i;
                skipSpaces();
                long long expLL = 0;
                bool ok = readInt(expLL);
                if (!ok) // không đọc được số mũ
                {
                    return false;
                }
                exp = (int)expLL;
            }
        }
        else
        {
            // không có x -> đây là hằng số, exp = 0
            if (!hasCoefDigits)
            {
                // Không có gì để đọc (ví dụ gặp ký tự lạ), coi là lỗi cú pháp
                return false;
            }
            exp = 0;
        }

        long long finalCoef = sign * coefAbs;

        // Nếu hệ số != 0 thì thêm term
        if (finalCoef != 0)
        {
            Term<T> t((T)finalCoef, exp);
            p._terms.push_back(t);
        }

        skipSpaces();
        // vòng while sẽ tiếp tục xử lý các term tiếp theo cho đến hết dòng
    }

    p.nomarlize();
    return true;
}

template class Polynomial<long long>;
template struct Term<long long>;