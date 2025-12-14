#include <iostream>
#include "figures.h"

using namespace std;

void inputCircleData(istream& inDevice, Circle& cir) {
	double x0, y0, r;
	inDevice >> x0 >> y0 >> r;	
	cir.Set(x0, y0, r);
}

void outputCircleInfo(ostream& outDevice, Circle& cir) {	
	outDevice << " - Area of circle = " << cir.Area() << "\n";
	outDevice << " - Perimeter of circle = " << cir.Perimeter() << "\n";
}

istream&operator >> (istream&inDevice, Circle&cir)
{
    double x0, y0, r;
    inDevice >> x0 >> y0 >> r;
    cir.Set(x0, y0, r);
    return inDevice;
}
ostream&operator << (ostream&outDevice, Circle&cir)
{
    outDevice << " - Area of circle = " << cir.Area() << "\n";
	outDevice << " - Perimeter of circle = " << cir.Perimeter() << "\n";
	return outDevice;
}

int main()
{
    Circle mycir;
    cout << "Input center and radius: "; 
    // inputCircleData(cin, mycir);
    // outputCircleInfo(cout, mycir);
    cin >> mycir;
    cout << mycir; 
    cin.get();
    return 0;
}