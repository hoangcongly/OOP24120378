#include "Student.h"

Student::Student() : Person()
{
    capacity = 10;
    numGrades = 0;
    grades = new int[capacity];
}

Student::Student(const char *initialName, int gradeCapacity) : Person(initialName)
{
    capacity = (gradeCapacity > 0) ? gradeCapacity : 10;
    numGrades = 0;
    grades = new int[capacity];
}

Student::~Student()
{
    delete[] grades;
}

Student::Student(const Student &other) : Person(other)
{
    capacity = other.capacity;
    numGrades = other.numGrades;
    grades = new int[capacity];
    for (int i = 0; i < numGrades; i++)
    {
        grades[i] = other.grades[i];
    }
}

Student &Student::operator=(const Student &other)
{
    if (this == &other)
    {
        return *this;
    }
    Person::operator=(other);
    delete[] grades;
    capacity = other.capacity;
    numGrades = other.numGrades;
    grades = new int[capacity];
    for (int i = 0; i < numGrades; i++)
    {
        grades[i] = other.grades[i];
    }
    return *this;
}