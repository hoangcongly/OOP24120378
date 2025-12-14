#include <iostream>
#include "MyString.h"

using namespace std;

void testConstructors()
{
    cout << "===== TEST 1: Constructors, operator<< =====\n";

    MyString s1("hello");
    MyString s2("world");
    MyString s3;      // default
    MyString s4 = s1; // copy ctor
    MyString s5;

    s5 = s2; // operator=

    cout << "s1 = " << s1 << "\n";
    cout << "s2 = " << s2 << "\n";
    cout << "s3 (default) = \"" << s3 << "\"\n";
    cout << "s4 (copy of s1) = " << s4 << "\n";
    cout << "s5 (assigned from s2) = " << s5 << "\n\n";
}

void testBasicAccess()
{
    cout << "===== TEST 2: size, empty, [], at, front, back =====\n";

    MyString s("hello");

    cout << "s = " << s << "\n";
    cout << "size = " << s.size() << "\n";
    cout << "empty = " << (s.empty() ? "true" : "false") << "\n";
    cout << "s[1] = " << s[1] << "\n";
    cout << "s.at(1) = " << s.at(1) << "\n";
    cout << "front = " << s.front() << "\n";
    cout << "back  = " << s.back() << "\n";

    cout << "\nTest at() out of range:\n";
    try
    {
        char c = s.at(100);
        cout << "s.at(100) = " << c << " (KHONG NEN THAY DONG NAY)\n";
    }
    catch (const out_of_range &e)
    {
        cout << "Throw out_of_range OK: " << e.what() << "\n";
    }
    cout << "\n";
}

void testModifiers()
{
    cout << "===== TEST 3: push_back, clear, operator+=, operator+ =====\n";

    MyString s1("hello");
    MyString s2("world");

    cout << "s1 = " << s1 << "\n";
    cout << "s2 = " << s2 << "\n";

    s1.push_back(' ');
    s1 += s2;  // nối chuỗi
    s1 += '!'; // thêm 1 kí tự

    cout << "Sau khi s1.push_back(' '), s1 += s2, s1 += '!':\n";
    cout << "s1 = " << s1 << "\n";

    MyString s3 = MyString("Test") + MyString(" ") + MyString("ABC");
    cout << "MyString(\"Test\") + \" \" + \"ABC\" = " << s3 << "\n";

    s3.clear();
    cout << "Sau clear(), s3 = \"" << s3 << "\", size = " << s3.size() << "\n\n";
}

void testCompare()
{
    cout << "===== TEST 4: operator==, !=, <, > =====\n";

    MyString a("apple");
    MyString b("banana");
    MyString c("apple");

    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    cout << "c = " << c << "\n\n";

    cout << "a == b ? " << (a == b ? "true" : "false") << "\n";
    cout << "a == c ? " << (a == c ? "true" : "false") << "\n";
    cout << "a != c ? " << (a != c ? "true" : "false") << "\n";
    cout << "a <  b ? " << (a < b ? "true" : "false") << "\n";
    cout << "b >  a ? " << (b > a ? "true" : "false") << "\n\n";
}

void testSubstrFind()
{
    cout << "===== TEST 5: substr, find =====\n";

    MyString s("hello world");

    cout << "s = " << s << "\n";

    MyString sub = s.substr(6, 5); // "world"
    cout << "s.substr(6, 5) = " << sub << "\n";

    int pos1 = s.find(MyString("lo wo")); // "hel[lo wo]rld" -> pos = 3
    cout << "s.find(\"lo wo\") = " << pos1 << "\n";

    int pos2 = s.find(MyString("abc"));
    cout << "s.find(\"abc\") = " << pos2 << " (nen la -1)\n";

    cout << "\nTest substr out of range:\n";
    try
    {
        MyString bad = s.substr(100, 3);
        cout << "substr(100,3) = " << bad << " (KHONG NEN THAY DONG NAY)\n";
    }
    catch (const out_of_range &e)
    {
        cout << "Throw out_of_range OK: " << e.what() << "\n";
    }

    cout << "\n";
}

void testIterator()
{
    cout << "===== TEST 6: Iterator (duyet tung ki tu) =====\n";

    MyString s("iterator test");
    cout << "s = " << s << "\n";
    cout << "Duyet bang MyString::Iterator:\n";

    for (MyString::Iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << '[' << *it << ']';
    }
    cout << "\n\n";
}

void testInput()
{
    cout << "===== TEST 7: operator>> (doc 1 tu), getline (doc ca dong) =====\n";

    MyString word, line;

    cout << "Nhap 1 tu (operator>>): ";
    cin >> word;
    cout << "Ban vua nhap: " << word << "\n";

    // Xử lý bỏ '\n' còn lại trong buffer trước khi getline
    cin.ignore(1000, '\n');

    cout << "Nhap ca dong (getline): ";
    getline(cin, line);
    cout << "Dong vua nhap: " << line << "\n\n";
}

void testReadFromFile()
{
    cout << "===== TEST 8: readFromFile =====\n";
    cout << "Gia su ban co file \"input.txt\" cung folder, noi dung bat ky.\n";

    MyString fileContent;
    if (readFromFile("input.txt", fileContent))
    {
        cout << "Noi dung file input.txt:\n";
        cout << fileContent << "\n";
    }
    else
    {
        cout << "Khong mo duoc file input.txt (kiem tra lai file).\n";
    }

    cout << "\n";
}

int main()
{
    testConstructors();
    testBasicAccess();
    testModifiers();
    testCompare();
    testSubstrFind();
    testIterator();
    testInput();
    testReadFromFile();

    cout << "===== TAT CA TEST DA CHAY XONG =====\n";
    return 0;
}