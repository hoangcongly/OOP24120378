#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Logger
{
private:
    vector<string> messages;
    static Logger *instance;
    Logger()
    {
        cout << "[system] Logger khoi tao lan dau tien\n";
    }

public:
    Logger(const Logger &) = delete;
    void operator=(const Logger &) = delete;
    static Logger *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Logger();
        }
        return instance;
    }
    void write(const string &msg)
    {
        messages.push_back(msg);
    }
    void print() const
    {
        for (auto m : messages)
        {
            cout << m << endl;
        }
    }
};

Logger *Logger::instance = nullptr;
int main()
{
    Logger *log = Logger::getInstance();
    log->write("001 cai dit me cmay");
    log->write("002 doi a bac qua");
    log->print();
    return 0;
}