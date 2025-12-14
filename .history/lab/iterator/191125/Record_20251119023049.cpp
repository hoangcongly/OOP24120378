#include "SLList.cpp"
#include <cstring>
#include <fstream>

class Record
{
private:
    SLList<int> _data;
    int _id;

public:
    Record()
    {
        _id = 0;
    }
    Record(const int &id, const int *arr, int n)
    {
        _id = id;
        for (int i = 0; i < n; i++)
        {
            _data.push_back(arr[i]);
        }
    }
    Record(const Record &other)
    {
        _data = other._data;
        _id = other._id;
    }
    ~Record() {}
    Record &operator=(const Record &other)
    {
        if (this != &other)
        {
            _data = other._data;
            _id = other._id;
        }
        return *this;
    }
    int getID() const
    {
        return _id;
    }
    void setID(int newid)
    {
        _id = newid;
    }
    void pushValue(int v)
    {
        _data.push_back(v);
    }
    bool popValue()
    {
        if (_data.empty())
        {
            return false;
        }
        _data.RemoveTail();
        return true;
    }
    bool isEmpty() const
    {
        return _data.empty();
    }

    void print(std::ostream &os = std::cout) const
    {
        os << "[";
        int n = _data.size();
        for (int i = 0; i < n; i++)
        {
            os << _data[i];
            if (i + 1 < n)
                os << ",";
        }
        os << "]";
    }
};

class Table
{
private:
    char *_nameTable;
    SLList<Record> listRecord;

    void copyName(const char *name)
    {
        if (name == nullptr)
        {
            _nameTable = nullptr;
            return;
        }
        delete[] _nameTable;
        _nameTable = new char[strlen(name) + 1];
        strcpy_s(_nameTable, strlen(name) + 1, name);
    }

public:
    Table()
    {
        _nameTable = nullptr;
    }
    Table(const char *name)
    {
        copyName(name);
    }
    Table(const Table &other)
    {
        copyName(other._nameTable);
        listRecord = other.listRecord;
    }
    ~Table()
    {
        delete[] _nameTable;
        _nameTable = nullptr;
    }
    Table &operator=(const Table &other)
    {
        if (this != &other)
        {
            _nameTable = other._nameTable;
            listRecord = other.listRecord;
        }
        return *this;
    }
    const char *getName() const
    {
        return _nameTable;
    }
    Record *findRecord(int id)
    {
        for (auto it = listRecord.begin(); it != listRecord.end(); ++it)
        {
            if (it->getID() == id)
            {
                return &(*it);
            }
        }
        return nullptr;
    }
    const Record *findRecord(int id) const
    {
        for (auto it = listRecord.begin(); it != listRecord.end(); ++it)
        {
            if (it->getID() == id)
            {
                return &(*it);
            }
        }
        return nullptr;
    }
    bool hasRecord(int id) const
    {
        Record *p = findRecord(id);
        if (p == nullptr)
            return false;
        return true;
    }
    bool insertEmptyRecord(int id)
    {
        if (hasRecord(id))
            return false;
        Record rec;
        rec.setID(id);
        listRecord.push_back(rec);
        return true;
    }
    bool insertRecord(int id, const int *arr, int n)
    {
        if (hasRecord(id))
            return false;
        Record rec(id, arr, n);
        listRecord.push_back(rec);
        return true;
    }
    bool deleteRecord(int id)
    {
        for (auto it = listRecord.begin(); it != listRecord.end(); ++it)
        {
            if (it->getID() == id)
            {
                listRecord.remove(it);
                return true;
            }
        }
        return false;
    }
    bool pushValueToRecord(int id, int v)
    {
        Record *p = findRecord(id);
        if (p == nullptr)
        {
            return false;
        }
        p->pushValue(v);
        return true;
    }
    bool popValueFromRecord(int id)
    {
        Record *p = findRecord(id);
        if (p == nullptr)
            return false;
        p->popValue();
        return true;
    }
    void printRecord(int id, std::ostream &os = std::cout) const
    {
        Record *p = findRecord(id);
        if (p == nullptr)
            return;
        p->print(os);
    }
    void printTable(std::ostream &os = std::cout) const
    {
        for (auto it = listRecord.begin(); it != listRecord.end(); ++it)
        {
            os << it->getID() << ":";
            it->print(os);
            os << "\n";
        }
    }
};

