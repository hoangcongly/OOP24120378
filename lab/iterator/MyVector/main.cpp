#include <iostream>
#include "MyVector.h"
using namespace std;

int main()
{
    int a[5] = {1, 2, 3, 4, 5};

    // dùng constructor từ mảng C
    MyVector<int> v(a, 5);
    cout << "Duyet bang iterator: ";
    for (MyVector<int>::Iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    cout << "v.at(2) = " << v.at(2) << "\n";

    MyVector<int> w = v; // copy constructor
    cout << "v == w ? " << (v == w ? "true" : "false") << "\n";

    v.pop_back();
    cout << "Sau pop_back, v size = " << v.size() << "\n";
    cout << "v != w ? " << (v != w ? "true" : "false") << "\n";

    try
    {
        cout << "v.at(10) = " << v.at(10) << "\n";
    }
    catch (const std::out_of_range &e)
    {
        cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
