/**
 * @file FixABSTTwoNodesSwapped.cpp
 * @author ADITYA BHARDWAJ
 * @brief Fix a BST with two Nodes swapped
 * @version 0.1
 * @date 2022-11-11 10:23 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int k)
    {
        this->key = k;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

/**
 * @brief TIME COMPLEXITY: O(n)
 *        AUX SPACE: O(h)
 * @param root 
 * @param first 
 * @param second 
 * @param prev 
 */
//idea is simply use the previous technique of checkBST using inorderTraversal
void fixBST(Node *root, Node* &first, Node* &second, Node* &prev)
{
    if (root == NULL)
        return;
    
    fixBST(root->left, first, second, prev);

    if (prev!=NULL && root->key < prev->key)
    {
        if (first == NULL)
            first = prev;
        second = root;
    }

    prev = root;

    fixBST(root->right, first, second, prev);


    
}

int main()
{

    Node *root = new Node(20);
    root->left = new Node(60); // 1st node to be swapped
    root->right = new Node(80);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->right->left = new Node(8); //2nd Node to be swapped
    root->right->right = new Node(100);

    inorder(root);

    Node* prev = NULL;
    Node* first = NULL;
    Node* second = NULL;

    fixBST(root, first, second, prev);

    cout << endl << first->key;
    cout << endl << second->key;

    return 0;
}