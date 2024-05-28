#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
void shift(Passenger *q, unsigned int n) {
    // Iterate through the queue
    Passenger *current = q;
    while (current != nullptr) {
        // Modify the row of each passenger
        current->row += n;
        // Move to the next passenger
        current = current->next;
    }
}

// Task 2(b).  Implement this function
Passenger* find(Passenger *q, unsigned int rowMin,
                unsigned int rowMax) {
    Passenger *head = nullptr; // Head of the new queue
    Passenger *tail = nullptr; // Tail of the new queue

    Passenger *current = q;
    while (current != nullptr) {
        if (current->row >= rowMin && current->row <= rowMax) {
            // Create a new dynamically-allocated copy of the current passenger
            Passenger *newPassenger = new Passenger;
            newPassenger->name = current->name;
            newPassenger->ticket = current->ticket;
            newPassenger->row = current->row;
            newPassenger->seat = current->seat;
            newPassenger->next = nullptr;

            if (head == nullptr) {
                // This is the first passenger in the new queue
                head = newPassenger;
                tail = newPassenger;
            } else {
                // Append to the new queue
                tail->next = newPassenger;
                tail = newPassenger;
            }
        }
        current = current->next;
    }

    return head; // Return the head of the new queue

}

// Task 2(c).  Implement this function
bool occupied(Passenger *q, unsigned int row, char seat) {
    // Replace the following with your code

    //Passenger *que = find(q,row,row);
    while (q != nullptr) {
        if(q->row == row && q->seat == seat){
            return true;
        }
        q = q->next;
    }

    return false;
}

// Do not modify
void displayQueue(Passenger *q) {
    if (q == nullptr) {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    cout << ", seat " << q->row << q->seat << endl;
    displayQueue(q->next);
}
