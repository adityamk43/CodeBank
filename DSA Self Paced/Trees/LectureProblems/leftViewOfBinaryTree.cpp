/**
 * @file leftViewOfBinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-10 01:48 PM
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


//METHOD 1
/*
    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(h)
*/
//Using PreOrderT Traversal

// int maxLevel = 0;
// void leftView(Node *root, int level)
// {
//     if (root != nullptr)
//     {
//         if (level > maxLevel)
//         {
//             cout << root->key << " ";
//             maxLevel = level;
//         }
//         leftView(root->left, level + 1);
//         leftView(root->right, level + 1);
//     }
// }

//METHOD 2
/*
    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(w)
*/

//Using Method 2 of Print LevelOrder Traversal Line By Line
void leftView(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        //it is necessary to maintain queue size here in a variable as queue size will change inside the below for loop and it will cause the error in the code
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            Node *node = q.front();
            q.pop();

            if (i==0)
                cout << node->key << " ";

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }

        cout << endl;
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    //DFS
    // leftView(root, 1);
    //BFS
    leftView(root);

    return 0;
}