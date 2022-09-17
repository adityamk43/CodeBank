/**
 * @file InorderTraversal(Iterative).cpp
 * @author ADITYA BHARDWAJ
 * @brief Iterative Method of Inorder Traversal of a Binary Tree
 * @version 0.1
 * @date 2022-09-17 07:42 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <stack>
using namespace std;

//INORDER TRAVERSAL OF BINARY TREE (ITERATIVE) - USING STACK

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

    All Nodes of a Binary Tree are pushed and popped into the stack once which are O(1) operations, so time complexity is O(n)

    AUX SPACE: O(h)

    All left left left nodes are pushed into the stack until the last leftmost node and then popped which we can say that stack can have max node proportional to height of a binary tree, so aux space is O(h)
*/

void inOrderTraversalIterative(Node *root)
{
    if (root == NULL)
        return;
    
    stack<Node*> s;

    Node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr!=NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top(); 
        s.pop();

        cout << curr->key << " ";

        curr = curr->right;

    }

}


int main()
{
    /**
     * @brief 
     *              10
     *             /  \
     *           20   30
     *          /  \
     *        40   50
     */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    inOrderTraversalIterative(root);


    return 0;
}