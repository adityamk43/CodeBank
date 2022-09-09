/**
 * @file PrintNodesAtKDistance.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-09 11:48 AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

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

/*
    TIME COMPLEXITY: ⊝(n)
    AUXILIARY SPACE: ⊝(h) h = max height of tree (h+1)
*/

void printNodeAtKDistance(Node *root, int k)
{
    if (k==0)
    {
        cout << root->key << " ";
        return;
    }

    printNodeAtKDistance(root->left, k-1);
    printNodeAtKDistance(root->right, k-1);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(70);
    root->right->left->left = new Node(80);

    int k = 2;
    printNodeAtKDistance(root, k);

    return 0;
}