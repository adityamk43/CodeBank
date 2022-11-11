/**
 * @file CheckBST.cpp
 * @author ADITYA BHARDWAJ
 * @brief check if the given Tree is BST or not
 * @version 0.1
 * @date 2022-11-11 09:45 PM
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
 *        AUX SPACE: O(h) (Since Recursion stack call)
 * 
 * @param root 
 * @param max 
 * @param min 
 * @return true 
 * @return false 
 */


// using between range technique (pre order traversal)
bool checkBST(Node *root, int max, int min)
{
    if (root == NULL)
        return true;

    return (
        min < root->key && 
        max > root->key &&
        checkBST(root->left, root->key, min) &&
        checkBST(root->right, max, root->key) 
    );
    
}

/**
 * @brief TIME COMPLEXITY: O(n)
 *        AUX SPACE: O(h) (Since Recursion stack call)
 * 
 * @param root 
 * @param prevv 
 * @return true 
 * @return false 
 */
//using inorder traversal
//(Binary Tree is BST iff inorder traversal of it is in increasing order)
bool checkBSTInorder(Node* root, int &prevv)
{
    if (root == NULL)
        return true;

    if (checkBSTInorder(root->left, prevv) == false)
        return false;
    
    if (prevv >= root->key)
        return false;

    prevv = root->key;

    return checkBSTInorder(root->right, prevv);
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(18);
    // root->right->left = new Node(25);
    root->right->right = new Node(35);

    inorder(root);

    int max = INT_MAX;
    int min = INT_MIN;
    cout << endl << endl << "Preorder" << endl;

    if (checkBST(root, max, min))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    int prevv = INT_MIN;
    cout << endl << "Inorder" << endl;

    if (checkBSTInorder(root, prevv))
        cout <<  "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}