#pragma once

#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"
#include "SoNguyenLon.h"
#include <fstream>

#define MAX_SNL 2000
struct Token
{
    char kind;
    SoNguyenLon value;
    char op;
    Token() : kind('N'), value((unsigned long)0), op(0) {}
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

bool tokenize(const char *s, SLList<Token> &tokens)
{
    int i = 0;
    while (s[i] != '\0')
    {
        char c = s[i];
        if (c == ' ')
        {
            i++;
            continue;
        }
        if (isDigitChar(c))
        {
            char buf[MAX_SNL];
            int k = 0;
            while (s[i] != '\0' && isDigitChar(s[i]))
            {
                if (k < MAX_SNL - 1)
                {
                    buf[k++] = s[i];
                }
                i++;
            }
            buf[k] = '\0';

            Token t;
            t.kind = 'N';
            SoNguyenLon tmp(buf);
            t.value = tmp;
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

bool evalPostfix(MyQueue<Token> postfix, SoNguyenLon &res)
{
    MyStack<SoNguyenLon> st;
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

            SoNguyenLon b = st.top();
            st.pop();
            SoNguyenLon a = st.top();
            st.pop();

            SoNguyenLon r;
            if (t.op == '+')
                r = a + b;
            else if (t.op == '-')
                r = a - b;
            else if (t.op == '*')
                r = a * b;
            // else if (t.op == '/')
            // {
            //     if (b == 0)
            //         return false;
            //     r = a / b;
            // }
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

bool readFile(const char *filepath, SLList<const char *> &lines)
{
    std::ifstream fin(filepath);
    if (!fin)
    {
        std::cout << "Khong the mo file" << endl;
        return false;
    }
    const int MAXLINE = 1000;
    char line[MAXLINE];
    while (fin.getline(line, MAXLINE))
    {
        char *linecpy = new char[strlen(line) + 1];
        strcpy(linecpy, line);
        lines.push_back(linecpy);
    }
    fin.close();
    return !lines.empty();
}
