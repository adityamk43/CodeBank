/**
 * @file FloorInBST.cpp
 * @author ADITYA BHARDWAJ
 * @brief Floor in BST
 * @version 0.1
 * @date 2022-10-22 11:03 PM
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
void floorBST(Node *root, int floor_val, Node *&curr_val)
{
    if (root == NULL)
        return;

    if (root->key == floor_val)
    {
        curr_val = root;
        return;
    }

    else if (floor_val < root->key)
        floorBST(root->left, floor_val, curr_val);

    else if (floor_val > root->key)
    {
        curr_val = root;
        floorBST(root->right, floor_val, curr_val);
    }
    
}


/*
    EFFICIENT SOLUTION:

    TIME COMPLEXITY: O(h)
    S.C. / Aux Space: O(1)
*/
Node* iterativeFloorBST(Node *root, int floor_val)
{
    Node *res = NULL;
    Node *curr = root;

    while(curr!= NULL)
    {
        if (curr->key == floor_val)
            return curr;

        else if (floor_val < curr->key)
            curr = curr->left;

        else if (floor_val > curr->key)
        {
            res = curr;
            curr = curr->right;
        }
    }

    return res;
}

int main()
{
    /**
     * @brief 
     *          eg: floor_val = 25
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
    int floor_value = 25;
    // int floor_value = 58;
    // int floor_value = 100;
    // int floor_value = 15;
    // int floor_value = 70;

    //Recursive Soln.
    floorBST(root, floor_value, curr_value);

    cout << "Recursive: ";

    if (curr_value!=NULL)
        cout << curr_value->key << endl;
    else
        cout << "No Floor Value Exists" << endl;
    

    //EFFICIENT SOLUTION:
    //Iterative Soln.
    Node *res = iterativeFloorBST(root, floor_value);
    cout << "Iterative: ";
    if (res!=NULL)
        cout << res->key << endl;
    else
        cout << "No Floor Value Exists" << endl;
    
    return 0;
}