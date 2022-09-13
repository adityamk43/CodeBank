/**
 * @file MaxSumOfNonAdjacentNodes.cpp
 * @author ADITYA BHARDWAJ
 * @brief Maximum sum of Non-adjacent nodes
MediumAccuracy: 53.29%Submissions: 33445Points: 4
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.



Example 1:

Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.
Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
Your Task:
You don't need to read input or print anything. You just have to complete function getMaxSum() which accepts root node of the tree as parameter and returns the maximum sum as described.

Expected Time Complexity: O(Number of nodes in the tree).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes in the tree ≤ 10000
1 ≤ Value of each node ≤ 100000
 * @version 0.1
 * @date 2022-09-14 12:14 AM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
    Node *root = newNode(stoi(ip[0]));

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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
public:
    // Function to return the maximum sum of non-adjacent nodes.
    void myGetMaxSum(Node *root, unordered_map<Node *, int> &maxValue)
    {
        if (root == NULL)
        {
            maxValue[root] = 0;
            return;
        }

        myGetMaxSum(root->left, maxValue);
        myGetMaxSum(root->right, maxValue);

        int sum = root->data;
        int ls = maxValue[root->left];
        int rs = maxValue[root->right];

        if (root->left != NULL)
            sum += maxValue[root->left->left] + maxValue[root->left->right];

        if (root->right != NULL)
            sum += maxValue[root->right->left] + maxValue[root->right->right];

        maxValue[root] = max(sum, ls + rs);
    }

    int getMaxSum(Node *root)
    {
        // Add your code here
        unordered_map<Node *, int> maxValue;

        myGetMaxSum(root, maxValue);

        return maxValue[root];
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.getMaxSum(root) << endl;
    }
    return 0;
}
// } Driver Code Ends