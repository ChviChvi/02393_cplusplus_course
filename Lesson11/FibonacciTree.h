//
// Created by Christiaan Vink on 21/11/2023.
//

// FibonacciTree.h
#ifndef FIBONACCITREE_H
#define FIBONACCITREE_H

#include <vector>

struct Node;

class FibonacciTree {
public:
    FibonacciTree(int n);
    ~FibonacciTree();
    std::vector<int> getFibonacciPreOrder();
    int getTreeSize();
    int getTreeHeight();
    int getLeafNodesCount();

private:
    Node* rootNode;
    Node* makeTree(int n);
    void doPreOrder(Node* node, std::vector<int>& result);
    int countAllNodes(Node* node);
    int findTreeHeight(Node* node);
    int countLeafNodes(Node* node);
    void deleteTree(Node* node);
};

#endif // FIBONACCITREE_H
