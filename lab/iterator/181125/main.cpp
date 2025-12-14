#include "Expression.h"
#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"

using namespace std;

int main()
{
    SLList<char *> allLines;

    if (!readFile("input.txt", allLines))
    {
        cout << "Khong mo duoc file\n";
        return 1;
    }

    int linenum = 0;
    while (!allLines.empty())
    {
        char *line = allLines.front();
        allLines.RemoveHead();
        ++linenum;

        SLList<Token> tokens;
        MyQueue<Token> postfix;

        if (!tokenize(line, tokens) ||
            !infixToPostfix(tokens, postfix))
        {
            cout << "ERROR\n";
            delete[] line;
            continue;
        }

        SoNguyenLon res;
        if (!evalPostfix(postfix, res))
        {
            cout << "ERROR\n";
            delete[] line;
            continue;
        }

        cout << res << "\n";
        delete[] line; // nhớ giải phóng
    }

    return 0;
}
