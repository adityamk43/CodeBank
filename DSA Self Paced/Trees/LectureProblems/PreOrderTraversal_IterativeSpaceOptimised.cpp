/**
 * @file PreOrderTraversal_IterativeSpaceOptimised.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-17 08:43 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

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

// void preOrderTraversalIterative(Node *root)
// {
//     if (root == NULL)
//         return;
    
//     stack<Node*> s;
//     s.push(root);

//     while (s.empty() == false)
//     {
//         Node *curr = s.top(); 
//         s.pop();
//         cout << curr->key << " ";

//         if (curr->right != NULL)
//             s.push(curr->right);
//         if (curr->left != NULL)
//             s.push(curr->left);


//     }

// }


/*
    Since, above function using level order technique has O(n) Auxiliary Space, we can optimise it more further to O(h) in the below approach.

    What we can do is since, we are traversing left left left nodes, when we are traversing left of that node, we can push its right node in the stack alon while printing the root node.

    Here, since we are only pushing right nodes of the tree, we will have atmost O(h) right children when we are beginning with the root.

    Therefore,

    TIME COMPLEXITY: O(n)

    AUX SPACE: O(h)

*/
void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    
    stack<Node*> st;

    Node *curr = root;

    while (curr!=NULL || st.empty() == false)
    {
        while (curr!=NULL)
        {
            cout << curr->key << " ";

            if (curr->right!=NULL)
                st.push(curr->right);
            
            curr = curr->left;
        }

        if (st.empty() == false)
        {
            curr = st.top();
            st.pop();
        }
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
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    preOrderTraversal(root);

    return 0;
}