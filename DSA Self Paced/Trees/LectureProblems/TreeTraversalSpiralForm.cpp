/**
 * @file TreeTraversalSpiralForm.cpp
 * @author ADITYA BHARDWAJ
 * @brief Traversing Binary Tree in simple spiral form or zig zag form
 * @version 0.1
 * @date 2022-09-11 02:38 PM
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
    @brief
    WE COULD HAVE USED NORMAL LEVEL ORDER TRAVERSAL LINE BY LINE FOR SPIRAL TRAVERSAL. WHAT EXTRA WORK THAT WAS REQUIRED IS THAT FOR EACH ALTERNATE TRAVERSAL WE HAD TO REVERSE THE PRINT. SO, WE HAVE TO MAINTAIN ONE STACK FOR ALTERNATE LEVELS, WHERE NODE CAN BE PUSHED INTO STACK AND WHEN POPPED FROM STACK NODES ARE PRINTED IN REVERSE ORDER. FOR ALTERNATE PRINTING, WE WILL MAINTAIN ONE BOOLEAN VARIABLE WHICH AFTER ONE TRAVERSAL WILL BE INVERTED TO TRUE OR FALSE.

    MEANS FOR THE BELOW GIVEN TREE:
        BOOLEAN VARIABLE WILL BE INITIALISED AS FALSE FOR DEFAULT.
        1 WILL BE PRINTED NORMALLY LIKE WE DO IN LEVEL ORDER TRAVERSAL LINE BY LINE
        IN THIS LOOP BOOLEAND VARIABLE IS INVERTED TO TRUE
        SO FOR 2ND LEVEL (2, 3) WILL BE PUSHED INTO THE STACK AND AFTER POPPING IT WILL BE PRINTED AS 3, 2. AND SO ON..
    
    TIME COMPLEXITY: O(n) for above method..

    BUT THIS COULD BE OPTIMISED. THE ABOVE METHOD SEEMS TO BE DOING EXTRA WORK FOR THE ITEMS WHICH HAVE TO BE PRINTED IN REVERSE ORDER AS ALTERNATE LEVEL NODES ARE PUSHED INTO QUEUE THEN DEQUED, AND THEN PUSHED INTO STACK AND THEN POPPED WHICH CAUSES O(4n) OPERATION FOR ALTERNATE LEVEL NODES AS THOSE NODES WILL BE TRAVERSED 4 TIMES.

    WE CAN OPTIMISED THIS IN SUCH A WAY THAT EVERY NODE GOES INTO THE DATA STRUCTURE EXACTLY ONCE AND COMES OUT OF THE DATA STRUCTURE EXACTLY ONCE. SO, THIS WAY WE REDUCE THE AMOUNT OF THE WORK FOR HALF OF THE ITEMS/NODES WHICH ARE BEING PRINTED FROM RIGHT TO LEFT.

    SO, BELOW IS THE IMPLEMENTATION WHICH CAN REDUCE PUSHING AND POPPING OPERATION BY MAINTAING ONLY 2 STACKS INSTEAD OF QUEUE AND STACK.

    ONE STACK WILL PRINT IN ORIGINAL ORDER AND OTHER STACK IN REVERSE ORDER.

    SO 1ST STACK WILL PUSH RIGHT CHILD NODE FIRST AND THEN LEFT CHILD NODE WHICH WHEN POPPED WILL PRINT IN ORIGINAL ORDER AND VICE-VERSA FOR 2ND STACK.

    YOU CAN GET CLEAR UNDERSTANDING FROM BELOW IMPLEMENTATION.
        
*/

/**
 * @brief 
 *  I/P:
 *                    1
 *                 /    \
 *                /      \
 *               2       3
 *            /   \     /  \
 *           4    5    6    7
 *         /  \      /  \
 *        8    9   10    11
 * 
 *  O/P: 
 *  FOR ZIGZAG TRAVERSAL WHEN Root Node is Pushed in 2nd stack first
 *      1 3 2 4 5 6 7 11 10 9 8 
 *  FOR SIMPLE SPIRAL TRAVERSAL WHEN Root Node is Pushed in 1nd stack first
 *      1 2 3 7 6 5 4 8 9 10 11
 */

/*
    TIME COMPLEXITY: O(n)
    AUXILIARY SPACE: O(h)
*/

void treeTraversalSpiralForm(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s1;
    stack<Node *> s2;

    //for simple spiral traversal
    s1.push(root);
    //for zig-zag traversal
    // s2.push(root);

    while (!s1.empty() || !s2.empty())
    {

        //take out a node and print it, and push its children to 2nd stack (s2)
        while (!s1.empty())
        {
            Node *node = s1.top();
            s1.pop();

            cout << node->key << " ";

            if (node->right != NULL)
                s2.push(node->right);

            if (node->left != NULL)
                s2.push(node->left);
        }
        
        //take out a node and print it, and push its children to 1nd stack (s1) in reverse order
        while (!s2.empty())
        {
            Node *node = s2.top();
            s2.pop();

            cout << node->key << " ";

            if (node->left != NULL)
                s1.push(node->left);

            if (node->right != NULL)
                s1.push(node->right);
        }

    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->left->left = new Node(10);
    root->right->left->right = new Node(11);

    treeTraversalSpiralForm(root);

    return 0;
}