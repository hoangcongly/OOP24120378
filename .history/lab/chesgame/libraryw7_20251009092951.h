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
    std:: string m_ID;
    std:: string m_Title;
    std:: string m_Author;
    int m_Count;// So lan muon
public:
    virtual ~CCatalogue() { };
    virtual void Input(std:: stringstream& ss) = 0;
    virtual void Output(std:: ostream& os) = 0;
    virtual int GetYear() const = 0;
    virtual std::string getType() const =0;

    std::string getID() const;
    std::string getAuthor() const;
};

class CBook : public CCatalogue
{
private:
    std:: string m_Publisher;
    std:: string m_Version;
    int m_Year;

public:
    void Input(std:: stringstream&& ss) override;
    void Output(std:: ostream& os) override;
    int getYear() const override;
    std:: string getType() const override;
}

class CPaper : public CCatalogue
{
private: 
    std:: string m_Journal;
    int m_Year;
public: 
    void Input(std:: stringstream&& ss) override;
    void Output(std:: ostream& os) override;
    int getYear() const override;
    std:: string getType() const override;
}

class CThesis : public CCatalogue
{
private:
    std:: string m_School;
    std:: string m_Faculty;
    int m_Year;
public:
    void Input(std:: stringstream&& ss) override;
    void Output(std:: ostream&os) override;
    int getYear() const override;
    std:: string getType() const override;
};

class CLibrary
{
private:
    std:: vector<CCatalogue*> m_Catalogues;
    std:: string trim(const string&str);
public:
    ~CLibrary();

    void Input(const std:: string&filename);
    void Output(const std:: string&filename);
    void Delete();
    void SortYear();
    void SearchByAuthor();
    void FilterByType();
    void PrintToConsole();
};

#endif 