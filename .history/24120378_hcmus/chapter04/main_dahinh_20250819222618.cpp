#include "Rectangle.h"
#include "Square.h"

void main()
{
    Rectangle *pRec;
    Rectangle Rec;
    Square Sq;
    cout << "Rectangle's size(width and height): ";
    pRec= &Rec;
    pRec->Input(cin);
    cout << "Rectangle's area= " << pRec->Area() << endl;
    cout << "Square's size: ";
    pRec=&Sq;
    pRec->Input(cin);
    cout << "Square's area= " << pRec->Area() << endl;
}