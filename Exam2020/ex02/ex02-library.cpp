#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    unsigned int total_length = 0;

    // Traverse the RLE list
    while (list != nullptr) {
        // Add the times value of the current element to the total length
        total_length += list->times;
        // Move to the next element in the list
        list = list->next;
    }

    return total_length;  // Return the total length
}

// Task 2(b).  Implement this function
Elem* append(Elem *list, int v) {
    if (list == nullptr) {
        // If the list is empty, create a new element and return it
        return new Elem{v, 1, nullptr};
    }

    Elem *current = list;
    // Traverse to the end of the list
    while (current->next != nullptr) {
        current = current->next;
    }

    // Check if the last element's value matches the new value
    if (current->value == v) {
        // Increment the times of the last element
        current->times += 1;
    } else {
        // Append a new element to the end of the list
        current->next = new Elem{v, 1, nullptr};
    }

    return list;  // Return the original list

}

// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    Elem *list = nullptr;  // Start with an empty list

    // Iterate through the data array
    for (unsigned int i = 0; i < n; ++i) {
        // Use the append function to add elements to the list
        list = append(list, data[i]);
    }

    return list;  // Return the constructed RLE list
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
