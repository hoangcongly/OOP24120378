#include "Person.h"

Person::Person()
{
    const char*defaultName= "Unnamed";
    _name= new char[strlen(defaultName)+1];
    strcpy_s(_name, strlen(defaultName)+1, defaultName);
}

Person::Person(const char* initialName)
{
    _name= new char[strlen(initialName)+1];
    strcpy_s(_name, strlen(initialName)+1, initialName);
}

Person:: ~Person()
{
    delete[] _name;
}

Person:: Person(const Person&other)
{
    _name= new char[strlen(other._name)+1];
    strcpy_s(_name, strlen(other._name)+1, other._name);
}

Person& Person::operator=(const Person&other)
{
    if(this==&other)
    {
        return *this;
    }
    delete[] _name;
    _name= new char[strlen(other._name)+1];
    strcpy_s(_name, strlen(other._name)+1, other._name);
    return *this;
}

void Person:: setName(const char*newName)
{
    delete[] _name;
    _name= new char[strlen(newName)+1];
    strcpy_s(_name, strlen(newName)+1, newName);
}

const char* Person::getName() const
{
    return _name;
}

void Person::display() const
{
    std:: cout << "Name: " << _name << std::endl;
}