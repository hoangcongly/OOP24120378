#include <iostream>
// ĐÃ XÓA: #include <string>
#include "MyStack.h"

using namespace std;

int main()
{
    // --- 1. Kiểm tra với MyStack<int> ---
    cout << "--- Kiem tra MyStack<int> ---" << endl;
    MyStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Kich thuoc stack: " << stack.size() << endl; // 3
    cout << "Dinh stack (top): " << stack.top() << endl;  // 30

    stack.pop();                                               // Xóa 30
    cout << "Dinh stack sau khi pop: " << stack.top() << endl; // 20

    cout << "Duyet stack (LIFO): ";
    for (int &value : stack)
    {
        cout << value << " "; // 20 10
    }
    cout << endl;

    // --- 2. Kiểm tra Copy Constructor (với int) ---
    cout << "\n--- Kiem tra Copy Constructor (int) ---" << endl;
    MyStack<int> stackCopy = stack; // Sao chép (20, 10)

    stack.pop();                                            // Xóa 20 khỏi stack gốc
    cout << "Dinh stack goc: " << stack.top() << endl;      // 10
    cout << "Dinh stack copy: " << stackCopy.top() << endl; // 20

    // --- 3. THAY ĐỔI: Kiểm tra với MyStack<const char*> ---
    // (Thay thế cho std::string)
    cout << "\n--- Kiem tra MyStack<const char*> ---" << endl;
    MyStack<const char *> cstrStack;
    cstrStack.push("the");
    cstrStack.push("quick");
    cstrStack.push("brown");
    cstrStack.push("fox");

    cout << "Dinh stack C-string: " << cstrStack.top() << endl; // fox

    cout << "Duyet stack C-string: ";
    for (const char *s : cstrStack)
    {
        cout << s << " "; // fox quick brown the
    }
    cout << endl;

    return 0;
}