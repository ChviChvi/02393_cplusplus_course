//
// Created by Christiaan Vink on 07/11/2023.
//
#include <iostream>
#include <vector>
using namespace std;

void readAndReverse(vector<int>& nums) {
    int num;
    while (cin >> num) { // Read numbers until newline or EOF
        nums.push_back(num);
    }
}

void printReverse(const vector<int>& nums, int index) {
    if (index < 0) return; // Base case
    cout << nums[index] << " "; // Print the current number
    printReverse(nums, index - 1); // Recursive call
}

int main() {
    vector<int> nums;
    cout << "Enter a sequence of numbers followed by a non-numeric character (e.g., 'x') to end input: ";
    readAndReverse(nums); // Read and store numbers
    printReverse(nums, nums.size() - 1); // Print in reverse
    cout << endl; // Print a newline at the end
    return 0;
}

