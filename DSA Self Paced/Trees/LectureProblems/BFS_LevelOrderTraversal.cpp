/**
 * @file BFS_LevelOrderTraversal.cpp
 * @author yADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-09 11:24 AM
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
    Inefficient way could be that we could have used functions of finding height of the tree and print Nodes at K Distance.

    First we call heightOfTheTree function to get the height of the Binary Tree which will take O(n) time.

    Then, in another function we run a loop till height of tree inside of which we will call printNodesAtK Distance, which will do level order printing of nodes. This will take O(h*n) time.

    So Overall time Complexity will become O(n + n*h) = O(n*h)

    We have done the level order traversal in O(n) time using queue below which is a efficient approach!!

*/

/*
    TIME COMPLEXITY: ⊝(n)
    AUXILIARY SPACE: ⊝(w) or O(n)   w = max width of binary tree ((n+1)/2)
                    ⊝(1) when tree is skewed structured like tree root and its child has only left nodes and right nodes are null or vice versa
                    ⊝(n) when it is a pure/perfect Binary tree. Eg: when tree has 15 nodes then its leaves will be (15+1)/2 = 8
*/

void levelOrderTraversalBFS(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node *node = q.front();
        q.pop();
        cout << node->key << " ";

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }

}

int main()
{    
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(7);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(15);

    levelOrderTraversalBFS(root);

    return 0;
}