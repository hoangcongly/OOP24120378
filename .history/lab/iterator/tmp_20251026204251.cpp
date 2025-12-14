#include "MyStack.h"
#include <iostream> // Để dùng cerr, endl (thay cho <cstdio>)
#include <cstdlib>  // Để dùng exit, EXIT_FAILURE
#include <cstring>  // Để hỗ trợ kiểu const char* (thay cho <string>)

using namespace std;

// --- ĐỊNH NGHĨA CÁC HÀM CỦA MyStack ---

template <typename T>
void MyStack<T>::clear() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
MyStack<T>::MyStack() : m_top(nullptr), m_size(0) {
    // Constructor mặc định
}

template <typename T>
MyStack<T>::~MyStack() {
    clear();
}

// Copy Constructor
template <typename T>
MyStack<T>::MyStack(const MyStack<T>& other) : m_top(nullptr), m_size(0) {
    MyStack<T> tempStack;
    Node* current = other.m_top;
    while (current != nullptr) {
        tempStack.push(current->data);
        current = current->next;
    }
    while (!tempStack.empty()) {
        this->push(tempStack.top());
        tempStack.pop();
    }
}

// Copy Assignment Operator
template <typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& other) {
    if (this == &other) { 
        return *this;
    }
    clear();
    MyStack<T> tempStack;
    Node* current = other.m_top;
    while (current != nullptr) {
        tempStack.push(current->data);
        current = current->next;
    }
    while (!tempStack.empty()) {
        this->push(tempStack.top());
        tempStack.pop();
    }
    return *this;
}

template <typename T>
void MyStack<T>::push(const T& value) {
    Node* newNode = new Node(value, m_top);
    m_top = newNode;
    m_size++;
}

template <typename T>
void MyStack<T>::pop() {
    if (empty()) {
        return;
    }
    Node* nodeToDelete = m_top;
    m_top = m_top->next;
    delete nodeToDelete;
    m_size--;
}

template <typename T>
T& MyStack<T>::top() {
    if (empty()) {
        // THAY ĐỔI: Dùng cerr từ <iostream> thay vì fprintf từ <cstdio>
        cerr << "Error: Calling top() on an empty stack." << endl;
        exit(EXIT_FAILURE); 
    }
    return m_top->data;
}

template <typename T>
const T& MyStack<T>::top() const {
    if (empty()) {
        // THAY ĐỔI: Dùng cerr từ <iostream> thay vì fprintf từ <cstdio>
        cerr << "Error: Calling top() on an empty stack." << endl;
        exit(EXIT_FAILURE);
    }
    return m_top->data;
}

template <typename T>
bool MyStack<T>::empty() const {
    return m_top == nullptr;
}

template <typename T>
unsigned long MyStack<T>::size() const {
    return m_size;
}

template <typename T>
typename MyStack<T>::Iterator MyStack<T>::begin() {
    return Iterator(m_top);
}

template <typename T>
typename MyStack<T>::Iterator MyStack<T>::end() {
    return Iterator(nullptr);
}


// --- BIÊN DỊCH TƯỜNG MINH (EXPLICIT INSTANTIATION) ---

template class MyStack<int>;
template class MyStack<double>;
// THAY ĐỔI: Bỏ 'string', thay bằng 'const char*' (vì <cstring> được phép)
template class MyStack<const char*>;