/**@file LevelOrderToBST.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-11-14 10:30 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 * Convert Level Order Traversal to BST
MediumAccuracy: 71.16%Submissions: 16330Points: 4
Given an array of size N containing level order traversal of a BST. The task is to complete the function constructBst(), that construct the BST (Binary Search Tree) from its given level order traversal.

Example 1:

Input:
N = 9
BST[] = {7,4,12,3,6,8,1,5,10}
Output: 7 4 3 1 6 5 12 8 10
Explanation: After constructing BST, the
preorder traversal of BST is
7 4 3 1 6 5 12 8 10.
Example 2:

Input:
N = 6
BST[] = {1,3,4,6,7,8}
Output: 1 3 4 6 7 8
Explanation: After constructing BST, the
preorder traversal of BST is 1 3 4 6 7 8.
Your Task:
Your task is to complete the function constructBst() which has two arguments, first as the array containing level order traversal of BST and next argument as the length of array which return the root of the newly constructed BST. The preorder traversal of the tree is printed by the driver's code.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 103
 */

//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

// import java.io.*;
import java.util.*;

class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class LevelOrderToBST {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            GFG obj = new GFG();
            Node tree = obj.constructBST(arr);
            preorder(tree);
            System.out.println();
        }

        sc.close();
    }

    public static void preorder(Node root) {
        if (root == null) {
            return;
        }

        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }
}

// } Driver Code Ends

// User function Template for Java

class GFG {
    // My Function
    // TIME COMPLEXITY: O(N*H)

    // Function to construct the BST from its given level order traversal.
    // public Node insertBST(Node root, int x)
    // {
    // if (root == null)
    // return new Node(x);

    // else if (root.data > x)
    // root.left = insertBST(root.left, x);

    // else if (root.data < x)
    // root.right = insertBST(root.right, x);

    // //if key is already present in the given BST Or simply return after linking
    // leaf node with the given key
    // return root;

    // }

    //// Time Complexity: O(N*H)
    // public Node constructBST(int[] arr)
    // {
    // //Write your code here
    // Node root = null;

    // for (int i=0; i<arr.length; i++)
    // root = insertBST(root, arr[i]);

    // return root;
    // }

    // Optimised Version T.C. = O(N)
    class NodeDetails {
        Node ptr;
        int max;
        int min;

        NodeDetails(Node ptr) {
            this.ptr = ptr;
            this.max = Integer.MAX_VALUE;
            this.min = Integer.MIN_VALUE;
        }
    }

    public Node constructBST(int[] arr) {
        // Write your code here
        if (arr.length == 0)
            return null;

        int i = 0;
        Node root = new Node(arr[i++]);

        Queue<NodeDetails> q = new LinkedList<>();
        q.add(new NodeDetails(root));

        NodeDetails nd;

        while (i != arr.length) {
            nd = q.poll();

            if (i < arr.length && nd.min < arr[i] && arr[i] < nd.ptr.data) {
                Node curr = new Node(arr[i++]);
                nd.ptr.left = curr;

                NodeDetails newND = new NodeDetails(curr);
                newND.max = nd.ptr.data;
                newND.min = nd.min;

                q.add(newND);

            }

            if (i < arr.length && nd.ptr.data < arr[i] && arr[i] < nd.max) {
                Node curr = new Node(arr[i++]);
                nd.ptr.right = curr;

                NodeDetails newND = new NodeDetails(curr);
                newND.min = nd.ptr.data;
                newND.max = nd.max;

                q.add(newND);

            }
        }

        return root;
    }
}