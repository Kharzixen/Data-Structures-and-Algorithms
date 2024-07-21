#include "Algorithm.h"
#include <iostream>
#include "Queue.h"

int main() {
    const int n = 15; 
    int arr[n] = { 3, 9, 14, 1, 7, 5, 10, 2, 6, 11, 15, 13,12, 4, 8 };
    quicksort_iterative(&arr[0], &arr[n-1]); 

    std::cout << std::endl; 
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    
    return 0;
}