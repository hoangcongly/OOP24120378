#include "Array.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "KHOI TAO MANG MAC DINH" << endl;
    cout << "Mang a: ";
    Array a;
    a.output();

    cout << "\nNHAP MANG TU BAN PHIM" << endl;
    a.input();
    cout << "Mang vua nhap: ";
    a.output();

    cout << "\nKHOI TAO MANG TU MANG CO SAN" << endl;
    int arr[] = {5, 2, 8, 1, 9};
    Array b(arr, 5);
    cout << "Mang b: ";
    b.output();

    cout << "\nSAO CHEP MANG" << endl;
    Array c = b;
    cout << "Mang c (copy tu b): ";
    c.output();

    cout << "\nDOI KICH THUOC MANG" << endl;
    b.setSize(7);
    cout << "Mang b sau khi tang kich thuoc len 7: ";
    b.output();

    b.setSize(3);
    cout << "Mang b sau khi giam kich thuoc xuong 3: ";
    b.output();

    cout << "\nLAY VA THAY DOI PHAN TU" << endl;
    cout << "Phan tu thu 1 cua c: " << c.getElement(1) << endl;
    c.setElement(1, 100);
    cout << "Mang c sau khi thay doi: ";
    c.output();

    cout << "\nTIM KIEM PHAN TU" << endl;
    int pos = c.find(100);
    if (pos != -1)
        cout << "Tim thay 100 tai vi tri " << pos << endl;
    else
        cout << "Khong tim thay 100" << endl;

    cout << "\nSAP XEP MANG TANG DAN" << endl;
    c.sort(true);
    c.output();

    cout << "\nSAP XEP MANG GIAM DAN" << endl;
    c.sort(false);
    c.output();

    return 0;
}
