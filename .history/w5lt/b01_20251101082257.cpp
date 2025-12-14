#include "b01.h"

Address::Address(const string &s, const string &c, const string &st)
{
    street = s;
    city = c;
    state = st;
}

void Address::display() const
{
    cout << "Address: " << street << ", " << city << ", " << state << endl;
}

Student::Student(const string &n, const string &id, float g, const Address &a)
{
    name = n;
    studentID = id;
    gpa = g;
    address = a;
}

char Student::getGrade() const
{
    if (gpa >= 3.5)
        return 'A';
    else if (gpa >= 3.0)
        return 'B';
    else if (gpa >= 2.0)
        return 'C';
    else if (gpa >= 1.0)
        return 'D';
    else
        return 'F';
}

void Student::display() const
{
    cout << "Name: " << name << endl
         << "ID: " << studentID << endl
         << "GPA: " << gpa << "(" << getGrade() << ")" << endl;
    address.display();
}

ExchangeStudent::ExchangeStudent(const string &n, const string &id, float g, const Address &a, const string &hc, int dur) : Student(n, id, g, a)
{
    homeCountry = hc;
    duration = dur;
}

void ExchangeStudent::updateDuration(int newDuration)
{
    duration = newDuration;
}

void ExchangeStudent::display() const
{
    Student::display();
    cout << "Home Country: " << homeCountry << endl
         << "Exchange Duration: " << duration << " months\n"
         << endl;
}