/**
 * @file VerticalSumBST.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-11-12 10:15 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <map>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int key)
    {
        this->key = key;
        left=right=NULL;
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
 * @brief TIME COMPLEXITY: O(nloghd + hd) 
 * (log hd since map is based on self balancing BST so we will store all horizontal distances node's sum so total values of hd will be stored in map and slef balancing has logn time in insertion and hence, loghd here and we are doing this loghd for all nodes so O(nloghd))
 * (Addition of hd since for printing the values we are traversing the map and as it is a self balancing BST it will take hd time)
 *                  
 *                  approx. O(nloghd)
 *                  where hd = Total no. of possible horizontal distances
 * 
 * AUX SPACE: O(n + hd) 
 *            approx. O(n)
 * @param root 
 * @param m 
 * @param hd 
 */
void verticalSumBST(Node *root, map<int, int> &m, int hd)
{
    if (root == NULL)
        return;
    
    verticalSumBST(root->left, m, hd-1);

    m[hd] += root->key;

    verticalSumBST(root->right, m, hd+1);

}

int main()
{

    //Example 1
    Node *root = new Node(10);
    root->left = new Node(20); 
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    //Example 2
    // Node *root = new Node(10);
    // root->left = new Node(15); 
    // root->right = new Node(25);
    // root->left->left = new Node(35);
    // root->left->right = new Node(20);
    // root->left->left->left = new Node(40); 
    // root->left->right->right = new Node(75);
    // root->left->right->right->right = new Node(80);

    inorder(root);

    map<int, int> m;
    verticalSumBST(root, m, 0);

    cout << endl << "Vertical Sum " << endl;

    for (auto x: m)
        cout << x.second << " ";
    cout << endl;

    return 0;
}