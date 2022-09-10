/**
 * @file MaximumInBinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-10 01:24 PM
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
int maximumInBinaryTree(Node *root)
{
    if (root == NULL)
        return INT_MIN; 
    
    return max(root->key, max(maximumInBinaryTree(root->left), maximumInBinaryTree(root->right)));
}


/*
    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(w) w = width of binary tree (n+1)/2
*/

//Using BFS: Iterative Solution
// int maximumInBinaryTree(Node *root)
// {
//     if (root == NULL)
//         return -1;

//     int res = INT_MIN;

//     queue<Node *> q;
//     q.push(root);

//     while(!q.empty())
//     {
//         Node *node = q.front();
//         q.pop();
//         res = max(res, node->key);

//         if (node->left != NULL)
//             q.push(node->left);
//         if (node->right != NULL)
//             q.push(node->right);
//     }

//     return res;
// }


/*
    If your Binary Tree is skewed means that parents and it childs and so on.. only has one child then Level Order (BFS) will be efficient 
    and if your Binary Tree is almost near to perfect or pure Binary Tree means it will have (n+1)/2 leaves then Recursive Solution (DFS) is efficient.

    This is due to the difference in their Auxiliary Space that different technique requires

    DFS: O(h), so iterative solution is efficient for this when Binary Tree is skewed.
    BFS: O(w), recursive solution is perfect for this when it is near to perfect.
*/

int main()
{
    Node *root = new Node(20);
    root->left = new Node(80);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << maximumInBinaryTree(root) << endl;

    return 0;
}