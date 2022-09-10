/**
 * @file BinaryTreeFromPreorderAndInOrder.cpp
 * @author ADITYA BHARDWAJ
 * @brief WE WILL NEED A COMBINATION OF EITHER PREORDER AND INORDER 
 *        OR POSTORDER AND INORDER TO CONSTRUCT BINARY TREE FROM IT.
 *  
 *      **WITHOUT INORDER ARRAY, WE CANNOT CONSTRUCT A BINARY TREE, (EG:- PREORDER AND POSTORDER 
 *        CANNOT CONSTRUCT BINARY TREE AS WE WILL NEED INORDER DATA WHICH WILL TELL LEFT AND RIGHT 
 *        CHILD NODES OF THE ROOT OF TREE)
 * @version 0.1
 * @date 2022-09-10 07:25 PM
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
    TIME COMPLEXITY: ⊝(n^2) 
    AUXILIARY SPACE: ⊝(h)   h = height of binary tree (h+1)

 *  @brief (IMPORTANT NOTE):
        THIS SOLUTION CAN ALSO BE DONE IN O(n) TIME USING HASHING!!

        WHAT WE CAN DO IS, WE CAN STORE INORDER TRAVERSAL KEYS AS KEY IN THE HASH TABLE AND THEIR INDEXES AS VALUE.

        SO, INSTEAD OF LINEARLY SEARCHING INORDER ARRAY FOR FINDING THE INDEX OF KEY OF A ROOT, WE CAN JUST DO A LOOKUP IN THE HASH TABLE.

        SO, THIS HASH TABLE CAN BE DONE AS A PART OF PREPROCESSING AND THIS HASH TABLE CAN PASSED AS A PARAMETER TO THESE FUNCTIONS, SO THAT THESE FUNCTIONS CAN QUICKLY FIGURE OUT WHAT IS THE INDEX OF THIS ITEM IN INORDER TRAVERSAL.

        **IN C++, WE CAN CREATED AN UNORDERED SET AND WE CAN PASS IT IN THE RECURSIVE CALLS.
        **IN JAVA, WE CAN CREATE A HASH SET AND PASS IT AROUND IN ALL THE RECURSIVE CALLS, SO THAT THESE RECURSIVE CALLS CAN FIND THE INDEX OF A KEY IN INORDER TRAVERSAL.

*/

/**
 * @brief 
 *  I/P:    
 *  int in[]={20,10,40,30,50};
	int pre[]={10,20,30,40,50};

    O/P:
            10
 *         /  \
 *       20   30
 *           /  \
 *         40   50
 * 
 *  (Output in inorder fashion)
 *  10 20 30 40 50
 * 
 * 
    If we Observe, preorder will store the first element as root only, so we can create a root and store key as 10 from above example as root node. Inorder array will give data about left and right child nodes. we can see 10 key Root Node has (20) as left child node and (40, 30, 50) as right child nodes.

    Now, we increment preIndex, and we have new root Node as 20. Now, in inorder Array, we see 20 key Node has (NULL) as left child Node and (NULL) as right Child Node.

    Sim, for 30, we have (40) as left and (50) as right child Node.

    **(IN QUESTION, IT IS NOT NECESSARY THAT WE WILL BE GIVEN INORDER AND PREORDER, QUESTION CAN ALSO BE LIKE CONSTRUCT A TREE FROM INORDER AND POSTORDER.
    
    THE IDEA WILL CHANGE A LITTLE BIT AS POSTORDER STORES THE ROOT NODE AS A LAST ELEMENT IN ITS ARRAY)
 * 
 */

/*
    is is inorder start pointer
    ie is inorder end pointer
*/
//This pointer will maintain preOrder index for all nodes (for all recursive function)
// int preIndex = 0;
// Node *constructTree(int pre[], int in[], int is, int ie)
// {
//     if (is > ie)
//         return NULL;
    
//     //as explained earlier, preorder has stores data as first root then left then right child node
//     Node *root = new Node(pre[preIndex++]);

//     /**
//      * @brief To find the root element in inorder array so, that we can compute its left and right child nodes
//      * 
//      */
//     int inIndex = 0;
//     for (int i=is; i<=ie; i++)
//     {
//         if (in[i] == root->key)
//         {
//             inIndex = i;
//             break;
//         }
//     }

//     //recursive call for left and right child nodes untill whole tree is fullly constructed, then we return the root node to the parent call..
//     root->left = constructTree(pre, in, is, inIndex-1);
//     root->right = constructTree(pre, in, inIndex+1, ie);

//     return root;
// }

/*
    USING HASHING
*/
int preIndex = 0;
Node *constructTree(int pre[], int in[], unordered_map<int, int> &inorderMap, int is, int ie)
{
    if (is > ie)
        return NULL;
    
    //as explained earlier, preorder has stores data as first root then left then right child node
    Node *root = new Node(pre[preIndex++]);

    /**
     * @brief To find the root element in inorder array so, that we can compute its left and right child nodes. In this we are finding using pre computed Hashmap
     * 
     */
    //find function finds the iterator of that element in O(1) time on an average
    // auto it = inorderMap.find(root->key);
    // int inIndex = it->second;

    /**
     * @brief Both at() and operator[] is used to refer the element present at the given position, the only difference is, at() throws out-of-range exception whereas operator[] shows undefined behavior i.e. if operator[] is used to find the value corresponding to key and if key is not present in unordered map, it will first insert the key into the map and then assign the default value ‘0’ corresponding to that key. . 
     * 
     */
    int inIndex = inorderMap.at(root->key);
    //OR
    // int inIndex = inorderMap[root->key];


    //recursive call for left and right child nodes untill whole tree is fullly constructed, then we return the root node to the parent call..
    root->left = constructTree(pre, in, inorderMap, is, inIndex-1);
    root->right = constructTree(pre, in, inorderMap, inIndex+1, ie);

    return root;
}




//To print constructed tree in inorder method
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}  

int main()
{
    int in[]={20,10,40,30,50};
	int pre[]={10,20,30,40,50};

    int n=sizeof(in)/sizeof(in[0]);

    //This hasing technique is specifically to construct tree in O(n) time instead of O(n^2)
    unordered_map<int, int> inorderMap;
    //precomputing values in inorder array to store keys as key and index as value and send it during function call to construct a tree
    for (int i=0; i<n; i++)
        inorderMap.insert(make_pair(in[i], i));

    //to check hash mapping by printing hashmap key value pairs
    // unordered_map<int, int>:: iterator itr;
    // cout << "\nAll Elements : \n";
    // for (itr = inorderMap.begin(); itr != inorderMap.end(); itr++)
    // {
    //     cout << itr->first << "  " << itr->second << endl;
    // }

    // Node *root = constructTree(pre, in, 0, n-1);
    Node *root = constructTree(pre, in, inorderMap, 0, n-1);

    inorder(root);

    return 0;
}