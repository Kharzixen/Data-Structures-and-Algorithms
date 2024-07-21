#pragma once

#include "LinkedList.h"; 

template<typename T>
class Stack {
public:
    Stack();
    ~Stack();
    void push(const T& value);
    void pop(); 
    T peak(); 
    size_t size();
    bool isEmpty(); 
    void clear(); 
private:
    linked_list<T> linkedList;
};

template<typename T>
Stack<T>::Stack() {
    this->linkedList = linked_list<T>();
}

template<typename T>
Stack<T>::~Stack() {
    linkedList.~linked_list(); 
}

template<typename T>
void Stack<T>::push(const T& value) {
    linkedList.prepend(value); 
}

template<typename T>
void Stack<T>::pop() {
    linkedList.remove(0); 
}

template<typename T>
T Stack<T>::peak() {
    return linkedList.get_first(); 
}

template<typename T>
inline size_t Stack<T>::size()
{
    return linkedList.get_size();
}

template<typename T>
inline bool Stack<T>::isEmpty()
{
    return (linkedList.get_size() == 0);
}

template<typename T>
void Stack<T>::clear() {
    linkedList.clear(); 
}

