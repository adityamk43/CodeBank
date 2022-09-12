/**
 * @file BinaryTreeFromParentArray.cpp
 * @author ADITYA BHARDWAJ
 * @brief Construct Binary Tree from Parent Array
MediumAccuracy: 45.96%Submissions: 29034Points: 4
Given an array of size N that can be used to represents a tree. The array indexes are values in tree nodes and array values give the parent node of that particular index (or node). The value of the root node index would always be -1 as there is no parent for root. Construct the standard linked representation of Binary Tree from this array representation.

Note: If two elements have the same parent, the one that appears first in the array will be the left child and the other is the right child.


Example 1:

Input:
N = 7
parent[] = {-1,0,0,1,1,3,5}
Output: 0 1 2 3 4 5 6
Explanation: the tree generated
will have a structure like
          0
        /   \
       1     2
      / \
     3   4
    /
   5
 /
6
Example 2:

Input:
N = 3
parent[] = {2, 0, -1}
Output: 2 0 1
Explanation: the tree generated will
have a sturcture like
               2
             /
            0
          /
         1

Your Task:
You don't need to read input or print anything. The task is to complete the function createTree() which takes 2 arguments parent[] and N and returns the root node of the constructed tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 103
 * @version 0.1
 * @date 2022-09-12 09:34 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector<int> &v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node *root)
{
    vector<int> v;
    queue<Node *> q;

    q.push(root);

    Node *next_row = NULL;

    while (!q.empty())
    {
        Node *n = q.front();
        q.pop();

        if (n == next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left)
        {
            q.push(n->left);
            if (next_row == NULL)
                next_row = n->left;
        }

        if (n->right)
        {
            q.push(n->right);
            if (next_row == NULL)
                next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/

// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution
{
public:
    // Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {
        // Your code here

        // MY METHOD
        // unordered_map<int, Node *> nm;

        // Node *root;

        // for (int i = 0; i < N; i++)
        // {
        //     Node *temp = new Node(i);

        //     if (parent[i] == -1)
        //         root = temp;

        //     nm[i] = temp;
        // }

        // for (int i = 0; i < N; i++)
        // {
        //     if (parent[i] == -1)
        //         continue;

        //     Node *child = nm[i];
        //     Node *parentNode = nm[parent[i]];

        //     if (parentNode->left == NULL)
        //         parentNode->left = child;
        //     else
        //         parentNode->right = child;
        // }

        // return root;

        // MOST SHORT AND EASY TO UNDERSTAND OPTIMISED APPROACH (BY: shreevathsabk01)
        unordered_map<int, pair<Node *, Node *>> mp;

        for (int i = 0; i < N; i++)
        {
            if (mp.find(parent[i]) == mp.end())
                mp[parent[i]].first = new Node(i);
            else
                mp[parent[i]].second = new Node(i);
        }

        queue<Node *> q;

        Node *root = mp[-1].first;

        q.push(root);

        while (q.empty() == false)
        {
            Node *curr = q.front();
            q.pop();

            curr->left = mp[curr->data].first;
            curr->right = mp[curr->data].second;

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }

        return root;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        Node *res = ob.createTree(a, n);

        printLevelOrder(res);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends