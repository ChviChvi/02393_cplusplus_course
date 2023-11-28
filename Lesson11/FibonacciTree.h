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
    std::vector<int> Get_Fib_Preorder();
    int getTree_Size();
    int getTree_Height();
    int Get_Fib_Tree_Leaves();

private:
    Node* Root_Node;
    Node* Making_Fib_Tree(int n);
    void Pre_Order(Node* node, std::vector<int>& result);
    int Counting_AllThe_Nodes(Node* node);
    int Find_Fib_Tree_Height(Node* node);
    int Count_Fib_Tree_Leaves_Nodes(Node* node);
    void slet_tree(Node* node);
};

#endif
