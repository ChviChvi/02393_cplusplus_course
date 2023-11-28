//
// Created by Christiaan Vink on 21/11/2023.
//


#include <iostream>


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

//structure for defining the fib node
struct Node {
    int Fibonacci_Vallue;
    Node* Left_Child;
    Node* Right_Child;

    Node(int val) : Fibonacci_Vallue(val), Left_Child(nullptr), Right_Child(nullptr) {}
};

// takes int - n and creates a fib tree of n levels
FibonacciTree::FibonacciTree(int n) {
    Root_Node = Making_Fib_Tree(n);
}

// delocating memmoery
FibonacciTree::~FibonacciTree() {
    slet_tree(Root_Node);
}

// returns how the tree was visited by doing preorder
std::vector<int> FibonacciTree::Get_Fib_Preorder() {
    std::vector<int> ResultAfterTraversing;
    Pre_Order(Root_Node, ResultAfterTraversing);
    return ResultAfterTraversing;
}

int FibonacciTree::getTree_Size() {
    return Counting_AllThe_Nodes(Root_Node);
}

int FibonacciTree::getTree_Height() {
    return Find_Fib_Tree_Height(Root_Node);
}

// counts the leaves ( aka. nodes w/o children) in the tree
int FibonacciTree::Get_Fib_Tree_Leaves() {
    return Count_Fib_Tree_Leaves_Nodes(Root_Node);
}

// here we use recursion, it for n <=1, it returns a  node with value of 1, for a larger n it creates a new node
// with the value being the sum of the value left and right of the child, which are the fub tree zie, n-1 and n-2 :)
Node* FibonacciTree::Making_Fib_Tree(int n) {
    if (n <= 1) return new Node(1);  // Base case: Fibonacci of 0 and 1 is 1
    Node* New_Node = new Node(-1);    // Temporary value, will be updated later
    New_Node->Left_Child = Making_Fib_Tree(n - 1);
    New_Node->Right_Child = Making_Fib_Tree(n - 2);
    New_Node->Fibonacci_Vallue = New_Node->Left_Child->Fibonacci_Vallue + New_Node->Right_Child->Fibonacci_Vallue;
    return New_Node;
}

// recursivly doing a preordder ( so first visit node, then left subtree and then right subtree
void FibonacciTree::Pre_Order(Node* node, std::vector<int>& result) {
    if (!node) return;
    result.push_back(node->Fibonacci_Vallue);
    Pre_Order(node->Left_Child, result);
    Pre_Order(node->Right_Child, result);
}

// recursively counts the tree nodes
int FibonacciTree::Counting_AllThe_Nodes(Node* node) {
    if (!node) return 0;
    return 1 + Counting_AllThe_Nodes(node->Left_Child) + Counting_AllThe_Nodes(node->Right_Child);
}

// recursively counts the tree height
int FibonacciTree::Find_Fib_Tree_Height(Node* node) {
    if (!node) return 0;
    return 1 + std::max(Find_Fib_Tree_Height(node->Left_Child), Find_Fib_Tree_Height(node->Right_Child));
}

// recursively counts the tree leave nodes
int FibonacciTree::Count_Fib_Tree_Leaves_Nodes(Node* node) {
    if (!node) return 0;
    if (!node->Left_Child && !node->Right_Child) return 1;
    return Count_Fib_Tree_Leaves_Nodes(node->Left_Child) + Count_Fib_Tree_Leaves_Nodes(node->Right_Child);
}

// removes allll the nodes in trhe tree recursivly
void FibonacciTree::slet_tree(Node* node) {
    if (node) {
        slet_tree(node->Left_Child);
        slet_tree(node->Right_Child);
        delete node;
    }
}

int main() {
    int n;
    std::cout << "";
    std::cin >> n;

    FibonacciTree fibTree(n);
    std::vector<int> preOrder = fibTree.Get_Fib_Preorder();

    std::cout << "Call tree in pre-order:";
    for (int val : preOrder) {
        std::cout << " " << val;
    }
    std::cout << "\nCall tree size: " << fibTree.getTree_Size();
    std::cout << "\nCall tree depth: " << fibTree.getTree_Height();
    std::cout << "\nCall tree leafs: " << fibTree.Get_Fib_Tree_Leaves();

    return 0;
}
