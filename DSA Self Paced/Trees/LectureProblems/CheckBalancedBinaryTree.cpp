/**
 * @file CheckBalancedBinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief  IF DIFFERENCE HEIGHTS OF LEFT CHILDS OF ROOTS AND RIGHT CHILD IS NOT MORE THAN ONE THEN IT CAN BE SAID THAT IT IS A BALANCED BINARY TREE. (DIFFERENCE CAN BE EITHER 0 OR 1 AND NOT MORE THAN 1)
 * @version 0.1
 * @date 2022-09-10 06:12 PM
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

//NAIVE METHOD: O(n^2)

/*
    TIME COMPLEXITY: O(n^2)
                    Since we are finding height if binary tree for every node during traversing the tree recursively. Hence, we are doing O(n) work for every node.
                    So, total time complexity is O(n^2)
    AUXILIARY SPACE: O(h)
*/
// int heightOfBinaryTree(Node *root)
// {
//     if (root == NULL)
//         return 0; 
    
//     return 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
// }

// bool checkBalancedBinaryTree(Node* root)
// {
//     if (root == NULL)
//         return true;

//     int lh = heightOfBinaryTree(root->left);
//     int rh = heightOfBinaryTree(root->right);

//     int diff = abs(lh-rh);

//     return diff <=1 && checkBalancedBinaryTree(root->left) && checkBalancedBinaryTree(root->right);

// }


//EFFICIENT METHOD
/**
 * @brief We can find height and return true in one function only.
 * What we can do is that we can return -1 if height is not balanced else we can return the height of the tree. so instead of making the datatype of function as bool we can do it by making function to return int. If tree is balanced then return height of the Binary tree else return -1 if Binary Tree is not Balanced.

 */
int checkBalancedBinaryTree(Node* root)
{
    if (root == NULL)
        return 0;

    /**
    * @brief left child or right child has not balanced subtree then immediately return -1 as there
    * is no use of more taversal as if subtree is not balanced then ultimately whole tree is not
    * balanced
    */
    
    //checking for left subtree and also getting the left height
    int lh = checkBalancedBinaryTree(root->left);
    if (lh == -1) return -1;

    //checking for right subtree and also getting the right height
    int rh = checkBalancedBinaryTree(root->right);
    if (rh == -1) return -1;

    if (abs(lh-rh) > 1) return -1;

    //returning height of respective tree
    return 1 + max(lh, rh);

}


int main()
{
    //Balanced tree example
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);

    //Unbalanced tree example
    // Node *root = new Node(8);
    // root->left = new Node(12);
    // root->right = new Node(15);
    // root->left->left = new Node(13);
    // root->left->right = new Node(14);
    // root->right->right = new Node(16);
    // root->right->right->right = new Node(17);

    // if (checkBalancedBinaryTree(root))
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;

    if (checkBalancedBinaryTree(root) != -1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}