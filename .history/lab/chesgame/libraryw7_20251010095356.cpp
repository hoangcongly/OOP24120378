#include "libraryw7.h"

std:: string CCatalogue:: getID() const {return m_ID;}
std:: string CCatalogue:: getAuthor() const {return m_Author;}

int CBook:: getYear() const {return m_Year;}
std:: string CBook:: getType() const {return "B";} 
void CBook:: Input(std:: stringstream&ss) 
{
    std:: string count_str,date_str;
    std:: getline(ss, this->m_ID,',');
    std:: getline(ss, this->m_Title,',');
    std:: getline(ss, this->m_Author,',');
    std:: getline(ss, count_str,',');
    std:: getline(ss, this->m_Publisher,',');
    std:: getline(ss, this->m_Version, ',');
    std:: getline(ss, date_str);
    this->m_Count= std:: stoi(CLibrary::trim(count_str));
    size_t last_flash = date_str.find_last_of('/');
    this->m_Year = std:: stoi(CLibrary::trim(date_str.substr(last_flash+1)));
}
void CBook::Output(std:: ostream&os)
{
    os << m_ID << ", " << m_Title << ", " << m_Author << ", " << m_Count << ", "
       << m_Publisher << ", " << m_Version << ", " << "dd/mm/" << m_Year;
}

int CPaper:: getYear() const
{
    return m_Year;
}
std:: string CPaper:: getType() const
{
    return "P";
}
void CPaper:: Input(std:: stringstream& ss)
{
    std:: string count_str, date_str;
    std:: getline(ss, this->m_ID, ',');
    std:: getline(ss, this->m_Title,',');
    std:: getline(ss, this->m_Author,',');
    std:: getline(ss, count_str,',');
    std:: getline(ss, this->m_Journal, ',');
    std:: getline(ss, date_str);

    this->m_Count= std:: stoi(CLibrary::trim(count_str));
    size_t last_flash= date_str.find_last_of('/');
    this->m_Year= std:: stoi(CLibrary::trim(date_str.substr(last_flash+1)));
}
void CPaper:: Output(std:: ostream& os)
{
    os << m_ID << ", " << m_Title << ", " << m_Author << ", " << m_Count << ", "
       << m_Journal << ", " << "dd/mm/" << m_Year;   
}

int CThesis:: getYear() const 
{
    return m_Year;
}
std:: string CThesis:: getType() const
{
    return "T";
}
void CThesis::Input(std:: stringstream&ss)
{
    std:: string count_str, date_str;
    std:: getline(ss, this->m_ID, ',');
    std:: getline(ss, this->m_Title,',');
    std:: getline(ss, this->m_Author,',');
    std:: getline(ss, count_str,',');
    std:: getline(ss, this->m_School, ',');
    std:: getline(ss, this->m_Faculty, ',');
    std:: getline(ss, date_str);

    this->m_Count= std:: stoi(CLibrary::trim(count_str));
    size_t last_flash= date_str.find_last_of('/');
    this->m_Year= std:: stoi(CLibrary::trim(date_str.substr(last_flash+1)));
}
void CThesis::Output(std:: ostream&os)
{
    os << m_ID << ", " << m_Title << ", " << m_Author << ", " << m_Count << ", "
       << m_School << ", "<< m_Faculty << ", " << "dd/mm/" << m_Year;      
}

std:: string CLibrary::trim(const std:: string&str)
{
    size_t first= str.find_first_not_of(" \t\n\r");
    if(string::npos==first) return str;
}