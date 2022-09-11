/**
 * @file LCABinaryTree.cpp
 * @author ADITYA BHARDWAJ
 * @brief We are given a Binary Tree and two values inside it. We need to find out Lowest Common Ancestor of these two values. Ancestor of a node is node itself, its parents, its parents of parents and so on..
 * @version 0.1
 * @date 2022-09-11 03:56 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
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
 * @brief 
 *      I/P:
 *                 10
 *               /    \
 *              20    30
 *                  /    \
 *                40     50
 *              /      /    \
 *            60     70     80
 *  
 *          n1 = 60, n2 = 70
 *  
 *      O/P:  30 (Lowest Level Common Ancestor in Binary Tree for 60 and 70 is 30)
 *      
 *      More Examples:
 *          LCA(20, 80) = 10         
 *          LCA(80, 30) = 30         
 *          LCA(70, 80) = 50  
 *  
 *  NOTE: LOWEST COMMON ANCESTOR PROBLEM IS ALSO USEFUL TO FIND OUT DISTANCE BETWEEN TWO NODES.
 *      Suppose, We want to know the distance between 60 and 70. We can find the lowest common 
 *      ancestor, then the distance would be distance from  60 to 30 (LCA) and the distance from 30 
 *      (LCA) to 70.      
 * 
 * 
 */

/**
 * @brief NAIVE SOLUTION:
 *          
 *      The idea is to build two path arrays. Path1 array has path from root to the first node(n1) 
 *      and path2 array has path from root to the second node(n2).
 * 
 *      Once, we have filled this two path arrays, our task is really simple, we simply need to     
 *      traverse both the arrays while we are seeing common ancestor. So, the last common node in two 
 *      path arrays we see is our lowest common ancestor.
 *      
 *      eg: 
 *          I/P:
 * 
 *                      10
 *                    /   \
 *                  50    60
 *                /   \
 *              70     20
 *             /     /   \
 *           40    90    80
 *                /
 *              30
 * 
 *        n1 = 30, n2 = 80
 * 
 * 
 *      O/P: 
 *          path1[] = {10, 50, 20, 90, 30}
 *          path2[] = {10, 50, 20, 80}
 * 
 *      => 20 is the lowest common ancestor here
 * 
 */

/*
    TIME COMPLEXITY: findpath1 + findpath2 + finding lca in loop
                        ⊖(n)  +   ⊖(n)   +    O(n)
                        
                        :⊖(n)

    It requires three traversals of a tree to find path1 and path2 and then finding LCA from path1 and path2 Arrays

    AUXILIARY SPACE: O(n) for storing the path1 and path2 

    NOTE: WE WILL SOLVE IT IN A WAY THAT WE DO ONLY ONE TRAVERSAL OF A TREE AND NO EXTRA ARRAY. FOR THIS, WE WILL ASSUME THAT BOTH THE KEYS ARE PRESENT IN THE TREE. WE DON'T NEED TO HANDLE THE CASE WHEN KEYS ARE NOT PRESENT IN THE TREE. UNDER THIS ASSUMPTION, WE CAN SOLVE THIS PROBLEM IN ONE TRAVERSAL OF THE BINARY TREE
*/


//this function finds path between root and the given node and store it in the path array and returns true if given node is present in the tree
// bool findPath(Node *root, vector<Node*> &path, int n)
// {
//     if (root == NULL) 
//         return false;
    
//     path.push_back(root);

//     if (root->key == n)
//         return true;

//     if (findPath(root->left, path, n) || findPath(root->right, path, n))
//         return true;
    
//     path.pop_back();

//     return false;

// }

// Node* LCA(Node *root, int n1, int n2)
// {
//     vector<Node*> path1, path2;

//     if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
//         return NULL;
    
//     //to find the LCA from finding least common ancestor from comparing path1 and path2 arrays
//     for (int i=0; i<path1.size()-1 && i<path2.size()-1; i++)
//         if (path1[i+1]!=path2[i+1])
//             return path1[i];

//     return NULL;

// }

