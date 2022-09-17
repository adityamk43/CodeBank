/**
 * @file SearchInBST.cpp
 * @author ADITYA BHARDWAJ
 * @brief In Binary Search Tree, only distinct key values are preffered.
 *        They can be looked like modified form of linked list as values are stored in different locations and doesn't require static size and values can be inserted until the memory is available
 * 
 *      In Binary Search Tree, key value smaller than root key value are inserted as the left child of the root and greater as the right child and similarly for subtrees.
 * @version 0.1
 * @date 2022-09-17 10:33 PM
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


/**
 * @brief NOTE:
 *  
 * Since, this is a normal Binary Search Tree, so it may happen that height of the tree may become equal to number of nodes in the BST i.e. n.
 * 
 * So, for skewed BST, when node keys are in increasing order of the keys,
 *                  N
 *                  \
 *                   N
 *                   \
 *                   ..
 *  Or decreasing order of the keys,
 *  *               N
 *                 /
 *                N
 *               /
 *             ..
 * 
 *  then time complexity and Auxiliary Space(For Recursive Approach) will become O(n) for this.
 * 
 * In future, when we will use self-balancing BST, its time complexity and Auxiliary Space(for Recursive approach) will be O(log n).
 * 
 * That's why average/best term for time complexity/auxiliary space will be O(h) for normal BST!!
 * 
 * NOTE: Best case is when BST is perfectly balanced. As self-balancing BST ensured logn order for the height!! (logn height of self-balanced BST)
 */

//RECURSIVE APPROACH
/*
    TIME COMPLEXITY: O(h)
    AUXILIARY SPACE: O(h)  max func call stack can be h or h+1
*/
bool searchBSTRecursive(Node *root, int x)
{
    if (root == NULL)
        return false;
    
    if (root->key == x)
        return true;
    else if (root->key > x)
        return searchBSTRecursive(root->left, x);
    else 
        return searchBSTRecursive(root->right, x); 

}

//ITERATIVE APPROACH (Better Approach)
/*
    TIME COMPLEXITY: O(h)
    AUXILIARY SPACE: O(1)
        Therefore, Less space and no func call overhead here!!
*/
bool searchBSTIterative(Node *root, int x)
{
    Node *curr = root;

    while (curr!=NULL)
    {
        if (curr->key == x)
            return true;
        else if (curr->key > x)
            curr = curr->left;
        else if (curr->key < x)
            curr = curr->right;
    }

    return false;
}

int main()
{
    /**
     * @brief 
     *                          15
     *                       /     \
     *                      5      20
     *                     /      /   \
     *                    3     18    80
     *                         /
     *                       16
     */

    Node *root = new Node(15);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->right->left = new Node(18);
    root->right->right = new Node(80);
    root->right->left->left = new Node(16);

    int searchKeyRecursive = 16;
    int searchKeyIterative = 19;

    cout << "Using Recursive Approach" << endl;
    if (searchBSTRecursive(root, searchKeyRecursive))
        cout << "Present" << endl;
    else
        cout << "Not Present" << endl;


    cout << "Using Iterative Approach" << endl;
    if (searchBSTIterative(root, searchKeyIterative))
        cout << "Present" << endl;
    else
        cout << "Not Present" << endl;

    return 0;
}
