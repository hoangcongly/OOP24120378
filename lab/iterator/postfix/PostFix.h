#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
#include "SLList.h"

template <class T>
class MyStack
{
private:
    SLList<T> _data;

public:
    MyStack() = default;
    bool empty() const
    {
        return _data.size() == 0;
    }
    int size() const
    {
        return _data.size();
    }
    void push(const T &value)
    {
        _data.push_back(value);
    }
    void pop()
    {
        if (empty())
        {
            throw std::out_of_range("MyStack: pop on empty stack");
        }
        _data.RemoveTail(); 
    }
    T &top()
    {
        if (empty())
        {
            throw std::out_of_range("MyStack: pop on empty stack");
        }
        return _data.back();
    }
    const T &top() const
    {
        if (empty())
        {
            throw std::out_of_range("MyStack: pop on empty stack");
        }
        return _data.back();
    }
};

template <class T>
class MyQueue
{
private:
    SLList<T> _data;

public:
    MyQueue() = default;
    bool empty() const
    {
        return _data.size() == 0;
    }
    int size() const
    {
        return _data.size();
    }
    void push(const T &value)
    {
        _data.push_back(value);
    }
    void pop()
    {
        if (empty())
        {
            throw std::out_of_range("MyQueue: pop on empty queue");
        }
        _data.RemoveHead();
    }
    T &front()
    {
        if (empty())
        {
            throw std::out_of_range("MyQueue: pop on empty queue");
        }
        return _data.front();
    }
    const T &front() const
    {
        if (empty())
        {
            throw std::out_of_range("MyQueue: pop on empty queue");
        }
        return _data.front();
    }
    T &back()
    {
        if (empty())
            throw std::out_of_range("MyQueue::back on empty queue");
        return _data.back();
    }

    const T &back() const
    {
        if (empty())
            throw std::out_of_range("MyQueue::back on empty queue");
        return _data.back();
    }
};

struct Token
{
    char kind;
    long long value;
    char op;
    Token()
    {
        kind = 'N'; // 'N', 'O', '(', ')'
        value = 0;  // neu kind= 'N'
        op = 0;     // neu kind='O'
    }
};

int precedent(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

bool isDigitChar(char c)
{
    return c >= '0' && c <= '9';
}

bool tokenize(const std::string &s, SLList<Token> &tokens)
{
    int n = (int)s.size();
    int i = 0;
    while (i < n)
    {
        char c = s[i];
        if (c == ' ')
        {
            i++;
            continue;
        }
        if (isDigitChar(c))
        {
            long long val = 0;
            while (i < n && isDigitChar(s[i]))
            {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            Token t;
            t.kind = 'N';
            t.value = val;
            tokens.push_back(t);
            continue;
        }
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            Token t;
            t.kind = 'O';
            t.op = c;
            tokens.push_back(t);
            i++;
            continue;
        }
        if (c == '(')
        {
            Token t;
            t.kind = '(';
            t.op = '(';
            tokens.push_back(t);
            i++;
            continue;
        }
        if (c == ')')
        {
            Token t;
            t.kind = ')';
            t.op = ')';
            tokens.push_back(t);
            i++;
            continue;
        }
        return false;
    }
    return true;
}

bool infixToPostfix(const SLList<Token> &infix, MyQueue<Token> &out)
{
    MyStack<Token> st;
    SLList<Token>::Iterator it = infix.begin();
    SLList<Token>::Iterator itEnd = infix.end();
    for (; it != itEnd; ++it)
    {
        Token t = *it;
        if (t.kind == 'N')
        {
            out.push(t);
        }
        else if (t.kind == 'O')
        {
            while (!st.empty() && st.top().kind == 'O' && precedent(st.top().op) >= precedent(t.op))
            {
                out.push(st.top());
                st.pop();
            }
            st.push(t);
        }
        else if (t.kind == '(')
        {
            st.push(t);
        }
        else if (t.kind == ')')
        {
            bool found = false;
            while (!st.empty())
            {
                if (st.top().kind == '(')
                {
                    found = true;
                    st.pop();
                    break;
                }
                out.push(st.top());
                st.pop();
            }
            if (!found)
                return false;
        }
        else
        {
            return false;
        }
    }
    while (!st.empty())
    {
        if (st.top().kind == '(' || st.top().kind == ')')
            return false;
        out.push(st.top());
        st.pop();
    }
    return true;
}

bool evalPostfix(MyQueue<Token> postfix, long long &res)
{
    MyStack<long long> st;
    while (!postfix.empty())
    {
        Token t = postfix.front();
        postfix.pop();
        if (t.kind == 'N')
        {
            st.push(t.value);
        }
        else if (t.kind == 'O')
        {
            if (st.size() < 2)
                return false;

            long long b = st.top();
            st.pop();
            long long a = st.top();
            st.pop();

            long long r;
            if (t.op == '+')
                r = a + b;
            else if (t.op == '-')
                r = a - b;
            else if (t.op == '*')
                r = a * b;
            else if (t.op == '/')
            {
                if (b == 0)
                    return false;
                r = a / b;
            }
            else
            {
                return false;
            }
            st.push(r);
        }
        else
        {
            return false;
        }
    }
    if (st.size() != 1)
        return false;

    res = st.top();
    return true;
}

bool readExpressionFromFile(const std::string &filename, std::string &expr)
{
    std::ifstream fin;
    fin.open(filename.c_str());
    if (!fin.is_open())
        return false;
    expr = "";
    char c;
    while (fin.get(c))
    {
        if (c == '\n' || c == '\r')
            break;
        expr += c;
    }
    fin.close();
    if (expr == "")
        return false;
    return true;
}
#endif // POSTFIX_H