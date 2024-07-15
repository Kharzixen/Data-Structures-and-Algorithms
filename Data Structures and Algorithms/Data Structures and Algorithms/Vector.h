#pragma once 

#include <stdexcept>

template <typename T>
class Vector {
public:
    Vector();
    ~Vector();
    void push_back(const T& value);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;
    T* begin(); 
    T* end(); 

private:
    void resize();

    T* data;
    size_t capacity;
    size_t currentSize;
};

template <typename T>
Vector<T>::Vector() : data(nullptr), capacity(0), currentSize(0) {}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (currentSize == capacity) {
        resize();
    }
    data[currentSize++] = value;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {

    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
size_t Vector<T>::size() const {
    return currentSize;
}

template <typename T>
void Vector<T>::resize() {
    size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = new T[newCapacity];

    for (size_t i = 0; i < currentSize; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
T* Vector<T>::begin() {
    return &(this->data[0]);
}

template <typename T>
T* Vector<T>::end() {
    return &(this->data[this->currentSize-1]);
}