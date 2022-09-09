/**
 * @file LevelOrderTraversalLineByLine.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * @version 0.1
 * @date 2022-09-09 12:00 PM
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
    AUXILIARY SPACE: ⊝(w) or O(n)   w = max width of tree ((n+1)/2)
                    ⊝(1) when tree is queued structured like tree root and its child has only left nodes and right nodes are null
                    ⊝(n) when it is a pure/perfect Binary tree. Eg: when tree has 15 nodes then its leaves will be (15+1)/2 = 8
*/

// METHOD 1 USING NULL PUSHING TECHNIQUE IN QUEUE
//  void levelOrderTraversalBFSLineByLine(Node *root)
//  {
//      if (root == NULL)
//          return;

//     queue<Node *> q;
//     q.push(root);
//     q.push(NULL);

//     while(q.size() > 1)
//     {
//         Node *node = q.front();
//         q.pop();

//         if (node == NULL)
//         {
//             cout << endl;
//             q.push(NULL);
//             continue;
//         }

//         cout << node->key << " ";

//         if (node->left != NULL)
//             q.push(node->left);
//         if (node->right != NULL)
//             q.push(node->right);
//     }

// }

// METHOD 2 MAINTAINING SIZE OF QUEUE TO PRINT NODES ACCORDING TO BREADTH
void levelOrderTraversalBFSLineByLine(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            Node *node = q.front();
            q.pop();

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
    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->right->left = new Node(6);
    // root->left->left = new Node(8);
    // root->left->right = new Node(7);
    // root->left->right->left = new Node(3);
    // root->left->right->right = new Node(15);

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    levelOrderTraversalBFSLineByLine(root);

    return 0;
}