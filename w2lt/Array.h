#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

class Array {
private:
    int* data;  
    int size;   

public:
    Array();                            
    Array(int length);                  
    Array(int arr[], int length);       
    Array(const Array& other);          
    ~Array();                           
    
    void input();                                   
    void output() const;                            
    int getSize() const;                            
    void setSize(int newSize);                      
    int getElement(int index) const;                
    void setElement(int index, int value);          
    int find(int value) const;                      
    void sort(bool ascending = true);               
};

#endif // ARRAY_H