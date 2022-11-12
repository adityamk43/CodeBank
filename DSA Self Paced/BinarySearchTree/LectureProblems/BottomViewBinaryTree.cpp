/**
 * @file BottomViewBinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief Bottom View of Binary Tree
 * @version 0.1
 * 
 * @date 2022-11-13 02:20 AM
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

/**
 * @brief TIME COMPLEXITY: O(nloghd)
 *      AUX SPACE: O(n)
 * The above are same as finding vertical sum since we are following the same approach!!
 * 
 * @param root 
 * @param m 
 */
void bottomViewBST(Node *root, map<int, int> &m)
{
    if (root == NULL)
        return;
    
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        Node *curr = p.first;
        int hd = p.second;

        if (m.find(hd) == m.end())
            m.insert({hd, curr->key});
        else
            m.at(hd) = curr->key;

        //shortcut
        // m[hd] = curr->key;        

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
     *               10
     *             /   \
     *           20    50
     *          / \   /  \
     *        30  40 60  70
     * 
     */
    Node *root = new Node(10);
    root->left = new Node(20); 
    root->right = new Node(50);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

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
    // Node *root = new Node(1);
    // root->left = new Node(2); 
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // root->right->right->left = new Node(8);
    // root->right->right->left->left = new Node(9);

    inorder(root);

    map<int, int> m;
    bottomViewBST(root, m);

    cout << endl << "Bottom View of Binary Tree:" << endl;

    for (auto x: m)
        cout << x.second << " ";
    
    cout << endl;

    return 0;
}

