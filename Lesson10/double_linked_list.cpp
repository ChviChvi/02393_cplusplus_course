//
// Created by Christiaan Vink on 21/11/2023.
//

#include "double_linked_list.h"



// initialize the new List object
List::List() {
    first = nullptr;
}

// Destructor! - cleaning up when List object is destroyed
//               so there is no memory leaks
List::~List() {
    Node *current_node = first;
    while (current_node != nullptr) {
        Node *next = current_node->next;
        delete current_node;
        current_node = next;
    }
}

// Inserter! - Creates new node and inserts it at the end with value n,
//             if the list is empty the new node becomes the first
//             else it puts it at the end
void List::insert(int n) {
    Node *new_node = new Node;
    new_node->val = n;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (first == nullptr) {
        first = new_node;
    } else {
        Node *current_node = first;
        while (current_node->next != nullptr) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
        new_node->prev = current_node;
    }
}

// Reverse! - iterating through the list swapping each next and pres pointer
//            it also updates the first pointer to point to the new first node of
//            the reverse list
void List::reverse() {
    Node *temp_node = nullptr;
    Node *current_node = first;

    while (current_node != nullptr) {
        temp_node = current_node->prev;
        current_node->prev = current_node->next;
        current_node->next = temp_node;
        current_node = current_node->prev;
    }

    if (temp_node != nullptr) {
        first = temp_node->prev;
    }
}

// Printer - keeps printing nodes until it hits the nullpointer
void List::print() {
    Node *current_node = first;
    while (current_node != nullptr) {
        cout << current_node->val << " ";
        current_node = current_node->next;
    }
    cout << endl;
}
