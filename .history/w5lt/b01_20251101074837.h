#ifndef BAI01_H
#define BAI01_H

#include <iostream>
using namespace std;

class Address
{
private:
    string street;
    string city;
    string state;
public:
    void display();
};

class Student
{
private:
    string name;
    string studentID;
    float gpa;
    Address address;
public:
    Student();
    Student(string _n, string id, string _gpa, string _adr);
    Student(const Student&other);

    string getGrade() const;
    void display();
};

class ExchangeStudent: public Student
{
private:

public:
    
};

#endif