#include "SLList.cpp"

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

public:
    Table();
    Table(const char *name)
};
