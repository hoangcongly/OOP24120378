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
    Address(const string &s = "", const string &c = "", const string &st = "");
    void display() const;
};

class Student
{
private:
    string name;
    string studentID;
    float gpa;
    Address address;

public:
    Student(const string &n = "", const string &id = "", float g = 0.0, const Address &a = Address());
    char getGrade() const;
    virtual void display() const;
};

class ExchangeStudent : public Student
{
private:
    string homeCountry;
    int duration;

public:
    ExchangeStudent(const string &n = "", const string &id = 0, float g = 0.0, const Address &a = Address(), const string &hc = "", int dur = 0);
    void updateDuration(int newDuration);
    void display() const override;
};

#endif