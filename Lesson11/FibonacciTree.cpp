//
// Created by Christiaan Vink on 21/11/2023.
//

#include "FibonacciTree.h"
#include <iostream>

struct Node {
    int fibValue;
    Node* leftChild;
    Node* rightChild;

    Node(int val) : fibValue(val), leftChild(nullptr), rightChild(nullptr) {}
};

FibonacciTree::FibonacciTree(int n) {
    rootNode = makeTree(n);
}


FibonacciTree::~FibonacciTree() {
    deleteTree(rootNode);
}

std::vector<int> FibonacciTree::getFibonacciPreOrder() {
    std::vector<int> traversalResult;
    doPreOrder(rootNode, traversalResult);
    return traversalResult;
}

int FibonacciTree::getTreeSize() {
    return countAllNodes(rootNode);
}

int FibonacciTree::getTreeHeight() {
    return findTreeHeight(rootNode);
}

int FibonacciTree::getLeafNodesCount() {
    return countLeafNodes(rootNode);
}


Node* FibonacciTree::makeTree(int n) {
    if (n <= 1) return new Node(1);  // Base case: Fibonacci of 0 and 1 is 1
    Node* newNode = new Node(-1);    // Temporary value, will be updated later
    newNode->leftChild = makeTree(n - 1);
    newNode->rightChild = makeTree(n - 2);
    newNode->fibValue = newNode->leftChild->fibValue + newNode->rightChild->fibValue;
    return newNode;
}

void FibonacciTree::doPreOrder(Node* node, std::vector<int>& result) {
    if (!node) return;
    result.push_back(node->fibValue);
    doPreOrder(node->leftChild, result);
    doPreOrder(node->rightChild, result);
}

int FibonacciTree::countAllNodes(Node* node) {
    if (!node) return 0;
    return 1 + countAllNodes(node->leftChild) + countAllNodes(node->rightChild);
}

int FibonacciTree::findTreeHeight(Node* node) {
    if (!node) return 0;
    return 1 + std::max(findTreeHeight(node->leftChild), findTreeHeight(node->rightChild));
}

int FibonacciTree::countLeafNodes(Node* node) {
    if (!node) return 0;
    if (!node->leftChild && !node->rightChild) return 1;
    return countLeafNodes(node->leftChild) + countLeafNodes(node->rightChild);
}

void FibonacciTree::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->leftChild);
        deleteTree(node->rightChild);
        delete node;
    }
}

int main() {
    int n;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> n;

    FibonacciTree fibTree(n);
    std::vector<int> preOrder = fibTree.getFibonacciPreOrder();

    std::cout << "Tree in pre-order:";
    for (int val : preOrder) {
        std::cout << " " << val;
    }
    std::cout << "\nTree size: " << fibTree.getTreeSize();
    std::cout << "\nTree height: " << fibTree.getTreeHeight();
    std::cout << "\nLeaf nodes: " << fibTree.getLeafNodesCount();

    return 0;
}
