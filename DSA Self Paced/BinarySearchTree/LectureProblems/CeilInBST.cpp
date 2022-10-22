/**
 * @file CeilInBST.cpp
 * @author ADITYA BHARDWAJ
 * @brief Ceil In BST
 * @version 0.1
 * @date 2022-10-23 12:15 AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int key;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

void preorder(Node *root)
{
    if (root == NULL)
        return;
    
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

/*
    TIME COMPLEXITY: O(h)
    S.C. / Aux Space: O(h)
*/
void ceilBST(Node *root, int ceil_value, Node *&curr_val)
{
    if (root == NULL)
        return;

    if (root->key == ceil_value)
    {
        curr_val = root;
        return;
    }

    else if (ceil_value > root->key)
        ceilBST(root->right, ceil_value, curr_val);

    else if (ceil_value < root->key)
    {
        curr_val = root;
        ceilBST(root->left, ceil_value, curr_val);
    }
    
}


/*
    EFFICIENT SOLUTION:

    TIME COMPLEXITY: O(h)
    S.C. / Aux Space: O(1)
*/
Node* iterativeCeilBST(Node *root, int ceil_value)
{
    Node *res = NULL;
    Node *curr = root;

    while(curr!= NULL)
    {
        if (curr->key == ceil_value)
            return curr;

        else if (ceil_value > curr->key)
            curr = curr->right;

        else if (ceil_value < curr->key)
        {
            res = curr;
            curr = curr->left;
        }
    }

    return res;
}

int main()
{
    /**
     * @brief 
     *          eg: ceil_value = 25
     *  
     *                         50
     *                       /    \
     *                     30     70
     *                    / \    /  \
     *                  20  40  60   80
     *                        /  \
     *                      55   65
     */

    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    root->right->left->left = new Node(55);
    root->right->left->right = new Node(65);

    // preorder(root);

    Node *curr_value = NULL;
    int ceil_value = 25;
    // int ceil_value = 58;
    // int ceil_value = 100;
    // int ceil_value = 15;
    // int ceil_value = 70;

    //Recursive Soln.
    ceilBST(root, ceil_value, curr_value);

    cout << "Recursive: ";

    if (curr_value!=NULL)
        cout << curr_value->key << endl;
    else
        cout << "No Ceil Value Exists" << endl;
    

    //EFFICIENT SOLUTION:
    //Iterative Soln.
    Node *res = iterativeCeilBST(root, ceil_value);
    cout << "Iterative: ";
    if (res!=NULL)
        cout << res->key << endl;
    else
        cout << "No Ceil Value Exists" << endl;
    
    return 0;
}