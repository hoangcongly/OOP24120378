#include <iostream>
#include "MySet.h"

using namespace std;

void testBasic()
{
    cout << "===== TEST 1: Constructors, insert, operator<< =====\n";

    int arrA[] = {5, 1, 3, 3, 2, 5, 4};
    int nA = sizeof(arrA) / sizeof(arrA[0]);

    MySet<int> A(arrA, nA); // tự loại trùng + sort

    cout << "A (tu mang {5,1,3,3,2,5,4}) = " << A << "\n";
    cout << "size(A) = " << A.size() << ", empty? " << (A.empty() ? "true" : "false") << "\n\n";

    cout << "Chen 3 vao A (da co 3): ";
    bool ins3 = A.insert(3);
    cout << (ins3 ? "insert OK" : "khong insert vi da ton tai") << ", A = " << A << "\n";

    cout << "Chen 10 vao A: ";
    bool ins10 = A.insert(10);
    cout << (ins10 ? "insert OK" : "khong insert") << ", A = " << A << "\n\n";
}

void testEraseFind()
{
    cout << "===== TEST 2: erase(value), contains, find, erase(iterator) =====\n";

    int arrB[] = {2, 4, 6, 8, 10};
    MySet<int> B(arrB, 5);

    cout << "B = " << B << "\n";

    cout << "B.contains(4)? " << (B.contains(4) ? "true" : "false") << "\n";
    cout << "B.contains(5)? " << (B.contains(5) ? "true" : "false") << "\n";

    cout << "Xoa 6 khoi B: ";
    bool e6 = B.erase(6);
    cout << (e6 ? "xoa OK" : "khong tim thay") << ", B = " << B << "\n";

    cout << "Xoa 100 khoi B: ";
    bool e100 = B.erase(100);
    cout << (e100 ? "xoa OK" : "khong tim thay") << ", B = " << B << "\n";

    cout << "Tim 8 trong B, neu co thi xoa bang iterator:\n";
    MySet<int>::Iterator it = B.find(8);
    if (it != B.end())
    {
        cout << "  Tim thay 8, xoa bang iterator...\n";
        B.erase(it);
    }
    else
    {
        cout << "  Khong tim thay 8.\n";
    }
    cout << "B sau khi xoa bang iterator: " << B << "\n\n";
}

void testCompare()
{
    cout << "===== TEST 3: operator==, !=, <, > =====\n";

    int arrC1[] = {1, 2, 3};
    int arrC2[] = {1, 2, 3};
    int arrC3[] = {1, 3, 5};

    MySet<int> C1(arrC1, 3);
    MySet<int> C2(arrC2, 3);
    MySet<int> C3(arrC3, 3);

    cout << "C1 = " << C1 << "\n";
    cout << "C2 = " << C2 << "\n";
    cout << "C3 = " << C3 << "\n\n";

    cout << "C1 == C2 ? " << (C1 == C2 ? "true" : "false") << "\n";
    cout << "C1 != C3 ? " << (C1 != C3 ? "true" : "false") << "\n";
    cout << "C1 <  C3 ? " << (C1 < C3 ? "true" : "false") << "\n";
    cout << "C3 >  C1 ? " << (C3 > C1 ? "true" : "false") << "\n\n";
}

// void testSetOperations()
// {
//     cout << "===== TEST 4: setUnion, setIntersection, setDifference =====\n";

//     int arrA[] = {1, 2, 3, 4};
//     int arrB[] = {3, 4, 5, 6};

//     MySet<int> A(arrA, 4);
//     MySet<int> B(arrB, 4);

//     cout << "A = " << A << "\n";
//     cout << "B = " << B << "\n";

//     MySet<int> U = setUnion(A, B);
//     MySet<int> I = setIntersection(A, B);
//     MySet<int> D = setDifference(A, B); // A \ B

//     cout << "A ∪ B = " << U << "\n";
//     cout << "A ∩ B = " << I << "\n";
//     cout << "A \\ B = " << D << "\n\n";
// }

void testIterator()
{
    cout << "===== TEST 5: Duyet bang Iterator =====\n";

    int arr[] = {10, 7, 7, 3, 1, 20};
    MySet<int> S(arr, 6);

    cout << "S = " << S << "\n";
    cout << "Duyet S bang MySet<int>::Iterator:\n";

    for (MySet<int>::Iterator it = S.begin(); it != S.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n\n";
}

int main()
{
    testBasic();
    testEraseFind();
    testCompare();
    // testSetOperations();
    testIterator();

    cout << "===== TAT CA TEST DA CHAY XONG =====\n";
    return 0;
}
