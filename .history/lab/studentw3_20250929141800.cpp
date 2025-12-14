#include "studentw3.h"

CStudent:: CStudent()
{
    m_Name="";
    m_ID="";
    m_Subjects.clear();
}
CStudent:: CStudent(const CStudent&other)
{
    m_Name= other.m_Name;
    m_ID=other.m_ID;
    m_Subjects= other.m_Subjects;
}
CStudent:: CStudent(string name, string id, vector<pair<string, pair<int, float>>> subjects)
{
    m_Name= name;
    m_ID= id;
    m_Subjects= subjects;
}
CStudent:: ~CStudent() {};
float CStudent::AverageGrade() const
{
    if(m_Subjects.empty()) return 0;
    float tong=0;
    float tongTC=0;
    for(auto&sub:m_Subjects)
    {
        int tinChi= sub.second.first;
        float diem= sub.second.second;
        tong+= tinChi*diem;
        tongTC+= tinChi;
    }
    return tongTC? tong/tongTC:0;
}
bool CStudent::operator>(const CStudent& other) 
{
    return this->AverageGrade() > other.AverageGrade();
}
bool CStudent::operator>=(const CStudent& other)
{
    return this->AverageGrade()>= other.AverageGrade();
}
bool CStudent::operator==(const CStudent&other)
{
    return this->AverageGrade()== other.AverageGrade();
}
bool CStudent::operator<(const CStudent&other)
{
    return this->AverageGrade()< other.AverageGrade();
}
bool CStudent::operator<=(const CStudent&other)
{
    return this->AverageGrade()<=other.AverageGrade();
}
istream &operator>>(istream&in, CStudent&stdt)
{
    cout << "Nhap ten sinh vien: "; 
    getline(in, stdt.m_Name);
    cout << "Nhap ID sinh vien: ";
    getline(in, stdt.m_ID);
    int n;
    cout << "Nhap so mon hoc: ";
    cin >> n;
    in.ignore();
    stdt.m_Subjects.clear();
    for(int i=0; i<n; i++)
    {
        string subject;
        int tinchi;
        float diem;
        cout << "Mon: " << i+1<< " :";
        getline(in, subject);
        cout << "So tin chi: ";
        cin >> tinchi;
        cout << "Diem: ";
        in>> diem;
        in.ignore();
        stdt.m_Subjects.push_back({subject,{tinchi, diem}});
    }
    return in;
}
ostream& operator<< (ostream&out, CStudent&stdt)
{
     out << stdt.m_ID << " - " << stdt.m_Name << "\n";
    for(auto& sj: stdt.m_Subjects)
    {
        out << "Mon hoc: " << sj.first 
            << ", So tin chi: " << sj.second.first 
            << ", Diem: " << sj.second.second << "\n"; 
    }
    return out;
}
CListStudent:: CListStudent() {};
CListStudent:: CListStudent(const CListStudent&listStudent)
{
    m_Student= listStudent.m_Student;
}
CListStudent:: CListStudent(vector<CStudent> students)
{
    m_Student= students;
}
void CListStudent:: Input()
{
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << "Sinh vien thu " << i+1 << " :";
        CStudent sv;
        cin >> sv;
        m_Student.push_back(sv);
    }
}
void CListStudent:: Output()
{
    for(auto& student: m_Student)
    {
        cout << student << endl;
    }
}
CStudent CListStudent:: FindMaxGPAStudent()
{
    if(m_Student.empty()) return  CStudent();
    CStudent maxstu= m_Student[0];
    for(int i=1;  i< m_Student.size(); i++)
    {
        if(m_Student[i].AverageGrade() > maxstu.AverageGrade())
        {
            maxstu= m_Student[i];
        }
    }
    return maxstu;
}
CStudent CListStudent::  FindMinGPAStudent()
{
    if(m_Student.empty()) return  CStudent();
    CStudent minstu= m_Student[0];
    for(int i=1;  i< m_Student.size(); i++)
    {
        if(m_Student[i].AverageGrade() < minstu.AverageGrade())
        {
            minstu= m_Student[i];
        }
    }
    return minstu;
}
string CStudent:: getID() const{
    return m_ID;
}
void CListStudent:: SortAscending()
{
    sort(m_Student.begin(), m_Student.end(),
         [](const CStudent& a, const CStudent& b) {
             return a.AverageGrade() < b.AverageGrade();
         });
}
void CListStudent::SortDescending()
{
    sort(m_Student.begin(), m_Student.end(),
         [](const CStudent& a, const CStudent& b) {
             return a.AverageGrade() > b.AverageGrade();
         });
}
void CListStudent:: DeleteStudent(string mssv)
{
    for(int i=0; i< m_Student.size(); i++)
    {
        if(m_Student[i].getID()==mssv)
        {
            m_Student.erase(m_Student.begin()+i);
            cout << "Da xoa sinh vien co ID: " << mssv << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ID: " << mssv << endl;
}
CStudent CListStudent:: FindStudent(string mssv)
{
    for(int i=0; i< m_Student.size(); i++)
    {
        if(m_Student[i].getID()==mssv) 
        {
            return m_Student[i];
        }
    }
    return CStudent();
}
string CStudent:: getName() const
{
    return m_Name;
}
void CListStudent::RankStudent()
{
    vector<CStudent> temp = m_Student;

    sort(temp.begin(), temp.end(),
         [](const CStudent& a, const CStudent& b) {
             return a.AverageGrade() > b.AverageGrade();
         });

    cout << "=== Bang xep hang sinh vien ===\n";
    int rank = 1;
    for (auto &sv : temp)
    {
        cout << "Hang " << rank++ << ": " << sv.getID()
             << " - " << sv.getName()
             << " - GPA: " << sv.AverageGrade() << endl;
    }
}
