/**
 * @file BinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-07 10:20 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

//Binary Tree through class

// class Node{

//     public:
//     int key;
//     Node *left;
//     Node *right;

//     Node(int key)
//     {
//         this->key = key;
//     }

// };

//Binary Tree through struct

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

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);


    return 0;
}