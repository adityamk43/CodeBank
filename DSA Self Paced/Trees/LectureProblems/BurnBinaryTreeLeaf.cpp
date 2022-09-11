/**
 * @file BurnBinaryTreeLeaf.cpp
 * @author ADITYA BHARDWAJ
 * @brief It is simply finding maximum distance between given leaf node to the any other leaf in the given binary tree 
 * @version 0.1
 * @date 2022-09-11 08:55 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

struct Node{
    
    int key;
    Node* left;
    Node* right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

/**
 * @brief We basically use a technique of finding diameter of a tree. If for a node the given leaf is a descendent of that node, then we find a distance between them. and then if that leaf node is a right child then we find the height of the left subtree of it and we do addition of 1 + lh + rdist and vice versa if leaf node is left child. (So, this is simply like finding diameter but with some very tricky and important modification.)
 * 
 * We also use a technique of ancestors here:
 *       Let's take an example:
 *                          10(3)
 *                         /
 *                       20(2)
 *                     /    \
 *                   30(1)  5(3)
 *                  /   \
 *               40(2)  50(0)
 *               /
 *             60(3)
 *            /
 *          70(4)
 *          The farthest node must be reachable through one of the ancestors (50, 30, 20 and then 10)
 *  
 *         Distance through 50 = 0
 *         Distance through 30 = 4
 *         Distance through 20 = 3
 *         Distance through 10 = 3
 * 
 *    
 *      @details DRY RUN: (for leaf = 50)
 *                          10(2 5)
 *                         /     \ 
 *                     20(1 4)  30(-1 1)
 *                     /    \
 *                  40(-1 3) 50(0 1)
 *                  /   
 *               60(-1 2)  
 *               /
 *             70(-1 1) [Here -1 is distance from 50 if it is a descendant else -1]
 *                      [Here 1 is the height of this node] 
 *                      [This distance and height is managed for all nodes during recursive traversal]
 *                
 */

/*
    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(h)
*/

int myBurnBinaryTree(Node* root, int leaf, int &dist, int &res)
{
    if (root == NULL)
        return 0;
    
    if (root->key == leaf)
    {
        dist = 0;
        return 1;
    }

    int ldist = -1, rdist = -1;
    int lh = myBurnBinaryTree(root->left, leaf, ldist, res);
    int rh = myBurnBinaryTree(root->right, leaf, rdist, res);

    if (ldist!= -1)
    {
        dist = ldist + 1;
        res = max(res, dist + rh);
    }
    else if (rdist!= -1)
    {
        dist = rdist + 1;
        res = max(res, dist + lh);
    }

    return 1 + max(lh, rh);

}

int burnBinaryTree(Node *root, int leaf)
{
    int res = 0;
    int dist = -1;
    
    myBurnBinaryTree(root, leaf, dist, res);

    return res;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->left->left = new Node(60);
    root->left->left->left->left = new Node(70);

    int leaf = 50;

    cout << burnBinaryTree(root, leaf) << endl;

    return 0;
}