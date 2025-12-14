#include <iostream>
#include <fstream>
#include <cstring>
#include "SLList.h"

using namespace std;

#define MAX_LEN 100

class Document
{
private:
    char *id;
    char *title;
    char *author;
    int year;
    double rating;

public:
    Document()
    {
        id = new char[MAX_LEN];
        strcpy(id, "DEFAULT_ID");
        title = new char[MAX_LEN];
        strcpy(title, "DEFAULT_TITLE");
        author = new char[MAX_LEN];
        strcpy(author, "DEFAULT_AUTHOR");
        year = 0;
        rating = 0.0;
    }

    Document(const char *id_, const char *title_, const char *author_, int year_, double rating_)
    {
        id = new char[MAX_LEN];
        strcpy(id, id_);
        title = new char[MAX_LEN];
        strcpy(title, title_);
        author = new char[MAX_LEN];
        strcpy(author, author_);
        year = year_;
        rating = (rating_ >= 0 && rating_ <= 5) ? rating_ : 0.0;
    }

    Document(const Document &other)
    {
        id = new char[MAX_LEN];
        strcpy(id, other.id);
        title = new char[MAX_LEN];
        strcpy(title, other.title);
        author = new char[MAX_LEN];
        strcpy(author, other.author);
        year = other.year;
        rating = other.rating;
    }

    Document &operator=(const Document &other)
    {
        if (this != &other)
        {
            strcpy(id, other.id);
            strcpy(title, other.title);
            strcpy(author, other.author);
            year = other.year;
            rating = other.rating;
        }
        return *this;
    }

    ~Document()
    {
        delete[] id;
        delete[] title;
        delete[] author;
    }

    const char *getID() const { return id; }
    const char *getTitle() const { return title; }
    const char *getAuthor() const { return author; }
    int getYear() const { return year; }
    double getRating() const { return rating; }

    bool operator<(const Document &other) const
    {
        if (rating != other.rating)
            return rating > other.rating;
        if (year != other.year)
            return year > other.year;
        return strcmp(title, other.title) < 0;
    }

    void print() const
    {
        cout << "[ID:" << id << "] " << title << " | Tác giả: " << author
             << " | " << year << " | Rating: " << rating << "\n";
    }
};

class Category
{
public:
    char *name;
    SLList<char *> docIDs;

    Category(const char *n)
    {
        name = new char[MAX_LEN];
        strcpy(name, n);
    }

    ~Category()
    {
        delete[] name;
    }

    void addDocument(const char *id)
    {
        docIDs.push_back(id);
    }
};

// ============================
// Class Library
// ============================
class Library
{
private:
    SLList<Document> docs;
    SLList<Category> categories;

public:
    void addDocument(const Document &d)
    {
        // nếu trùng ID -> ghi đè
        for (auto node = docs.getHead(); node; node = node->next)
        {
            if (strcmp(node->data.getID(), d.getID()) == 0)
            {
                node->data = d;
                return;
            }
        }
        docs.push_back(d);
    }

    bool removeDocument(const char *id)
    {
        Document *prev = nullptr;
        auto node = docs.getHead();
        while (node)
        {
            if (strcmp(node->data.getID(), id) == 0)
            {
                if (prev)
                    prev->next = node->next;
                else
                    docs.getHead()->data = node->next->data; // head special
                delete node;
                return true;
            }
            prev = &(node->data);
            node = node->next;
        }
        return false;
    }

    Document *findDocument(const char *keyword)
    {
        for (auto node = docs.getHead(); node; node = node->next)
        {
            if (strstr(node->data.getTitle(), keyword) || strstr(node->data.getAuthor(), keyword))
                return &(node->data);
        }
        return nullptr;
    }

    void addCategory(const char *catName, const char *docID)
    {
        for (auto node = categories.getHead(); node; node = node->next)
        {
            if (strcmp(node->data.name, catName) == 0)
            {
                node->data.addDocument(docID);
                return;
            }
        }
        Category c(catName);
        c.addDocument(docID);
        categories.push_back(c);
    }

    void printDocuments()
    {
        for (auto node = docs.getHead(); node; node = node->next)
            node->data.print();
    }

    void readFromFile(const char *filename)
    {
        ifstream fin(filename);
        if (!fin)
        {
            cerr << "Cannot open file\n";
            return;
        }

        char line[500];
        while (fin.getline(line, 500))
        {
            char id[50], title[100], author[100];
            int year;
            double rating;
            // assume format: id,title,author,year,rating
            sscanf(line, "%[^,],%[^,],%[^,],%d,%lf", id, title, author, &year, &rating);
            Document d(id, title, author, year, rating);
            addDocument(d);
        }
        fin.close();
    }
};

// ============================
// Main demo
// ============================
int main()
{
    Library lib;

    // Đọc file
    lib.readFromFile("data.txt");

    cout << "=== Tat ca tai lieu ===\n";
    lib.printDocuments();

    Document *found = lib.findDocument("Nguyen");
    if (found)
    {
        cout << "\nTim thay keyword 'Nguyen':\n";
        found->print();
    }
    else
        cout << "\nKhong tim thay keyword 'Nguyen'\n";

    return 0;
}
