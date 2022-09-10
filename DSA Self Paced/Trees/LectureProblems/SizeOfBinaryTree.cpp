/**
 * @file SizeOfBinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-10 01:16 PM
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
    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(h) h = height of binary tree (h+1)
*/


//Using DFS: Recursive Solution 
// int sizeOfBinaryTree(Node *root)
// {
//     if (root == NULL)
//         return 0; 
    
//     return 1 + sizeOfBinaryTree(root->left) + sizeOfBinaryTree(root->right);
// }


/*
    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(w) w = width of binary tree (n+1)/2
*/

//Using BFS: Iterative Solution
int sizeOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;

    int size = 0;
    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node *node = q.front();
        q.pop();
        size++;

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }

    return size;
}



int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    cout << sizeOfBinaryTree(root) << endl;

    return 0;
}