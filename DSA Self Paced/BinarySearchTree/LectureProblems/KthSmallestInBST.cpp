/**
 * @file KthSmallestInBST.cpp
 * @author ADITYA BHARDWAJ
 * @brief Finding the Kth smallest Node key in the self-balancing BST
 * @version 0.1
 * @date 2022-11-11 01:59 AM
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

    int lCount;

    Node(int key)
    {
        this->key = key;
        left=right=NULL;
        lCount=0;
    }

};

Node* BSTInsert(Node *root, int key)
{
    Node *temp = new Node(key);
    //To have the hold of the parent node (Required for iterative approach)
    Node *parent = NULL;
    Node *curr = root;

    while (curr != NULL)
    {
        parent = curr;

        if (curr->key > key)
        {
            curr->lCount++;
            curr = curr->left;
        }
        else if (curr->key < key)
            curr = curr->right;
        else    //if key is already present in the given BST
            return root;
    }

    if (parent == NULL)
        return temp;
    else if (parent->key > key)
        parent->left = temp;
    else
        parent->right = temp;

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    
    inorder(root->left);
    cout << root->key << " ";
    // cout << "Root Key:" << root->key << " Root lCount:" << root->lCount << " " ;
    // cout << endl;

    inorder(root->right);
}

/**
 * @brief 
 *      TIME COMPLEXITY: O(h) (O(logn) for self balancing tree)
 *      AUX SPACE: iterative approach so O(1)
 * 
 * 
 * @param root 
 * @param k 
 * @return Node* 
 */

Node* kthSmallest(Node *root, int k)
{
    // if (root == NULL)
    //     return root;
    
    Node *curr = root;

    while (curr!=NULL)
    {
        if (k == (curr->lCount+1))
            return curr;
        
        else if (k < (curr->lCount+1))
            curr = curr->left;
        
        else if (k > (curr->lCount+1))
        {
            k = k-curr->lCount-1;
            curr = curr->right;
        }

    }

    return root;

}

int main()
{

    Node *root = NULL;
    root = BSTInsert(root, 50);
    root = BSTInsert(root, 20);
    root = BSTInsert(root, 100);
    root = BSTInsert(root, 10);
    root = BSTInsert(root, 40);
    root = BSTInsert(root, 70);
    root = BSTInsert(root, 120);
    root = BSTInsert(root, 4);
    root = BSTInsert(root, 60);
    root = BSTInsert(root, 80);

    inorder(root);

    cout << endl << endl;

    cout << "Kth Smallest: " << endl;

    // Node *curr = kthSmallest(root, 3);
    // Node *curr = kthSmallest(root, 4);
    // Node *curr = kthSmallest(root, 1);
    Node *curr = kthSmallest(root, 7);

    cout << curr->key << endl;

    return 0;
}