#include <iostream>
#include <string>
#include <cctype> // isdigit, isspace
#include <stdexcept>
#include "SLList.h"

// ======================= MyStack =======================

template <class T>
class MyStack
{
private:
    SLList<T> _data; // dùng SLList làm container nền

public:
    MyStack() {}

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
        _data.push_back(value); // đỉnh = phần tử cuối
    }

    void pop()
    {
        if (empty())
        {
            throw std::out_of_range("MyStack::pop on empty stack");
        }
        _data.RemoveTail();
    }

    T &top()
    {
        if (empty())
        {
            throw std::out_of_range("MyStack::top on empty stack");
        }
        // phần tử cuối: index = size - 1
        return _data[_data.size() - 1];
    }

    const T &top() const
    {
        if (empty())
        {
            throw std::out_of_range("MyStack::top on empty stack");
        }
        return _data[_data.size() - 1];
    }
};

// ======================= MyQueue =======================

template <class T>
class MyQueue
{
private:
    SLList<T> _data;

public:
    MyQueue() {}

    bool empty() const
    {
        return _data.size() == 0;
    }

    int size() const
    {
        return _data.size();
    }

    void push(const T &value) // enqueue
    {
        _data.push_back(value); // thêm vào cuối
    }

    void pop() // dequeue
    {
        if (empty())
        {
            throw std::out_of_range("MyQueue::pop on empty queue");
        }
        _data.RemoveHead(); // bỏ phần tử đầu tiên
    }

    T &front()
    {
        if (empty())
        {
            throw std::out_of_range("MyQueue::front on empty queue");
        }
        // phần tử đầu tiên: index = 0
        return _data[0];
    }

    const T &front() const
    {
        if (empty())
        {
            throw std::out_of_range("MyQueue::front on empty queue");
        }
        return _data[0];
    }

    T &back()
    {
        if (empty())
        {
            throw std::out_of_range("MyQueue::back on empty queue");
        }
        return _data[_data.size() - 1];
    }

    const T &back() const
    {
        if (empty())
        {
            throw std::out_of_range("MyQueue::back on empty queue");
        }
        return _data[_data.size() - 1];
    }
};

// ======================= Token (không dùng enum) =======================
//
// kind:
//   'N' : number
//   'O' : operator (+ - * /)
//   '(' : dấu mở ngoặc
//   ')' : dấu đóng ngoặc
// =======================

struct Token
{
    char kind;       // 'N', 'O', '(', ')'
    long long value; // nếu kind == 'N'
    char op;         // nếu kind == 'O', '(' hoặc ')'

    Token()
    {
        kind = 'N';
        value = 0;
        op = 0;
    }
};

// ======================= Helper: độ ưu tiên toán tử =======================

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// ======================= B1: Tokenize biểu thức =======================

bool tokenize(const std::string &s, SLList<Token> &tokens)
{
    int n = (int)s.size();
    int i = 0;

    while (i < n)
    {
        char c = s[i];

        if (std::isspace((unsigned char)c))
        {
            i++;
            continue;
        }

        // số nguyên
        if (std::isdigit((unsigned char)c))
        {
            long long val = 0;
            while (i < n && std::isdigit((unsigned char)s[i]))
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

        // toán tử
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            Token t;
            t.kind = 'O';
            t.op = c;
            tokens.push_back(t);
            i++;
            continue;
        }

        // ngoặc
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

        // ký tự lạ -> lỗi
        return false;
    }

    return true;
}

// ======================= B2: Infix -> Postfix (Shunting-yard) =======================

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
            // số -> đưa thẳng ra output
            out.push(t);
        }
        else if (t.kind == 'O')
        {
            // toán tử: pop các toán tử ưu tiên >= rồi mới push
            while (!st.empty() &&
                   st.top().kind == 'O' &&
                   precedence(st.top().op) >= precedence(t.op))
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
            // pop đến khi gặp '('
            bool foundLParen = false;
            while (!st.empty())
            {
                if (st.top().kind == '(')
                {
                    foundLParen = true;
                    st.pop(); // bỏ '('
                    break;
                }
                out.push(st.top());
                st.pop();
            }
            if (!foundLParen)
                return false; // thiếu '('
        }
        else
        {
            // kind lạ
            return false;
        }
    }

    // pop phần còn lại
    while (!st.empty())
    {
        if (st.top().kind == '(' || st.top().kind == ')')
            return false; // ngoặc còn sót
        out.push(st.top());
        st.pop();
    }

    return true;
}

// ======================= B3: Evaluate Postfix =======================

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
                    return false; // chia 0
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

// ======================= MAIN =======================

int main()
{
    std::string expr;
    std::cout << "Nhap bieu thuc: ";
    std::getline(std::cin, expr);

    SLList<Token> tokens;
    if (!tokenize(expr, tokens))
    {
        std::cout << "ERROR\n";
        return 0;
    }

    MyQueue<Token> postfix;
    if (!infixToPostfix(tokens, postfix))
    {
        std::cout << "ERROR\n";
        return 0;
    }

    long long ans;
    if (!evalPostfix(postfix, ans))
    {
        std::cout << "ERROR\n";
        return 0;
    }

    std::cout << ans << "\n";
    return 0;
}
