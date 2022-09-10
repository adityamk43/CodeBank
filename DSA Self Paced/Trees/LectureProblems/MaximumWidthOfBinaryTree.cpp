/**
 * @file MaximumWidthOfBinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-10 06:33 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

struct Node
{

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
    AUXILIARY SPACE: ⊝(w) or O(n)   w = width of binary tree ((n+1)/2)
*/

int maxWidthOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;

    queue<Node *> q;
    q.push(root);

    int res = 0;

    while (!q.empty())
    {
        //it is necessary to maintain queue size here in a variable as queue size will change inside the below for loop and it will cause the error in the code
        int count = q.size();
        res = max(res, count);

        for (int i = 0; i < count; i++)
        {
            Node *node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
    }

    return res;
}

int main()
{
    // Node *root = new Node(10);
    // root->left = new Node(80);
    // root->left->right = new Node(70);
    
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    cout << maxWidthOfBinaryTree(root) << endl;

    return 0;
}