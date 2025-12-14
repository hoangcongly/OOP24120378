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
    if(std:: string::npos==first) return str;
    size_t last= str.find_last_not_of(" \t\n\r");
    return str.substr(first,(last-first+1));
}
CLibrary::~CLibrary()
{
    for(auto&cat:m_Catalogues)
    {
        delete cat;
    }
    m_Catalogues.clear();
}
void CLibrary::Input(const std:: string&filename)
{
    std:: ifstream inFile(filename);
    if(!inFile)
    {
        std:: cerr << "Khong the mo file \n";
        return;
    }
    std:: string line;
    while(std::getline(inFile,line))
    {
        if(line.empty()) continue;
        CCatalogue*pCat=nullptr;
        char type=line[0];
        if(type=='B') pCat=new CBook();
        else if(type=='P') pCat= new CPaper();
        else if(type=='T') pCat= new CThesis();
        if(pCat)
        {
            std::stringstream ss(line);
            pCat->Input(ss);
            m_Catalogues.push_back(pCat);
        }
    }
    inFile.close();
}
void CLibrary:: Output(const std:: string&filename)
{
    std:: ofstream(outFile);
    if(!outFile)
    {
        std:: cerr << "Khong the mo file\n";
        return;
    }
    int ind=1;
    for(const auto&cat:m_Catalogues)
    {
        if(cat->getType()=="B")
        {
            outFile<< ind++ << ". ";
            cat->Output(outFile);
            outFile <<std:: endl;
        }
    }
    for(const auto& cat: m_Catalogues)
    {
        if(cat->getType()=="P")
        {
            outFile << ind++ << ". ";
            cat->Output(outFile);
            outFile << std:: endl;
        }
    }
    for(const auto& cat: m_Catalogues)
    {
        if(cat->getType()=="T")
        {
            outFile << ind++ << ". ";
            cat->Output(outFile);
            outFile << std:: endl;           
        }
    }
}
void CLibrary:: Delete()
{
    std:: string id_del;
    std:: cout << "Nhap ID can xoa khoi danh sach: ";
    std:: cin >> id_del;

    auto it=m_Catalogues.begin();
    bool found=false;
    while(it!=m_Catalogues.end())
    {
        if((*it)->getID()==id_del)
        {
            delete*it;
            it=m_Catalogues.erase(it);
            found=true;
            break;
        }
        else
        {
            ++it;
        }
    }
    if(!found)
    {
        std:: cout << "Khong tim thay tai lieu co ID: " << id_del << std:: endl;
    }
}
void CLibrary:: SortYear()
{
    std::sort(m_Catalogues.begin(),m_Catalogues.end(), [](const CCatalogue*a, const CCatalogue*b){ return a->getYear() < b->getYear();});
}
void CLibrary::SearchByAuthor()
{
    std:: string author_name;
    std:: cout << "Nhap ten tac gia: ";
    std:: cin.ignore();
    std:: getline(std:: cin, author_name);
    bool found=false;
    for(const auto&cat: m_Catalogues)
    {
        if(cat->getAuthor().find(author_name)!=std::string::npos)
        {
            cat->Output(std::cout);
            std:: cout << std:: endl;
            found=true;
        }
    }
    if(!found)
    {
        cout << "Khong tim thay tai lieu nao cua tac gia co ten chua: " << author_name << endl;
    }
}