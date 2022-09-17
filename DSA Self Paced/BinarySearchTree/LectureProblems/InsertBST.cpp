/**
 * @file InsertBST.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-17 11:02 PM
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

/**
 * @brief NOTE:
 *  1st Case:
 *      when we are inserting the key in the BST, we insert it at the bottom or we can say as a leaf.
 *      In this case, we don't change the root.
 *  
 *  2nd Case:
 *      But in a case when a user pass NULL as a root, then we have to update the root as a inserted key Node as we have to insert key in the empty BST. SO, in this we have to change the updated root in return!!
 * 
 *  2nd Case: 
 *      Function should not change the BST, if the given key is already present in the BST.
 * 
 */

/*
    Time Complexity and Auxiliary Space is same as that of Search in BST as we are doing the same thing with in extra we are creating a new Node and linking it to our BST which is considered as constant work. Therefore,

    TIME COMPLEXITY: O(h)
    AUXILIARY SPACE: O(h)  max func call stack can be h or h+1
*/

//SANDEEP SIR APPROACH (RECURSIVE)
Node* insertBSTSandeepSir(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);


    else if (root->key > x)
        root->left = insertBSTSandeepSir(root->left, x);

    else if (root->key < x)
        root->right = insertBSTSandeepSir(root->right, x);

    //if key is already present in the given BST Or simply return after linking leaf node with the given key
    return root;
    
}

//MY APPROACH (RECURSIVE)
void insertBST(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return;
    }

    if (root->key == x)
        return;
    else if (root->key > x)
    {
        if (root->left == NULL)
        {
            root->left = new Node(x);
            return;
        }
        else
            insertBST(root->left, x);
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(x);
            return;
        }
        else
            insertBST(root->right, x);
    }
}

//ITERATIVE APPROACH (Better Approach)
/*
    TIME COMPLEXITY: O(h)
    AUXILIARY SPACE: O(1)
        Therefore, Less space and no function call overhead here!!
        (But recurive code here of Sandeep Sir Approach is very tiny code and very simple to write)
*/

Node* insertBSTIterative(Node *root, int x)
{
    Node *temp = new Node(x);
    //To have the hold of the parent node (Required for iterative approach)
    Node *parent = NULL;
    Node *curr = root;

    while (curr != NULL)
    {
        parent = curr;

        if (curr->key > x)
            curr = curr->left;
        else if (curr->key < x)
            curr = curr->right;
        else    //if key is already present in the given BST
            return root;
    }
    //End of the Loop

    //For handling base case(Exceptional Condition) only when empty tree is provided, then we return the new Node with given key (As the parent Node will not be updated after the end of the loop if the given BST is empty!!)
    if (parent == NULL)
        return temp;
    else if (parent->key > x)
        parent->left = temp;
    else
        parent->right = temp;

    return root;
}
//End of the Iterative InsertBST Function

//Driver Code
int main()
{
    /**
     * @brief 
     *                         10
     *                       /    \
     *                      5     15
     *                           /  \
     *                         12   18
     */

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    //Base Case (if BST is empty)
    // Node *root1 = NULL;

    //Base Case (if given key is present already in the BST)
    // int insertKey = 18;

    int insertKey = 20;
    
    cout << "Before Insertion" << endl;
    preorder(root);
    
    //Using My Approach (Recursive)
    // insertBST(root, insertKey);

    //Using Sandeep Sir Approach
    // root = insertBSTSandeepSir(root, insertKey);

    //Using Iterative Approach
    root = insertBSTIterative(root, insertKey);
    
    cout << endl << "After Insertion" << endl;
    preorder(root);

    return 0;

}