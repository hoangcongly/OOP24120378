#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Logger
{
private:
    vector<string> messages;
    Logger()
    {
        cout << "[system] Logger khoi tao lan dau tien\n";
    }

public:
};