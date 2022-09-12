/**
 * @file BinaryTreeFromLinkedList.cpp
 * @author ADITYA BHARDWAJ
 * @brief Make Binary Tree From Linked List
MediumAccuracy: 51.16%Submissions: 27007Points: 4
Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.
Note : The complete binary tree is represented as a linked list in a way where if root node is stored at position i, its left, and right children are stored at position 2*i+1, 2*i+2 respectively.




Example 1:

Input:
N = 5
K = 1->2->3->4->5
Output: 1 2 3 4 5
Explanation: The tree would look like
      1
    /   \
   2     3
 /  \
4   5
Now, the level order traversal of
the above tree is 1 2 3 4 5.
Example 2:

Input:
N = 5
K = 5->4->3->2->1
Output: 5 4 3 2 1
Explanation: The tree would look like
     5
   /  \
  4    3
 / \
2    1
Now, the level order traversal of
the above tree is 5 4 3 2 1.
Your Task:
The task is to complete the function convert() which takes head of linked list and root of the tree as the reference. The driver code prints the level order.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Note: H is the height of the tree and this space is used implicitly for recursion stack.

Constraints:
1 <= N <= 105
1 <= Ki <= 105
 * @version 0.1
 * @date 2022-09-12 12:16 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data)
{

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r)
{
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty())
    {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head)
{
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

/* Driver program to test above function*/
int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL)
            cout << "-1\n";
        lvl(root);
        cout << endl;
        // inorder(root);
        getchar();
    }
    return 0;
}

// } Driver Code Ends

/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root)
{
    // Your code here
    if (head == NULL)
        return;

    Node *temp = head;
    queue<TreeNode *> q;
    int val = temp->data;
    // root->data = val;
    root = new TreeNode(head->data);
    q.push(root);

    temp = temp->next;

    // also works without q.empty condition but this condition might be important
    while (temp != NULL && !q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        // it can be optimised by removing this extra condition as this will be check already when
        // while loop is entered and checks for temo not  null. So, this condition is just rechecking
        // for left node which is unecessary

        // if (temp != NULL)
        // {
        //     curr->left = new TreeNode(temp->data);
        //     q.push(curr->left);
        //     temp = temp->next;
        // }

        curr->left = new TreeNode(temp->data);
        q.push(curr->left);
        temp = temp->next;

        if (temp != NULL)
        {
            curr->right = new TreeNode(temp->data);
            q.push(curr->right);
            temp = temp->next;
        }
    }
}
