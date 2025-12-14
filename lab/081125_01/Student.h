#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Person.h"
#include <cstring>

class Student : public Person
{
private:
    int *grades;   // con tro toi bang diem
    int numGrades; // so luong diem hien co
    int capacity;  // dung luong toi da cua bang diem

public:
    Student();
    Student(const char *initialName, int gradeCapacity);
    ~Student();
    Student(const Student &other);
    Student &operator=(const Student &other);

    void addGrade(int grade);
    double calculateGPA() const;
    virtual void display() const override;
};

#endif