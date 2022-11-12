/**
 * @file LCABST.cpp
 * @author ADITYA BHARDWAJ
 * @brief Finding Least Common Ancestor in a Binary Search Tree
 * @version 0.1
 * @date 2022-11-13 02:34 AM
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

    Node(int key)
    {
        this->key = key;
        left=right=NULL;
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

Node* lcaBST(Node *root, int n1, int n2)
{   
    Node *curr = root;

    while (curr!=NULL)
    {
        if (curr->key > n1 && curr->key > n2)
            curr = curr->left;
        else if (curr->key < n1 && curr->key < n2)
            curr = curr->right;
        else
            break;
    }

    return curr;
}

int main()
{

    //Example 1
    /**
     * @brief 
     * 
     *           20
     *         /   \
     *        8    22
     *      /  \  
     *     4   12 
     *        /  \
     *      10   14
     * 
     */
    Node *root = new Node(20);
    root->left = new Node(8); 
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);


    inorder(root);

    int n1 = 10, n2 = 14; //LCA = 12
    // int n1 = 14, n2 = 8; //LCA = 8
    // int n1 = 10, n2 = 22; //LCA = 20
    cout << endl;
    cout << endl << "LCA: " << endl;
    Node *lcaNode = lcaBST(root, n1, n2);
    cout << lcaNode->key << endl;

    return 0;
}