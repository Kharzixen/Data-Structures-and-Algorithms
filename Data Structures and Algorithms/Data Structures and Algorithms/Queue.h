#pragma once

#include "LinkedList.h"; 

template<typename T>
class Queue {
public:
    Queue();
    ~Queue();
    void enqueue(const T& value);
    void dequeue();
    T front();
    size_t size();
    bool isEmpty();
    void clear();
private:
    linked_list<T> linkedList;
};

template<typename T>
Queue<T>::Queue() {
    this->linkedList = linked_list<T>();
}

template<typename T>
Queue<T>::~Queue() {
    linkedList.~linked_list();
}

template<typename T>
void Queue<T>::enqueue(const T& value) {
    linkedList.append(value);
}

template<typename T>
void Queue<T>::dequeue() {
    linkedList.remove(0);
}

template<typename T>
T Queue<T>::front() {
    return linkedList.get_first();
}

template<typename T>
inline size_t Queue<T>::size()
{
    return linkedList.get_size();
}

template<typename T>
inline bool Queue<T>::isEmpty()
{
    return (linkedList.get_size() == 0);
}

template<typename T>
void Queue<T>::clear() {
    linkedList.clear();
}

