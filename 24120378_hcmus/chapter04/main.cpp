#include "Rectangle.h"
#include "Square.h"

int main()
{
    Rectangle Rec;
    Square Sq;
    cout << "Rectangle's size(width and height): ";
    Rec.Input(cin);
    cout << "Square'size: ";
    Sq.Input(cin);
    cout << "Square's area=" << Sq.Area() << endl;
    return 0;
}