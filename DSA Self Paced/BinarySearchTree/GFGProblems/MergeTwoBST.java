/*
    @file MergeTwoBST.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-11-14 10:26 PM
 * 
 * @copyright Copyright (c) 2022
Merge two BST 's
HardAccuracy: 64.95%Submissions: 36346Points: 8
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.  

Given two BSTs, return elements of both BSTs in sorted form.


Example 1:

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: 
After merging and sorting the
two BST we get 1 2 2 3 3 4 5 6 6 7.
Example 2:

Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: 
After merging and sorting the
two BST we get 2 5 6 8 9 10 11 12.

Your Task:
You don't need to read input or print anything. Your task is to complete the function merge() which takes roots of both the BSTs as its input and returns an array of integers denoting the node values of both the BSTs in a sorted order.


Expected Time Complexity: O(M+N) where M and N are the sizes if the two BSTs.
Expected Auxiliary Space: O(Height of BST1 + Height of BST2).


Constraints:
1 ≤ Number of Nodes ≤ 105
 */

//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
// import java.math.*;

class Node {
    int data;
    Node left, right;

    public Node(int d) {
        data = d;
        left = right = null;
    }
}

class MergeTwoBST {
    static Node buildTree(String str) {
        // Corner Case
        if (str.length() == 0 || str.equals('N'))
            return null;
        String[] s = str.split(" ");

        Node root = new Node(Integer.parseInt(s[0]));
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);

        // Starting from the second element
        int i = 1;
        while (!q.isEmpty() && i < s.length) {
            // Get and remove the front of the queue
            Node currNode = q.remove();

            // Get the curr node's value from the string
            String currVal = s[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the curr node
                currNode.left = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                q.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= s.length)
                break;
            currVal = s[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the curr node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                q.add(currNode.right);
            }

            i++;
        }

        return root;
    }

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t > 0) {
            String s = br.readLine();
            Node root1 = buildTree(s);

            s = br.readLine();
            Node root2 = buildTree(s);

            Solution T = new Solution();
            List<Integer> ans = T.merge(root1, root2);
            for (int i = 0; i < ans.size(); i++)
                System.out.print(ans.get(i) + " ");
            System.out.println();

            t--;
        }
    }
}

// } Driver Code Ends

// User function Template for Java

/*
 * class Node
 * {
 * int data;
 * Node left, right;
 * 
 * public Node(int d)
 * {
 * data = d;
 * left = right = null;
 * }
 * }
 * 
 */
class Solution {

    // MY SOLUTION WITH LESS OPTIMISATION
    // TIME COMPLEXITY: O((M+N)log(M+N))

    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    // public List<Integer> mergeTwoLists(List<Integer> l1, List<Integer> l2)
    // {
    // List<Integer> l = new ArrayList<Integer>();
    // int i=0, j=0;

    // while (i<l1.size() && j<l2.size())
    // {
    // if (l1.get(i) < l2.get(j))
    // {
    // l.add(l1.get(i));
    // i++;
    // }
    // else
    // {
    // l.add(l2.get(j));
    // j++;
    // }
    // }

    // while (i<l1.size())
    // {
    // l.add(l1.get(i++));
    // }

    // while (j<l2.size())
    // {
    // l.add(l2.get(j++));
    // }

    // return l;
    // }

    // public void inorder(Node root, List<Integer> l)
    // {
    // if (root == null)
    // return;

    // inorder(root.left, l);
    // l.add(root.data);
    // inorder(root.right, l);
    // }

    // public List<Integer> merge(Node root1,Node root2)
    // {
    // // Write your code here
    // List<Integer> l = new ArrayList<Integer>();
    // List<Integer> l1 = new ArrayList<Integer>();
    // List<Integer> l2 = new ArrayList<Integer>();

    // inorder(root1, l1);
    // inorder(root2, l2);

    // return mergeTwoLists(l1, l2);

    // }

    // GFG OPTIMISED SOLUTION
    // TIME COMPLEXITY: O(M+N)
    public void inorder(Node root, List<Integer> l) {
        if (root == null)
            return;

        inorder(root.left, l);
        l.add(root.data);
        inorder(root.right, l);
    }

    public Node minValNode(Node root) {
        Node curr = root;

        while (curr.left != null) {
            curr = curr.left;
        }

        return curr;
    }

    public List<Integer> merge(Node root1, Node root2) {
        // Write your code here
        List<Integer> l = new ArrayList<Integer>();

        Node c1 = root1;
        Node c2 = root2;

        if (root1 == null) {
            inorder(root2, l);
            return l;
        }

        if (root2 == null) {
            inorder(root1, l);
            return l;
        }

        Stack<Node> s1 = new Stack<>();
        Stack<Node> s2 = new Stack<>();

        while (c1 != null || !s1.isEmpty() || c2 != null || !s2.isEmpty()) {
            if (c1 != null || c2 != null) {
                if (c1 != null) {
                    s1.push(c1);
                    c1 = c1.left;
                }

                if (c2 != null) {
                    s2.push(c2);
                    c2 = c2.left;
                }
            }

            else {
                if (s1.isEmpty()) {
                    while (!s2.isEmpty()) {
                        c2 = s2.peek();
                        s2.pop();

                        c2.left = null;

                        inorder(c2, l);

                    }

                    return l;

                }

                if (s2.isEmpty()) {
                    while (!s1.isEmpty()) {
                        c1 = s1.peek();
                        s1.pop();

                        c1.left = null;

                        inorder(c1, l);

                    }

                    return l;

                }

                c1 = s1.peek();
                c2 = s2.peek();
                s1.pop();
                s2.pop();

                if (c1.data < c2.data) {
                    l.add(c1.data);
                    c1 = c1.right;
                    s2.push(c2);
                    c2 = null;
                }

                else {
                    l.add(c2.data);
                    c2 = c2.right;
                    s1.push(c1);
                    c1 = null;
                }

            }

        }

        return l;

    }
}