/**
 * @brief EFFICIENT SOLUTION:
 *       
 *  1.) Requires one travesal and ⊝(h) extra space for the recursive traversal.
 *  2.) Assumes that both n1 and n2 exist in the tree. Doesn't give correct result when only one (n1 or n2) exists. 
 *      For example:  n1 exists in the binary tree and n2 doesn't exist. In this particular case, it should be returning null because there is no lca existing in the binary tree, but it returns pointer to or reference to the existing key.
 * 
 * 
 * @details IDEA:
 *      We do normal recursive traversal. We have the following cases for every node:
 *  1.) If it is same as n1 or n2.
 *  2.) If one of its subtrees contains n1 and other contains n2.
 *  3.) If one its subtrees contains both n1 and n2.
 *  4.) If none of its substrees contain any of n1 and n2.
 * 
 * Example of above cases:
 *                  10
 *                /    \
 *              20     30
 *                    /  \
 *                  50   60
 *                 /    /  \
 *               70   80   90
 *                          \
 *                          40
 * 
 *  1.) n1 = 10, n2 = 40, curr_node = 10     [returns 10 as it is the current node and n1 is also 10]
 *  2.) n1 = 80, n2 = 40, curr_node = 60     [returns 60 as only LCA will have n1 in one subtree and n2 in its another subtree, eg: 30 is not lca as 80 and 40 are present in its same subtree and 20 0r 50 doesn't have n1 and n2 in its subtree]
 *  3.) n1 = 80, n2 = 40, curr_node = 30 OR (10)    [returns what its subtree will return as its subtree has n1 and n2 present in it so, it will return the correct lca to this]
 *  4.) n1 = 10, n2 = 40, curr_node = 20 OR (50)    [returns null as n1 and n2 are not present in its subtree]
 *  
 */

/*
    TIME COMPLEXITY: ⊖(n)
    AUXILIARY SPACE: ⊖(h)

    NOTE: Time Complexity wise, both naive and efficient solution are same. They both take linear time, but this solution requires only one traversal of a binary tree. Also, it requires less space in the worst case.
*/

//this function is based on the assumption that both keys n1 and n2 are present in the given binary tree otherwise it will not give correct value when either of them is not present.
Node* LCA(Node *root, int n1, int n2)
{
    //4th case (base case) - If none of its substrees contain any of n1 and n2.
    if (root == NULL)
        return NULL;

    //1st case - If it is same as n1 or n2.
    if (root->key == n1 || root->key == n2)
        return root;

    Node* lca1 = LCA(root->left, n1, n2);
    Node* lca2 = LCA(root->right, n1, n2);

    //2nd case - If one of its subtrees contains n1 and other contains n2.
    if (lca1 != NULL && lca2 != NULL)
        return root;
    
    //3rd case - If one its subtrees contains both n1 and n2.
    if (lca1!=NULL)
        return lca1;
    //this will return lca2 when lca2!= null or if lca1 and lca2 is null
    else
        return lca2;

}

/**
    @brief DRY RUN(EFFICIENT SOLUTION):
 *              10
 *             /  \
 *           20  30
 *              /  \
 *            40   50
 *  
 *          n1 = 40, n2 = 50
 *      
 *      LCA(10) [returns 30 as the final answer to parent call] (lca1 = null, lca2 = 30) 
 *          -> LCA(20) [returns NULL to its parent call] (lca1 = lca2 = NULL)
 *                  -> LCA(NULL)    
 *                  -> LCA(NULL)
 *          -> LCA(30) [returns reference Node of 30 to its parent call] (lca1 = 40, lca2 = 50)
 *                  -> LCA(40) [returns reference Node of 40 to its parent call]    
 *                  -> LCA(50) [returns reference Node of 50 to its parent call]    
 *                  
*/

int main()
{

    /**
     * @brief 
     *          10
     *         /  \
     *        20  30
     *           /  \
     *         40   50
     */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    
    // int n1 = 20, n2 = 50;
    int n1 = 40, n2 = 50;

    Node *LeastCommonAncestor = LCA(root, n1, n2);

    cout << LeastCommonAncestor->key << endl;

    return 0;
}