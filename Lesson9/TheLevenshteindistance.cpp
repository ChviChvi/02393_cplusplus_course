//
// Created by Christiaan Vink on 07/11/2023.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int The_levenshtein_Distance(const string& word1, const string& word2) {

    // checking if one of the words has hitted zero letters
    if (word1.empty()) return word2.size();
    if (word2.empty()) return word1.size();

    // finding the cost
    int cost = (word1.front() == word2.front()) ? 0 : 1;

    // Recursively finding out the minimum distance between the words
    // min returns the smallest of the 3 values and continues with that
    return min({
        The_levenshtein_Distance(word1.substr(1), word2) + 1,
        The_levenshtein_Distance(word1, word2.substr(1)) + 1,
        The_levenshtein_Distance(word1.substr(1), word2.substr(1)) + cost
    });
}

int main() {
    cout << "" << endl;

    string word1, word2;
    cin >> word1 >> word2;

    cout << "" << The_levenshtein_Distance(word1, word2) << endl;

    return 0;
}

