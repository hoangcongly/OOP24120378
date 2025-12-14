#include "b01.h"

Address:: Address(const string& s, const string& c, const string& st)
{
    street=s;
    city=c;
    state= st;
}

void Address::display() const
{
    cout << "Address: " << street << ", " << city << ", "<< state << endl;
}

Student::Student(const string& n, const string& id, float g, const Address&a)
{
    name= n;
    studentID= id;

}