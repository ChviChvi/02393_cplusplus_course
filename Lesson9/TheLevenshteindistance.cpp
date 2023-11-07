//
// Created by Christiaan Vink on 07/11/2023.
//
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int levenshteinDistance(const string& u, const string& v) {
    if (u.empty()) return v.length(); // Base cases
    if (v.empty()) return u.length();

    int cost = (u.front() == v.front()) ? 0 : 1; // Cost of substitution

    // Recursive calls for delete, insert, and substitute
    int del = levenshteinDistance(u.substr(1), v) + 1;
    int ins = levenshteinDistance(u, v.substr(1)) + 1;
    int sub = levenshteinDistance(u.substr(1), v.substr(1)) + cost;

    // Return the minimum of the three
    return min({del, ins, sub});
}

int main() {
    string u, v;
    cin >> u >> v; // Read two words
    cout << levenshteinDistance(u, v); // Calculate and output the distance
    return 0;
}
