/**
 * @file PreOrderTraversal(Iterative).cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-17 08:06 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <stack>
using namespace std;

//PREORDER TRAVERSAL OF BINARY TREE (ITERATIVE) - USING STACK (FOLLOWS LEVEL ORDER -BFS APPROACH BUT INSTEAD OF QUEUE, WE ARE USING STACK HERE AND PUSHING RIGHT CHILD FIRST AND THEN LEFT CHILD AS STACK FOLLOWS LIFO AND WE WANT TO PRINT LEFT FIRST BEFORE OF RIGHT CHILD NODE)

struct Node{

    int key;
    struct Node *left;
    struct Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }

};

/*
    TIME COMPLEXITY: O(n)

    AUX SPACE: O(n)

    Since, this approach follows BFS/Level Order Traversal, so time complexity and auxiliary space is same as level order traversal technique
*/

void preOrderTraversalIterative(Node *root)
{
    if (root == NULL)
        return;
    
    stack<Node*> s;
    s.push(root);

    while (s.empty() == false)
    {
        Node *curr = s.top(); 
        s.pop();
        cout << curr->key << " ";
        
        if (curr->right != NULL)
            s.push(curr->right);
        if (curr->left != NULL)
            s.push(curr->left);


    }

}


int main()
{
    /**
     * @brief 
     *               10
     *             /   \
     *           20    30
     *          /  \   /
     *        40   50 60
     */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    preOrderTraversalIterative(root);


    return 0;
}