#ifndef LIBRARYW7_H
#define LIBRARYW7_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

class CCatalogue
{
private:
    string m_ID;
    string m_Title;
    string m_Author;
    int m_Count;// So lan muon
public:
    virtual ~CCatalogue() { };
    virtual void Input(stringstream& ss) = 0;
    virtual void Output(ostream& os) = 0;
    virtual int GetYear() const = 0;
    virtual string getType() const =0;

    string getID() const;
    string getAuthor() const;
};

class CBook : public CCatalogue
{
private:
    string m_Publisher;
    string m_Version;
    int m_Year;

public:
    void Input(stringstream&& ss) override;
    void Output(ostream& os) override;
    int getYear() const override;
    string getType() const override;
}

class CPaper : public CCatalogue
{
private: 
    string m_Journal;
    int m_Year;
public: 
    void Input(stringstream&& ss) override;
    void Output(ostream& os) override;
    int getYear() const override;
    string getType() const override;
}

class CThesis : public CCatalogue
{
private:
    string m_School;
    string m_Faculty;
    int m_Year;
public:
    void Input(stringstream&& ss) override;
    void Output(ostream&os) override;
    int getYear() const override;
    string getType() const override;
};

class CLibrary
{
private:
    vector<CCatalogue*> m_Catalogues;
    string trim(const string&str);
public:
    ~CLibrary();

    void Input(const string&filename);
    void Output(const string&filename);
    void Delete();
    void SortYear();
    void SearchByAuthor();
    void FilterByType();
    void PrintToConsole();
};

#endif 