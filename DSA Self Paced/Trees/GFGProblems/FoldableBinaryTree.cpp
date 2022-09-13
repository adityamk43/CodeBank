/**
 * @file FoldableBinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief Foldable Binary Tree
MediumAccuracy: 50.45%Submissions: 34049Points: 4
Given a binary tree, check if the tree can be folded or not. A tree can be folded if left and right subtrees of the tree are structure wise mirror image of each other. An empty tree is considered as foldable.
Consider the below trees:
(a) and (b) can be folded.
(c) and (d) cannot be folded.


(a)
       10
     /    \
    7      15
     \    /
      9  11
(b)
        10
       /  \
      7    15
     /      \
    9       11
(c)
        10
       /  \
      7   15
     /    /
    5   11
(d)
         10
       /   \
      7     15
    /  \    /
   9   10  12

Example 1:

Input:
     10
    /    \
   7     15
 /  \   /  \
N   9  11   N
Output:Yes
Explaination:Structure of every left and right subtree are same.
Example 2:

Input:
      10
    /    \
   7     15
 /  \   /  \
5   N  11   N
Output: No
Explaination: 7's left child is not NULL and right child is NULL. That's why the tree is not foldable.


Your Task:
The task is to complete the function isFoldable() that takes root of the tree as input and returns true or false depending upon whether the tree is foldable or not.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0 <= n <= 103
1 <= data of node <= 104
 * @version 0.1
 * @date 2022-09-12 10:36 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
and a pointer to right child */
/*struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

// Function to check whether a binary tree is foldable or not.
bool isFoldableUtil(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    // this condition is not required as "if both are not NULL" condition gets false,
    // it will already be a false return
    //  if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
    //      return false;

    // We already compared null null in above base case, so here it is not required
    if (/*(root1 == NULL && root2 == NULL) ||*/ (root1 != NULL && root2 != NULL))
    {
        if (isFoldableUtil(root1->left, root2->right) && isFoldableUtil(root1->right, root2->left))
            return true;
    }

    return false;
}

bool IsFoldable(Node *root)
{
    // Your code goes here
    if (root == NULL)
        return true;

    if (isFoldableUtil(root->left, root->right))
        return true;
}

//{ Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        if (IsFoldable(root))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
// } Driver Code Ends