#include "Vector.h"
#include "Algorithm.h"
#include "LinkedList.h"
#include <iostream>

int main() {
    linked_list<int> linkedList;

    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);

    linkedList.insert(5, 1);
    linkedList.print();
    linkedList.remove(1);
    std::cout << std::endl;
    linkedList.print();


    int arr[5] = { 10, 30, 20, 50, 40 };
    quicksort(&arr[0], &arr[4]); 

    std::cout << std::endl; 
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }


    return 0;
}