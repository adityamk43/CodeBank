/**
 * @file VerticalTraversalBST.cpp
 * @author ADITYA BHARDWAJ
 * @brief Vertical Traversal of Binary Tree
 * @version 0.1
 * @date 2022-11-13 12:35 AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>

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

//My Method
/**
 * @brief IMPORTANT NOTE:
 * We can't use this since this is doing inorder traversal and the drawback is that:
 * 1.)If there are more than one nodes on same vertical line then the topmost node should be printed first then lower level node in Binary tree. 
 * 2.)And if two nodes are on same level then left child node should be printed first then right child node.
 * 
 * These above properties are not being followed using inorder traversal.
 * 
 * (LEVEL ORDER TRAVERSAL IS MUST AND REQUIRED TO SOLVE THIS QUESTION ACCORDING TO THE ABOVE PROPERTIES)
 * 
 * @param root 
 * @param m 
 * @param hd 
 */
// void verticalTraversalBSTDeprecated(Node *root, map<int, vector<int>> &m, int hd)
// {
//     if (root == NULL)
//         return;
    
//     verticalTraversalBSTDeprecated(root->left, m, hd-1);

//     //long way
//     // vector<int> vect = m[hd];
//     // vect.push_back(root->key);
//     // m[hd] = vect;

//     //shortcut
//     m[hd].push_back(root->key);

//     verticalTraversalBSTDeprecated(root->right, m, hd+1);

// }


/**
 * @brief TIME COMPLEXITY: O(nloghd)
 *      AUX SPACE: O(n)
 * The above are same as finding vertical sum since we are following the same approach!!
 * 
 * @param root 
 * @param m 
 */
void verticalTraversalBST(Node *root, map<int, vector<int>> &m)
{
    if (root == NULL)
        return;
    
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node*, int> p = q.front();
        q.pop();

        Node *curr = p.first;
        int hd = p.second;

        m[hd].push_back(curr->key);

        if (curr->left!=NULL)
            q.push({curr->left, hd-1});
        if (curr->right!=NULL)
            q.push({curr->right, hd+1});
    }
}

int main()
{

    //Example 1
    /**
     * @brief 
     *  
     *              10
     *             /  \
     *           20   30
     *          / \
     *         5  15 
     * 
     */
    // Node *root = new Node(10);
    // root->left = new Node(20); 
    // root->right = new Node(30);
    // root->left->left = new Node(5);
    // root->left->right = new Node(15);

    //Example 2
    /**
     * @brief 
     *  
     *              10
     *             /  \
     *           20   30
     *               / \
     *             40  50 
     * 
     */
    // Node *root = new Node(10);
    // root->left = new Node(20); 
    // root->right = new Node(30);
    // root->right->left = new Node(40);
    // root->right->right = new Node(50);

    //Example 3
    /**
     * @brief 
     *  
     *                1
     *              /   \
     *             2    3
     *           /  \  / \
     *          4   5 6  7
     *                  /
     *                 8
     *                /
     *               9
     */
    Node *root = new Node(1);
    root->left = new Node(2); 
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->left->left = new Node(9);

    inorder(root);

    map<int, vector<int>> m;
    verticalTraversalBST(root, m);

    cout << endl << "Vertical Traversal " << endl;

    for (auto x: m)
    {
        vector<int> arr = x.second;

        for (auto it = arr.begin(); it!=arr.end(); it++)
            cout << (*it) << " ";
        
        cout << endl;
    }

    return 0;
}

