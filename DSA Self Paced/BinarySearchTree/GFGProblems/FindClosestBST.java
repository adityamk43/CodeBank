/**
 * @file FindClosestBST.java
 * @author ADITYA BHARDWAJ
 * @brief
 * @version 0.1
 * @date 2022-11-14 10:32 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 *            Find the Closest Element in BST
 *            MediumAccuracy: 47.51%Submissions: 44373Points: 4
 *            Given a BST and an integer. Find the least absolute difference
 *            between any node value of the BST and the given integer.
 * 
 *            Example 1:
 * 
 *            Input:
 *            10
 *            / \
 *            2 11
 *            / \
 *            1 5
 *            / \
 *            3 6
 *            \
 *            4
 *            K = 13
 *            Output: 2
 *            Explanation: K=13. The node that has
 *            value nearest to K is 11. so the answer
 *            is 2
 *            Example 2:
 * 
 *            Input:
 *            8
 *            / \
 *            1 9
 *            \ \
 *            4 10
 *            /
 *            3
 *            K = 9
 *            Output: 0
 *            Explanation: K=9. The node that has
 *            value nearest to K is 9. so the answer
 *            is 0.
 *            Your Task:
 *            You don't need to read input or print anything. Your task is to
 *            complete the function minDiff() that takes the root of the BST and
 *            an integer K as its input and returns the minimum absolute
 *            difference between any node value of the BST and the integer K.
 * 
 *            Expected Time Complexity: O(Height of the BST).
 *            Expected Auxiliary Space: O(Height of the BST).
 * 
 *            Constraints:
 *            1 <= Number of nodes <= 100000
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

class FindClosestBST {
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

            // Get the current node's value from the string
            String currVal = s[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
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

                // Create the right child for the current node
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
            Node root = buildTree(s);

            int k = Integer.parseInt(br.readLine().trim());

            // Solution T = new Solution();
            System.out.println(Solution.minDiff(root, k));
            t--;
        }
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    // Function to find the least absolute difference between any node
    // value of the BST and the given integer.
    public static Node floorBST(Node root, int floor_val) {
        Node res = null;
        Node curr = root;

        while (curr != null) {
            if (curr.data == floor_val)
                return curr;

            else if (floor_val <= curr.data)
                curr = curr.left;

            else if (floor_val >= curr.data) {
                res = curr;
                curr = curr.right;
            }
        }

        return res;
    }

    public static Node ceilBST(Node root, int ceil_val) {
        Node res = null;
        Node curr = root;

        while (curr != null) {
            if (curr.data == ceil_val)
                return curr;

            else if (ceil_val >= curr.data)
                curr = curr.right;

            else if (ceil_val <= curr.data) {
                res = curr;
                curr = curr.left;
            }
        }

        return res;
    }

    static int minDiff(Node root, int K) {
        // Write your code here
        Node ceilNode = ceilBST(root, K);
        Node floorNode = floorBST(root, K);

        int minDiffVal = Integer.MAX_VALUE;

        if (ceilNode != null)
            minDiffVal = Math.abs(K - ceilNode.data);

        if (floorNode != null)
            minDiffVal = Math.min(Math.abs(K - floorNode.data), minDiffVal);

        if (minDiffVal == Integer.MAX_VALUE)
            minDiffVal = 0;

        return minDiffVal;

    }
}
