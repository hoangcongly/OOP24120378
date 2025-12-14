#include <string>
#include <fstream>
#include <stdexcept>
#include "PostFix.h"
#include <iostream>
using namespace std;

// ================== HÀM HỖ TRỢ IN DEBUG ==================

void printOneToken(const Token &t)
{
    if (t.kind == 'N')
    {
        cout << "[N:" << t.value << "]";
    }
    else if (t.kind == 'O')
    {
        cout << "[O:" << t.op << "]";
    }
    else if (t.kind == '(' || t.kind == ')')
    {
        cout << "[" << t.kind << "]";
    }
    else
    {
        cout << "[?]";
    }
}

// In danh sách token (SLList<Token>)
void printTokenList(const SLList<Token> &lst, const string &label)
{
    cout << label;
    SLList<Token>::Iterator it = lst.begin();
    SLList<Token>::Iterator itEnd = lst.end();
    if (it == itEnd)
    {
        cout << "(empty)";
    }
    else
    {
        for (; it != itEnd; ++it)
        {
            printOneToken(*it);
            cout << " ";
        }
    }
    cout << "\n";
}

// In queue token (MyQueue<Token>) – truyền theo VALUE để không làm thay đổi queue thật
void printTokenQueue(MyQueue<Token> q, const string &label)
{
    cout << label;
    if (q.empty())
    {
        cout << "(empty)";
    }
    else
    {
        while (!q.empty())
        {
            Token t = q.front();
            printOneToken(t);
            cout << " ";
            q.pop();
        }
    }
    cout << "\n";
}

// In stack token (MyStack<Token>) – truyền theo VALUE để không phá stack thật
void printTokenStack(MyStack<Token> st, const string &label)
{
    cout << label;
    if (st.empty())
    {
        cout << "(empty)\n";
        return;
    }

    // Vì stack: top ở cuối, mình pop dần ra: in từ top → bottom
    cout << "(top -> bottom): ";
    while (!st.empty())
    {
        Token t = st.top();
        printOneToken(t);
        cout << " ";
        st.pop();
    }
    cout << "\n";
}

// ================== PHIÊN BẢN DEBUG CỦA INFIX -> POSTFIX ==================
//
// Không đụng vào infixToPostfix trong POSTFIX_H,
// mình viết một hàm khác tên: infixToPostfixDebug
// Logic giống, nhưng sau mỗi token sẽ in trạng thái.

bool infixToPostfixDebug(const SLList<Token> &infix, MyQueue<Token> &out)
{
    MyStack<Token> st;
    int step = 1;

    SLList<Token>::Iterator it = infix.begin();
    SLList<Token>::Iterator itEnd = infix.end();

    for (; it != itEnd; ++it)
    {
        Token t = *it;

        cout << "\n========== STEP " << step++ << " ==========\n";
        cout << "Current token: ";
        printOneToken(t);
        cout << "\n";

        if (t.kind == 'N')
        {
            // số: cho vào output
            out.push(t);
            cout << "Action: push NUMBER to output.\n";
        }
        else if (t.kind == 'O')
        {
            cout << "Action: operator, compare precedence with stack top.\n";
            while (!st.empty() &&
                   st.top().kind == 'O' &&
                   precedent(st.top().op) >= precedent(t.op))
            {
                cout << "  Pop from stack to output because ";
                cout << "precedent(" << st.top().op << ") >= precedent(" << t.op << ")\n";

                out.push(st.top());
                st.pop();
            }
            cout << "  Push current operator to stack.\n";
            st.push(t);
        }
        else if (t.kind == '(')
        {
            cout << "Action: push '(' to stack.\n";
            st.push(t);
        }
        else if (t.kind == ')')
        {
            cout << "Action: found ')', pop until '('.\n";
            bool found = false;
            while (!st.empty())
            {
                if (st.top().kind == '(')
                {
                    found = true;
                    st.pop(); // bỏ '('
                    cout << "  Found '(', pop and stop.\n";
                    break;
                }
                cout << "  Pop from stack to output.\n";
                out.push(st.top());
                st.pop();
            }
            if (!found)
            {
                cout << "Error: ')' found but no matching '('.\n";
                return false;
            }
        }
        else
        {
            cout << "Error: unknown token kind.\n";
            return false;
        }

        // In trạng thái sau khi xử lý token
        printTokenQueue(out, "Output queue: ");
        printTokenStack(st, "Operator stack: ");
        cout << "====================================\n";
    }

    cout << "\n========== FINAL POP FROM STACK ==========\n";
    while (!st.empty())
    {
        if (st.top().kind == '(' || st.top().kind == ')')
        {
            cout << "Error: mismatched parentheses.\n";
            return false;
        }
        cout << "Pop from stack to output: ";
        printOneToken(st.top());
        cout << "\n";
        out.push(st.top());
        st.pop();

        printTokenQueue(out, "Output queue: ");
        printTokenStack(st, "Operator stack: ");
        cout << "------------------------------------\n";
    }

    cout << "========== DONE INFIX -> POSTFIX ==========\n";
    return true;
}

// ================== MAIN ==================

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string expr;
    int choice;

    cout << "Chon cach nhap bieu thuc:\n";
    cout << "1. Nhap tu ban phim\n";
    cout << "2. Doc tu file (dong dau tien)\n";
    cout << "Lua chon: " << std::flush;
    cin >> choice;
    cin.ignore(1000, '\n'); // bo \n con lai trong buffer

    if (choice == 1)
    {
        cout << "Nhap bieu thuc: ";
        getline(cin, expr);
    }
    else if (choice == 2)
    {
        string filename;
        cout << "Nhap ten file: ";
        getline(cin, filename);

        if (!readExpressionFromFile(filename, expr))
        {
            cout << "Khong doc duoc bieu thuc tu file.\n";
            return 0;
        }
        cout << "Bieu thuc doc duoc: " << expr << "\n";
    }
    else
    {
        cout << "Lua chon khong hop le.\n";
        return 0;
    }

    cout << "\n===== EXPRESSION =====\n";
    cout << expr << "\n";

    // 1) Tokenize
    SLList<Token> tokens;
    if (!tokenize(expr, tokens))
    {
        cout << "ERROR: Loi khi tokenize (ky tu khong hop le).\n";
        return 0;
    }

    printTokenList(tokens, "\nTokens (infix order): ");

    // 2) Infix -> Postfix (co debug)
    MyQueue<Token> postfix;
    bool ok = infixToPostfixDebug(tokens, postfix);
    if (!ok)
    {
        cout << "ERROR: Loi khi chuyen infix sang postfix (sai ngoac hoac cau truc).\n";
        return 0;
    }

    // In postfix cuoi cung
    printTokenQueue(postfix, "\nPostfix cuoi cung: ");

    // 3) Evaluate postfix
    long long result;
    if (!evalPostfix(postfix, result))
    {
        cout << "\nERROR: Loi khi tinh gia tri postfix (chia 0 hoac bieu thuc sai).\n";
        return 0;
    }

    cout << "\n===== RESULT =====\n";
    cout << result << "\n";

    return 0;
}
