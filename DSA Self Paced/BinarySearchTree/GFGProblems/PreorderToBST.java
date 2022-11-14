/**
 * @file PreorderToBST.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-11-14 10:27 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 * Preorder to BST
MediumAccuracy: 59.2%Submissions: 45083Points: 4
Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the exact BST from it's given preorder traversal. 
In Pre-Order traversal, the root node is visited before the left child and right child nodes.

Example 1:

Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40
Example 2:

Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40
Your Task:
You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 103
1 <= arr[i] <= 104
 */

//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;

class Node {
    int data;
    Node left, right;

    Node(int d) {
        data = d;
        left = right = null;
    }
}

class PreorderToBST {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String[] inputline = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputline[0]);
            inputline = br.readLine().trim().split(" ");
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputline[i]);
            }

            Node res = post_order(arr, n);
            printPostorder(res);
            System.out.println();
        }
    }

    // } Driver Code Ends
    // User function Template for Java

    // MY SOLUTION
    // TIME COMPLEXITY: O(N*H)

    // Function that constructs BST from its preorder traversal.
    // public static Node insertBST(Node root, int x)
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

    // public static Node post_order(int pre[], int size)
    // {
    // //Your code here
    // Node root = null;

    // for (int i=0; i<pre.length; i++)
    // root = insertBST(root, pre[i]);

    // return root;
    // }

    // OTHER SOLUTION
    // TIME COMPLEXITY: O(N)
    public static Node post_order(int pre[], int size) {
        // Your code here
        if (pre.length == 0)
            return null;

        Node root = new Node(pre[0]);

        Stack<Node> s = new Stack<>();
        s.push(root);

        for (int i = 1; i < pre.length; i++) {
            Node temp = null;

            while (!s.isEmpty() && pre[i] > s.peek().data)
                temp = s.pop();

            if (temp != null) {
                temp.right = new Node(pre[i]);
                s.push(temp.right);
            }

            else {
                s.peek().left = new Node(pre[i]);
                s.push(s.peek().left);
            }
        }

        return root;
    }

    // { Driver Code Starts.

    public static void printInorder(Node node) {
        if (node == null) {
            return;
        }
        printInorder(node.left);
        System.out.print(node.data + " ");
        printInorder(node.right);
    }

    public static void printPostorder(Node node) {
        if (node == null) {
            return;
        }
        printPostorder(node.left);
        printPostorder(node.right);
        System.out.print(node.data + " ");
    }

    public static void printPreorder(Node node) {
        if (node == null) {
            return;
        }
        System.out.print(node.data + " ");
        printPreorder(node.left);
        printPreorder(node.right);
    }

}
// } Driver Code Ends