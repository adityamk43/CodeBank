
/**
 * @file BinaryTreeFromPreorderAndInOrder.java
 * @author ADITYA BHARDWAJ
 * @brief WE WILL NEED A COMBINATION OF EITHER PREORDER AND INORDER 
 *        OR POSTORDER AND INORDER TO CONSTRUCT BINARY TREE FROM IT.
 *  
 *      **WITHOUT INORDER ARRAY, WE CANNOT CONSTRUCT A BINARY TREE, (EG:- PREORDER AND POSTORDER 
 *        CANNOT CONSTRUCT BINARY TREE AS WE WILL NEED INORDER DATA WHICH WILL TELL LEFT AND RIGHT 
 *        CHILD NODES OF THE ROOT OF TREE)
 * @version 0.1
 * @date 2022-09-10 07:35 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
    TIME COMPLEXITY: Theta(n) 
    AUXILIARY SPACE: Theta(h)   h = height of binary tree (h+1)
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

import java.util.HashMap;

class Node {

    int key;
    Node left;
    Node right;

    Node(int key) {
        this.key = key;
        ;
    }
}

class BinaryTreeFromPreorderAndInOrder {

    static int preIndex = 0;

    static Node constructTree(int pre[], int in[], HashMap<Integer, Integer> inorderMap, int is, int ie) {
        if (is > ie)
            return null;

        // as explained earlier, preorder has stores data as first root then left then
        // right child node
        Node root = new Node(pre[preIndex++]);

        // O(1) operation to retreive value using key from hashmap
        int inIndex = inorderMap.get(root.key);

        // recursive call for left and right child nodes untill whole tree is fullly
        // constructed, then we return the root node to the parent call..
        root.left = constructTree(pre, in, inorderMap, is, inIndex - 1);
        root.right = constructTree(pre, in, inorderMap, inIndex + 1, ie);

        return root;
    }

    //BT FROM POSTORDER AND INORDER
    static int postIndex;
    static Node constructTreePostOrderInOrder(int post[], int in[], HashMap<Integer, Integer> inorderMap, int is, int ie) {
        if (is > ie || postIndex < 0)
            return null;

        // as explained earlier, postorder has stores data as first root then left then
        // right child node
        Node root = new Node(post[postIndex--]);

        // O(1) operation to retreive value using key from hashmap
        int inIndex = inorderMap.get(root.key);

        // recursive call for left and right child nodes untill whole tree is fullly
        // constructed, then we return the root node to the parent call..
        root.right = constructTreePostOrderInOrder(post, in, inorderMap, inIndex + 1, ie);
        root.left = constructTreePostOrderInOrder(post, in, inorderMap, is, inIndex - 1);

        return root;
    }

    static void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.key + " ");
            inorder(root.right);
        }
    }

    public static void main(String[] args) {

         /*
            8
            4 8 2 5 1 6 3 7
            8 4 5 2 6 7 3 1
        */
        
        // int in[] = { 20, 10, 40, 30, 50 };
        // int pre[] = { 10, 20, 30, 40, 50 };
        // int post[] = {20, 40, 50, 30, 10};

        int in[] = { 4, 8, 2, 5, 1, 6, 3, 7};
        int pre[] = {1, 2, 4, 8, 5, 3, 6, 7};
        int post[] = {8, 4, 5, 2, 6, 7, 3, 1};

        int n = in.length;

        // This hashing technique is specifically to construct tree in O(n) time instead
        // of O(n^2)
        HashMap<Integer, Integer> inorderMap = new HashMap<>();

        for (int i = 0; i < n; i++)
            inorderMap.put(in[i], i);

        System.out.println("BINARY TREE FROM PREORDER AND INORDER"); 
        Node rootPreorder = constructTree(pre, in, inorderMap, 0, n - 1);
        inorder(rootPreorder);

        //BT FROM POSTORDER AND INORDER
        System.out.println("\n\nBINARY TREE FROM POSTORDER AND INORDER"); 
        BinaryTreeFromPreorderAndInOrder.postIndex = n-1;
        Node rootPostorder = constructTreePostOrderInOrder(post, in, inorderMap, 0, n - 1);

        inorder(rootPostorder);

    }
}