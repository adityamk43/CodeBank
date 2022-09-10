/**
 * @file ChildrenSumProperty.cpp
 * @author ADITYA BHARDWAJ
 * @brief SUM OF KEYS OF CHILD NODES SHOULD BE EQUAL TO KEY OF ROOT NODE, THEN CHILDREN SUM PROPERTY HOLDS TRUE
 * @version 0.1
 * @date 2022-09-10 06:01 PM
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
    AUXILIARY SPACE: O(h)
*/
bool isChildSum(Node* root)
{
    //NULL will always be true
    if (root == NULL)
        return true;
    
    //Important corner case that is necessary for leaf node cases
    //As leaf nodes should return true
    if (root->left == NULL && root->right == NULL)
        return true;

    int sum = 0;

    //if node has either left child or right child then these conditions solve those problems
    if (root->left!=NULL) 
        sum += root->left->key;

    if (root->right!=NULL) 
        sum += root->right->key;

    //if all these three conditions are true then function send true to its parents call
    //As if root's child node has it child sum not equal to its key value then whole tree should return false to the main driver function
    return  root->key == sum && isChildSum(root->left) && isChildSum(root->right);

}


int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(3);
    root->right->right = new Node(9);

    if (isChildSum(root))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}