#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book;
class BorrowerRecord;
class Libary;

class Book
{
private:
    string number;
    string author;
    string title;
    BorrowerRecord* borrower;
public: 
    Book(string number="NA", string author="NA", string title="NA")
    {
        this->setNumber(number);
        this->setAuthor(author);
        this->setTitle(title);
        this->setBorrower(nullptr);
    }
    void setNumber(string number)
    {
        this->number=number;
    }
    string getNumber()
    {
        return this->number;
    }
    void setAuthor(string author)
    {
        this->author=author;
    }
    string getAuthor()
    {
        return this->author;
    }
    void setTitle(string title)
    {
        this->title=title;
    }
    string getTitle()
    {
        return this->title;
    }
    void display() 
    {
        cout << "- Number: " << this->getNumber() 
        << "\n  Book: " << this->getTitle() 
        << "\n  Author: "<< this->getAuthor() << '\n';
    }
    void setBorrower(BorrowerRecord* borrowed)
    {
        this->borrower=borrowed;
    }
    void attachBorrower(BorrowerRecord*borrower)
    {
        this->setBorrower(borrower);
    }
    void detachBorrower(BorrowerRecord* borrower)
    {
        this->setBorrower(nullptr);
    }
    BorrowerRecord* getBorrower()
    {
        return this->borrower;
    }
};

class BorrowerRecord{
private:
    string name;
    vector<Book*> books;
public: 
    BorrowerRecord(string name, vector<Book*> books)
    {
        this->setName(name);
        this->setBooks(books);
    }
    BorrowerRecord(string name) : BorrowerRecord(name, vector<Book*>()) {};
    void setName(string name)
    {
        this->name=name;
    }
    string getName()
    {
        return this->name;
    }
    void setBooks(vector<Book*> books)
    {
        this->books=books;
    }
    vector<Book*> getBooks()
    {
        return this->books;
    }
    void display() 
    {
        cout << "Borrower: " << this->getName() << '\n';
    }
    void attachBook(Book*book)
    {
        this->books.push_back(book);
    }
    void detachBook()
    {
        this->books.pop_back();
    }
};

class Libary{
private:
    string name;
    vector<Book*> books;
    vector<BorrowerRecord*> borrowers;
public:
    Libary(string name)
    {
        this->name=name;
    }
    Libary() : Libary("NA") {};
    void setName(string name)
    {
        this->name= name;
    }
    string getName()
    {
        return this->name;
    }
    void display() {
        cout << this->getName() << "\nBooks:\n";
        for (int i = 0; i < books.size(); i++)
            books[i]->display();
    }
    void addOneBook(Book*book)
    {
        cout << "Book: " << book->getTitle() << " was added to the library" << endl;
        this->books.push_back(book);
    }
    // dang ki nguoi muon moi
    void registerOneBorrower(string name)
    {
        BorrowerRecord*borrower = new BorrowerRecord(name);
        this->borrowers.push_back(borrower);
    }
    // liet ke sach ranh
    void displayBooksAvailableForLoan()
    {
        cout << "Book avalable for loan: " << endl;
        for(int i=0; i< books.size(); i++)
        {
            if(books[i]->getBorrower()==NULL)
            {
                books[i]->display();
            }
        }
    }
    void displayBooksOnLoan()
    {
        cout << "Book on loan: " << endl;
        for(int i=0; i<books.size(); i++)
        {
            if(books[i]->getBorrower()!=nullptr)
            {
                cout << books[i]->getBorrower()->getName() << endl;
                books[i]->display();
            }
        }
    }
    void lendOnBook(string number, string name)
    {
        Book* book=nullptr;
        for(int i=0; i< this->books.size(); i++)
        {
            if(this->books[i]->getNumber()==number)
            {
                book= this->books[i];
                break;
            }
        }
        if(book==nullptr)
        {
            cout << "\nBook " << number << " not exists\n";
            return;
        }
        BorrowerRecord* borrower=nullptr;
        for(int i=0; i<this->borrowers.size(); i++)
        {
            if(this->borrowers[i]->getName()==name)
            {
                borrower = this->borrowers[i];
                break;
            }
        }
        if(borrower==nullptr)
        {
            cout << "\nBorrower " << name << " not exists\n";
            return;
        }
        book->attachBorrower(borrower);
        borrower->attachBook(book);
    }
    void returnOnBook(string number)
    {
        bool available= false;
        for(int i=0; i< this->books.size(); i++)
        {
            if(books[i]->getNumber()== number)
            {
                available= true;
                BorrowerRecord * borrower= this->books[i]->getBorrower();
                 cout << "\nBorrower: " << borrower->getName() << 
                        " return book " << books[i]->getNumber() << '\n';
                borrower->detachBook();
                this->books[i]->detachBorrower(borrower);
                break;
            }
        }
        if(!available)
        {
            cout << "\nBook " << number << " not exists\n";;
        }
    }
};

int main()
{
    Book book1("1", "Author", "Qua mon OOP");
    Book book2("2", "Author", "Bi kip OOP");
    Book book3("3", "Author", "Danh bai OOP");

    Library library("HCMUS - Library");
    library.addOneBook(&book1);
    library.addOneBook(&book2);
    library.addOneBook(&book3);
    library.display();
    library.registerOneBorrower("Nguyen Trung Duc");
    library.registerOneBorrower("Alice");
    library.registerOneBorrower("Bob");
    library.lendOneBook("3", "Nguyen Trung Duc");
    library.lendOneBook("1", "Alice");
    library.lendOneBook("2", "Bob");
    library.displayBooksAvailableForLoan();
    library.displayBooksOnLoan();
    library.lendOneBook("1", "Nguyen Trung Duc"); // Should fail (already borrowed)
    library.returnOneBook("1");
    library.lendOneBook("1", "Nguyen Trung Duc");
    library.displayBooksOnLoan();
    library.displayBooksAvailableForLoan();
    library.returnOneBook("1");
    library.displayBooksAvailableForLoan();
    library.lendOneBook("1", "Duc"); // Should fail (borrower not registered)
    return 0;
}