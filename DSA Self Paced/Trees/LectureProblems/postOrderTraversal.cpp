/**
 * @file postOrderTraversal.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-07 10:32 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
using namespace std;

//POSTORDER TRAVERSAL OF BINARY TREE

struct Node{

    int key;
    struct Node *left;
    struct Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }

};

void postOrderTraversal(Node *root)
{
    if (root != nullptr)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->key << " ";
    }
}

int main()
{
    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->left->left = new Node(40);

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    postOrderTraversal(root);


    return 0;
}