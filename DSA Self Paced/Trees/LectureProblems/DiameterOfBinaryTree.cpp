/**
 * @file DiameterOfBinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief Diameter of a binary tree is number of node on the longest path between two leafs.
 *          Base Cases: Null: 0
 *          Only Root exists: 1
 * @version 0.1
 * @date 2022-09-11 03:08 PM
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

/**
 * @brief 
 *  I/P:
 *                  
 *                    10
 *                   /  \
 *                 20   30
 *                     /  \
 *                   40   50
 *                   /  
 *                 60 
 *  
 *  O/P: 
 *     5  (Diameter is longest path from 20(leaf) - 10 - 30 - 40 - 60(leaf))
 */

/*
    TIME COMPLEXITY: O(n^2)

        Worst Case Time Complexity Happens when tree is skewed: 
*                    1
*                   / 
*                  2
*                 /
*                3
*              /
*            ...   
*          
*         T(n) = T(n-1) + ⊖(n)
*              = ⊝(n^2)

    AUXILIARY SPACE: O(h)
*/

// int heightOfBinaryTree(Node *root)
// {
//     if (root == NULL)
//         return 0; 
    
//     return 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
// }

// int diameterOfBinaryTree(Node *root)
// {
//     if (root == NULL)
//         return 0;
    
//     int lh = heightOfBinaryTree(root->left);
//     int rh = heightOfBinaryTree(root->right);

//     int d1 = 1 + lh + rh;
//     int d2 = diameterOfBinaryTree(root->left);
//     int d3 = diameterOfBinaryTree(root->right);

//     return max(d1, max(d2, d3));
    
// }

/**
 * @brief 
 * 
    METHOD 2:
        To Solve the above solution in linear time, we can precompute the heights of the given tree/subtree and store it in the map (unordered_map<Node*, int> in c++ and HashMap<Node, Integer> in java), then we can get the height in O(1) time.
        So, what we do is we run a function height for the whole tree that precomputes heights for every nodes in the given binary tree. It builds a map where node is a key and height is a value and this map can built in O(1) time. So, our diameter functiom now becomes O(1) time. Because now it's going to call height of left and height of right and they are going to be O(1) calls. So, overall diameter function becomes like any normal tree traversal function like a function which is used to find out maximum/minimum value in a tree. So, that's how we get O(n) overall TIME COMPLEXITY.

    METHOD 3: 
        The Method 2 was a better solution but it requires O(n) extra space for Hashing. Also, it requires extra overhead for looking up into the hash table and storing into the hash table.

        This solution will work in O(n) time and will not require any extra overhead for the hash table.

        The IDEA is to modify the height function. When we compute height of a tree, we traverse through every node and for every node, we computer the left height and right height of the binary tree. At that moment only, we can find out the diameter for that node. 

        We can find out this value -> (1+lh+rh) while we are traversing through every node to compute its height and we can just keep track of maximum of (1+rh+lh) values that we have seen so far. And at the end we simply return the maximum value.

        So, in this solution extra space is saves as Hash table requires O(n) extra space but now since we are using modified height function, the extra space will only be just O(h)!!
    
*/

/*
    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(h)
*/

int diameter = 0;
//This function returns height but sets the diameter (global variable) to have diamter
int heightOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;
    
    int lh = heightOfBinaryTree(root->left);
    int rh = heightOfBinaryTree(root->right);

    diameter = max(diameter, 1 + lh + rh);

    return 1 + max(lh, rh);
}

int main()
{
    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // root->left->left->left = new Node(8);
    // root->left->left->right = new Node(9);
    // root->right->left->left = new Node(10);
    // root->right->left->right = new Node(11);

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->left = new Node(60);
    

    // cout << diameterOfBinaryTree(root) << endl;

    cout << "Height: " << heightOfBinaryTree(root) << endl;
    cout << "Diameter: " << diameter << endl;

    return 0;
}