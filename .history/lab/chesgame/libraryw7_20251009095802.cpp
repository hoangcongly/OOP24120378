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
    this->m_Year = std:: stoi(CLibrary().*&CLibrary::trim(date_str.substr(last_flash+1)));
}