/**
 * @file BinaryTreeToDLL.cpp
 * @author ADITYA BHARDWAJ
 * @brief CONVERTING TREE TO DOUBLY LINKED LIST (Concept of Preorder Traversal)
 * @version 0.1
 * @date 2022-09-10 06:42 PM
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
    AUXILIARY SPACE: ⊝(h)   h = height of binary tree (h+1)
*/

/**
 * @brief DOUBLY LINKED HAS POINTERS AS NEXT AND PREVIOUS
 * AND BINARY TREE HAS REFERENCES AS LEFT AND RIGHT
 * 
 * SO, IT WILL BE EASY TO CONVERT FROM TREE TO DLL AS WE CAN USE LEFT AND RIGHT OF TREE AS PREVIOUS AND NEXT FOR DLL
 * 
 */

//We are simply doing inOrder Traversal to construct Doubly linked List from Binary tree
//This is for maintaining head pointer for DLL
Node *previous = NULL;
Node *BTToDLL(Node *root)
{
    //base case to return NULL if root is null
    if (root == NULL)
        return root;
    
    //stores head Node which should be return to parent call
    Node* head = BTToDLL(root->left);

    //this condition will be true for very first left node, which will eventually be the first node in DLL and previous pointer will store address of this node as this will be the first node
    if (previous == NULL)
        head = root;
    //this condition will run for all nodes except first node obviously, here we will transform left child of tree as left pointer for DLL and reference it to previous node that will come in preorder traversal and previous node to reference this/present node.
    else
    {
        root->left = previous;
        previous->right = root;
    }

    //now we will make this node as previous node as its work has completed, so that we can work with new node and connect to this node.
    previous = root;

    BTToDLL(root->right);

    //this will return first node to all recursive function which will eventually return head node to main driver call so that we can print DLL.
    return head;

}


int main()
{
    //EXAMPLE 1
    // Node *root = new Node(10);
    // root->left = new Node(80);
    // root->left->left = new Node(70);
    
    //EXAMPLE 2
    // Node *root = new Node(5);
    // root->left = new Node(8);
    // root->right = new Node(19);
    // root->right->left = new Node(6);

    //EXAMPLE 3
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(35);

    Node *head = BTToDLL(root);

    //Tree to DoublyLinkedList Printing
    cout << "Doubly Linked List Constructed from Binary Tree using PreOrder Traversal: " << endl;
    Node *temp = head;
    while (temp!=NULL)
    {
        cout << temp->key << " ";
        temp = temp->right;
    }

    return 0;
}