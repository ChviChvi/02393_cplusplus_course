#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of LimitedBuffer's
//             constructor and methods
LimitedBuffer::LimitedBuffer(unsigned int capacity, int defaultValue)
        : capacity(capacity), defaultValue(defaultValue) {}

//void LimitedBuffer::write(int v) {
//    // Placeholder
//}
//int LimitedBuffer::read() {
//    // Placeholder
//    return defaultValue;
//}
//unsigned int LimitedBuffer::occupancy() {
//    // Placeholder
//    return 0;
//}

// Task 4(b).  Write a working implementation of write() and occupancy()
void LimitedBuffer::write(int v) {
    if (buffer.size() < capacity) {
        // If the buffer is not at full capacity, add the new value
        buffer.push_back(v);
    }
    // If the buffer is full, do nothing (the new value is not added)
}
unsigned int LimitedBuffer::occupancy() {
    // Return the current number of elements in the buffer
    return buffer.size();
}


// Task 4(c).  Write a working implementation of read()
int LimitedBuffer::read() {
    if (buffer.empty()) {
        // If the buffer is empty, return the default value
        return defaultValue;
    } else {
        // Remove and return the oldest value in the buffer (FIFO)
        int oldestValue = buffer.front();
        buffer.erase(buffer.begin());
        return oldestValue;
    }
}


// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
