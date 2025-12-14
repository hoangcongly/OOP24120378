#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>
class Person
{
private:
    char *_name;

public:
    Person();
    Person(const char *n);
    virtual ~Person();
    Person(const Person &other);
    Person &operator=(const Person &other);

    void setName(const char *newName);
    const char *getName() const;

    virtual void display() const;
};

#endif