class Database
{
private:
    SLList<Table> tables;

public:
    Database() {}
    Table *findTable(const char *name)
    {
        for (auto it = tables.begin(); it != tables.end(); ++it)
        {
            if (strcmp(it->getName(), name) == 0)
            {
                return &(*it);
            }
        }
        return nullptr;
    }

    void CreateTable(const char *name)
    {
        if (findTable(name) != nullptr)
        {
            return;
        }
        tables.push_back(Table(name));
    }

    void DropTable(const char *name)
    {
        for (auto it = tables.begin(); it != tables.end(); ++it)
        {
            if (strcmp(it->getName(), name) == 0)
            {
                tables.remove(it);
                return;
            }
        }
    }

    void processCommand(const char *line)
    {
        char cmd[32];
        std::sscanf(line, "%31s", cmd);
        if (std::strcmp(cmd, "CREATE") == 0)
        {
            char tname[64];
            std::sscanf(line, "CREATE %63s", tname);
            CreateTable(tname);
            return;
        }
        if (std::strcmp(cmd, "DROP") == 0)
        {
            char tname[64];
            std::sscanf(line, "DROP %63s", tname);
            DropTable(tname);
            return;
        }
        if (std::strcmp(cmd, "INSERT") == 0)
        {
            char tname[64];
            int id;
            std::sscanf(line, "INSERT %63s %d", tname, &id);
            Table *t = findTable(tname);
            if (t == nullptr)
                return;
            t->insertEmptyRecord(id);
            return;
        }
        if (std::strcmp(cmd, "PUSH") == 0)
        {
            char tname[64];
            int id, val;
            std::sscanf(line, "PUSH %63s %d %d", tname, &id, &val);
            Table *t = findTable(tname);
            if (t == nullptr)
                return;
            t->pushValueToRecord(id, val);
            return;
        }
        if (std::strcmp(cmd, "POP") == 0)
        {
            char tname[64];
            int id;
            std::sscanf(line, "POP %63s %d", tname, &id);
            Table *t = findTable(tname);
            if (t == nullptr)
                return;
            t->popValueFromRecord(id);
            return;
        }
        if (std::strcmp(cmd, "PRINT") == 0)
        {
            char tname[64];
            int id;
            std::sscanf(line, "PRINT %63s %d", tname, &id);
            Table *t = findTable(tname);
            if (t == nullptr)
            {
                std::cout << "NULL\n";
                return;
            }
            t->printRecord(id);
            return;
        }
        if (std::strcmp(cmd, "PRINT_TABLE") == 0)
        {
            char tname[64];
            std::sscanf(line, "PRINT_TABLE %63s", tname);
            Table *t = findTable(tname);
            if (t == nullptr)
            {
                std::cout << "NULL\n";
                return;
            }
            t->printTable();
            return;
        }
        if (std::strcmp(cmd, "DELETE") == 0)
        {
            char tname[64];
            int id;
            std::sscanf(line, "DELETE %63s %d", tname, &id);
            Table *t = findTable(tname);
            if (!t)
                return;
            t->deleteRecord(id);
            return;
        }
    }
};

int main()
{
    std::ifstream fin("input.txt");
    if (!fin.is_open())
    {
        std::cout << "Khong the mo file input\n";
        return 1;
    }
    Database db;
    char line[256];
    while (fin.getline(line, sizeof(line)))
    {
        if (line[0] == '\0')
            continue;
        db.processCommand(line);
    }
    fin.close();
    return 0;
}