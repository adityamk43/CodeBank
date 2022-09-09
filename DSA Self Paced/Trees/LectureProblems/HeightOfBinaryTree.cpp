/**
 * @file HeightOfBinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-09 11:38 AM
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

int heightOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0; 
    
    return 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << heightOfBinaryTree(root) << endl;

    return 0;
}