/**
 * @file SubtreesHavingGivenSum.cpp
 * @author ADITYA BHARDWAJ
 * @brief Count Number of SubTrees having given Sum
MediumAccuracy: 50.13%Submissions: 35771Points: 4
Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.
Example: For the tree given below:

              5
            /    \
        -10     3
        /    \    /  \
      9     8  -4 7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.

Example 1:

Input:
       5
    /    \
  -10     3
 /   \   /  \
 9   8 -4    7
X = 7
Output: 2
Explanation: Subtrees with sum 7 are
[9, 8, -10] and [7] (refer the example
in the problem description).
Example 2:

Input:
    1
  /  \
 2    3
X = 5
Output: 0
Explanation: No subtree has sum equal
to 5.
Your Task:
You don't need to read input or print anything. Your task is to complete the function countSubtreesWithSumX() which takes the root node and an integer X as inputs and returns the number of subtrees of the given Binary Tree having sum exactly equal to X.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= N <= 103
-103 <= Node Value <= 103


Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
 * @version 0.1
 * @date 2022-09-14 12:11 AM
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

// Your are required to complete this function
int countSubtreesWithSumX(Node *root, int x);

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        int x;
        cin >> x;
        getchar();
        cout << countSubtreesWithSumX(root, x) << endl;
    }
    return 0;
}

// } Driver Code Ends

// User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// Function to count number of subtrees having sum equal to given sum.
int myCountSubtreesWithSumX(Node *root, int X, int &count)
{
    if (root == NULL)
        return 0;

    int l = myCountSubtreesWithSumX(root->left, X, count);
    int r = myCountSubtreesWithSumX(root->right, X, count);

    int sum = root->data + l + r;

    if (sum == X)
        count++;

    return sum;
}

int countSubtreesWithSumX(Node *root, int X)
{
    // Code here
    int count = 0;

    myCountSubtreesWithSumX(root, X, count);

    return count;
}
