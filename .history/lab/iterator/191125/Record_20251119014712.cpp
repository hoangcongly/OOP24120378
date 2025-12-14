#include "SLList.cpp"
#include <cstring>

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
    void setID(int newid) const
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
        copyName(name);
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
        Record *p = findRecord(id);
        if (p == nullptr)
        {
            return false;
        }
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
            os << it->getId() << ":";
            it->print(os);
            os << "\n";
        }
    }
};
