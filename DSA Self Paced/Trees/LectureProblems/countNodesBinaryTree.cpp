/**
 * @file countNodesBinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief This count Nodes if efficient version of finding size of a binary tree but only when tree is perfect binary tree.
 * 
 * A tree is called perfect binary tree when all internal levels are filled and only last level is partially filled or fully filled from *left to right*.
 * @version 0.1
 * @date 2022-09-11 10:10 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cmath>
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
 * @brief 
 *  We will use a mathematical formula that if binary tree is fully filled then total nodes in the binary tree is equal to (2^h-1) where h is the height of the perfect binary tree
 *  
 * example: if height = 4,
 *          then total nodes of this perfect binary tree is 2^4-1 = 15 Nodes
 *  
 *  (NOTE: We can check if binary tree is fully filled perfect binary tree if left subtree height is equal to right subtree height)
 *  
 *  An if subtree is partially filled at last level and not a fully filled then we will use normal way of finding size of a binary tree that is (1+ fun(root.left) + fun(root.right))
 * 
 * Through this way we can optimised the count node for perfect binary tree!!
 */

/*
    TIME COMPLEXITY: O(logn * logn)
        Let's say that left subtree of a root if fully perfect binary tree and right subtree is partially perfect binary tree as last level is partially filled.

        then left subtree will take ⊝(h) time to count nodes and right subtree will have take more time according to the nodes in right subtree as we will use naive way in it.

        So, we can say that recursive time complexity function will be like this:
            T(n) < T(2n/3) + ⊖(h)

        where 2n/3 are those nodes which are a part partially filled perfect binary tree/subtree

        So, to find the Time Complexity we can assume,
            =>T(n) = T(2n/3) + ⊖(h)
            =>T(n) = T(2n/3) + ⊖(log2n)   [as n = 2^h + 1]
            Since, for every recursive traversal n is reduced by a factor of 3/2,
                    ⊝(log2n)
                    |
                    ⊖(log2 (2n/3))
                    |
                    ⊖(log2 (4n/9))
                    |
                    ⊖(log2 (8n/27))
                    |
                    ..
            So, total Time Complexity will be:
                O(log3/2n * log2n)
                =>O(logn * logn) [which is less than naive time which was ⊖(n)]
        
        Best Case: ⊖(h) => ⊖(log2n)
    
    AUXILIARY SPACE: O(h)
*/

int countNodes(Node* root)
{
    int lh=0, rh=0;

    Node* curr = root;
    while(curr!=NULL)
    {
        lh++;
        curr = curr->left;
    }

    curr = root;
    while(curr!=NULL)
    {
        rh++;
        curr = curr->right;
    }

    if (lh==rh)
        return pow(2, lh)-1;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int main()
{

    /**
     * @brief DRY RUN:
     *     countNodes(10)  [returns 1+7+4 (Naive)]
     *              -> countNodes(20) [returns 2^3-1 = 7]
     *              -> countNodes(30)  [returns 1+2+1 = 4]
     *                          -> countNodes(60)  [returns 1+1+0 = 2 (Naive)]
     *                                      -> countNodes(120)  [returns 2^1-1 = 1]
     *                                      -> countNodes(NULL)  [returns 2^0-1 = 0]
     *                          -> countNodes(70)  [returns 2^1-1 = 1]
     * 
     */
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    root->left->left->left = new Node(80);
    root->left->left->right = new Node(90);
    root->left->right->left = new Node(100);
    root->left->right->right = new Node(110);
    root->right->left->left = new Node(120);

    cout << countNodes(root) << endl;

    return 0;
}