#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CStudent
{
private:
    string m_Name;
    string m_ID;
    vector<pair<string, pair<int, float>>> m_Subjects;
public:
    CStudent(/* args */);
    CStudent(const CStudent& other);
    CStudent(string name, string id, vector<pair<string, pair<int, float>>> subjects);
    ~CStudent();
    friend istream& operator>>(istream& in,CStudent& stdt);
    friend ostream& operator<<(ostream& out,const CStudent& stdt);
    float AverageGrade() const;
    bool operator>(const CStudent& other);
    bool operator>=(const CStudent& other);
    bool operator==(const CStudent&other);
    bool operator<(const CStudent&other);
    bool operator<=(const CStudent&other);
    string getID() const;
    string getName() const;
};
class CListStudent
{
private:
    vector<CStudent> m_Student;
public:
    CListStudent();
    CListStudent(const CListStudent&listStudent);
    CListStudent(vector<CStudent> students);
    ~CListStudent();
    void Input();
    void Output();
    CStudent FindMaxGPAStudent();
    CStudent FindMinGPAStudent();
    void SortAscending();
    void SortDescending();
    void DeleteStudent(string mssv);
    CStudent FindStudent(string mssv);
    void RankStudent();
};


#endif // STUDENT_H