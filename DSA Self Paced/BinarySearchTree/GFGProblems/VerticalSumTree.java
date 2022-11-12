/**
 * @file VerticalSumTree.java
 * @author ADITYA BHARDWAJ
 * @brief 
 * Vertical sum
EasyAccuracy: 64.76%Submissions: 23943Points: 2
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines starting from left-most vertical line to right-most vertical line.

Example 1:

Input:
       1
    /   \
  2      3
 / \    / \
4   5  6   7
Output: 
Explanation:
The tree has 5 vertical lines
Vertical-Line-1 has only one node
4 => vertical sum is 4
Vertical-Line-2: has only one node
2=> vertical sum is 2
Vertical-Line-3: has three nodes:
1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3
=> vertical sum is 3
Vertical-Line-5: has only one node 7
=> vertical sum is 7
Your Task:
You don't need to take input. Just complete the function verticalSum() that takes root node of the tree as parameter and returns an array containing the vertical sum of tree from left to right.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of nodes<=1000
 * 
 * @version 0.1
 * @date 2022-11-13 12:18 AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//{ Driver Code Starts
//Initial Template for Java

import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class VerticalSumTree {

    static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length)
                break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t > 0) {
            String s = br.readLine();
            Node root = buildTree(s);
            Solution g = new Solution();

            ArrayList<Integer> res = g.verticalSum(root);
            for (Integer num : res)
                System.out.print(num + " ");
            System.out.println();
            t--;

        }
    }

}

// } Driver Code Ends

/*
 * Complete the function below
 * Node is as follows:
 * class Node{
 * int data;
 * Node left, right;
 * Node(int item)
 * {
 * data = item;
 * left = right = null
 * }
 * }
 */
class Solution {

    public void myVerticalSum(Node root, TreeMap<Integer, Integer> m, int hd) {
        if (root == null)
            return;

        myVerticalSum(root.left, m, hd - 1);

        int pSum = (m.get(hd) == null) ? 0 : m.get(hd);
        m.put(hd, pSum + root.data);

        myVerticalSum(root.right, m, hd + 1);

    }

    public ArrayList<Integer> verticalSum(Node root) {
        // add your code here
        ArrayList<Integer> al = new ArrayList<>();

        TreeMap<Integer, Integer> m = new TreeMap<>();

        myVerticalSum(root, m, 0);

        for (Map.Entry<Integer, Integer> sum : m.entrySet())
            al.add(sum.getValue());
        // System.out.print(sum.getValue() + " ");

        return al;

    }
}
