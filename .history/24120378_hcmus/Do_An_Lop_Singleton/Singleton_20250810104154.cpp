#include "Singleton.h"

Singleton *Singleton:: instance=nullptr;
Singleton *Singleton:: getInstance()
{
    if(instance==nullptr)
    {
        instance= new Singleton();
    }
    return instance;
}
void Singleton::showMessage() 
{
    cout << "Hello, I am the only Singleton instance!" << endl;
}
