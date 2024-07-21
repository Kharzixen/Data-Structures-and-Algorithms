#pragma once

#include <cstdlib> 
#include <ctime> 
#include "Stack.h"

template<typename T>
void custom_swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array with random pivot selection
template<typename T>
T* partition(T* low, T* high) {
    // Select a random pivot index between low and high
    T* pivotIndex = low + std::rand() % (high - low + 1);
    // Move the pivot element to the end
    custom_swap(pivotIndex, high);

    T pivot = *high;
    T* i = low - 1;

    for (T* j = low; j <= high - 1; ++j) {
        if (*j <= pivot) {
            ++i;
            custom_swap(i, j);
        }
    }
    custom_swap(i + 1, high);
    return (i + 1);
}

template<typename T>
void quicksort(T* start, T* end) {
    if (start < end) {
        T* p = partition(start, end);
        quicksort(start, p - 1);
        quicksort(p + 1, end);
    }
}

template<typename T> 
void quicksort_iterative(T* start, T* end) {
    if (start >= end) return;

    Stack<T*> stack = Stack<T*>();
    stack.push(start);
    stack.push(end);

    while (!stack.isEmpty()) {
        end = stack.peak();
        stack.pop();
        start = stack.peak();
        stack.pop();

        T* p = partition(start, end);

        if (p - 1 > start) {
            stack.push(start);
            stack.push(p - 1);
        }

        if (p + 1 < end) {
            stack.push(p + 1);
            stack.push(end);
        }
    }
}