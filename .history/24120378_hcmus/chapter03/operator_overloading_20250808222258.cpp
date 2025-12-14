#include <iostream>
using namespace std;

class Array{
private:
    int *a;
    int size;
public:
    Array(int s=0)
    {
        size=s;
        if(size>0)
        {
            a= new int[size];
        }
        else a= nullptr;
    }

    ~Array() 
    {
        delete[] a;
    }
    Array& operator=(const Array&src)
    {
        if(this!=&src)
        {
            delete[] a;
            size= src.size;
            a= new int[size];
            for(int i=0; i<size; i++)
            {
                a[i]= src.a[i];
            }
        }
        return *this;
    }
    void Set(int*arr, int s)
    {
        delete[] a;
        size=s;
        a= new int[size];
        for(int i=0; i<size; i++)
        {
            a[i]= arr[i];
        }
    }
    void display()
    {
        for(int i=0; i<size; i++)
        {
            cout << a[i] << "\t";
        }
        cout << endl;
    }
};
int main()
{
    int data[]= {1,2,3,4,5,6,1,23,6,12,2,1,5,3};
    Array a1;
    a1.Set(data,14);
    cout << "a1: " ;
    a1.display();
    Array a2;
    a2=a1;  
    cout << "a2: ";
    a2.display();

    return 0;
}