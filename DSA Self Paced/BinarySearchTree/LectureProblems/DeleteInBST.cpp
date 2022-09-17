/**
 * @file DeleteInBST.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-09-18 12:25 AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int key;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

void preorder(Node *root)
{
    if (root == NULL)
        return;
    
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

//function to get inorder successor
/**
 * @brief 
 *  NOTE: Inorder Successor is closest greater value than the given key present in the tree (In
 * inorder Traversal of BST, inorder successor is leftmost Node present in the Right child subtree of the root)
 * 
 * Inorder Predecessor means closest smaller value than the given key present in the BST.
 * 
 *  NOTE: Here, we are finding inorder successor to replace the given Node with its inorder successor to maintain the rule of BST that right child should be greater than root and left child smaller than root.
 *  BUT, we could have also find inorder predecessor and replaced the given node to be deleted with it and it can also work fine with it as BST Rule will be maintained and followed!!
 * 
 *  EG:
 *          I/P: x=50
 * 
 *                  50
 *                /   \
 *              20    70
 *                   /  \
 *                 60   80
 * 
 *  If we use inorder successor method then,
 * 
 *                  60
 *                /   \
 *              20    70
 *                     \
 *                     80
 * 
 *  If we use inorder predecessor method then,
 * 
 *                  20
 *                    \
 *                    70
 *                   /  \
 *                 60   80
 * 
 */

Node *getInorderSuccessor(Node *curr)
{
    curr = curr->right;

    while (curr!=NULL && curr->left!=NULL)
        curr = curr->left;
    
    return curr;
}

/**
 * @brief NOTE:
 *  
 *      ONE INTERESTING AND IMPORTANT THING ABOUT DELETE OPERATION IN BST IS,
 * 
 *      WHEN YOU ARE DELETING A NODE AND IN DELETE, WHEN YOU FIND THE INORDER SUCCESSOR, IT WORKS BUT WE CAN'T USE THIS "getSuccessor(Node *curr)" IN GENERAL TO GET INORDER SUCCESSOR OF A NODE.
 * 
 *      THIS INORDER SUCCESSOR FUNCTION GIVES YOU SUCCESSOR ONLY WHEN YOUR RIGHT CHILD IS NON EMPTY. IN GENERAL FOR ANY ARBITRARY NODE, IF YOU WANT TO FIND THE INORDER SUCCESSOR, THIS CODE FOR "getSuccessor(Node* curr)" WILL BE SLIGHTLY MORE COMPLEX THAN THIS AND IN BST DELETION, WE NEED SUCCESSOR ONLY WHEN RIGHT CHILD IS NON-EMPTY OTHERWISE WE WILL GO INTO ONE OF THE OTHER IF ELSE CONDITION OF THE BELOW CODE.
 * 
 * LET'S OBSERVE WHY!!
 *  
 *  TAKING AN EXAMPLE OF THE GIVEN BST IN MAIN DRIVER CODE,
 *      IF YOU SEE THE INORDER SUCCESSOR OF 40, IT'S NOT THERE IN THE RIGHT CHILD WHO IS INORDER SUCCESSOR OF 40. BUT IN THE BST IT'S 50 (ROOT NODE) WHICH IS NOT PRESENT IN 40'S RIGHT SUBTREE AS RIGHT SUBTREE IS EMPTY FOR 40 NODE.
 *  
 *      SO, IN SOME CASES YOUR SUCCESSOR MAYBE ONE OF THE ANCESTORS. SO, THIS "GET SUCCESSOR FUNCTION" DOESN'T GIVE YOU IN GENERAL INORDER SUCCESSOR, BUT IT GIVES YOU INORDER SUCCESSOR WHEN RIGHT CHILD IS NOT EMPTY!!!!
 * 
 */

/*
    Since, deletion in BST works same as insertion and search in BST, so:
    
    TIME COMPLEXITY: O(h)
    AUXILIARY SPACE: O(h)  max func call stack can be h or h+1
*/

//Delete key from BST Function
Node *deleteBST(Node *root, int x)
{
    //same work as insertion
    if (root == NULL)
        return root;
    
    if (root->key > x)
        root->left = deleteBST(root->left, x);

    else if (root->key < x)
        root->right = deleteBST(root->right, x);
    
    //main work of deletion
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succNode =  getInorderSuccessor(root);
            root->key = succNode->key;
            root->right = deleteBST(root->right, succNode->key);
        }

    }
        return root;
}


//Driver Code
int main()
{
    /**
     * @brief 
     *                          50
     *                       /     \
     *                     30      70
     *                    /   \   /  \
     *                  10    40 60   80
     *                 /         /
     *                5         55
     */

    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(10);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    root->left->left->left = new Node(5);
    root->right->left->left = new Node(55);
    
    //Node with both non empty left and right child
    // int deleteKey = 50;

    //Node with both one empty either left or right child
    // int deleteKey = 10;

    //Leaf Node 
    int deleteKey = 55;
    
    cout << "Before Deletion" << endl;
    preorder(root);
    
    root = deleteBST(root, deleteKey);
    
    cout << endl << "After Deletion" << endl;
    preorder(root);

    return 0;

}