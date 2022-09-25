/*
 * Find Common Nodes in two BSTs
 * EasyAccuracy: 49.82%Submissions: 24384Points: 2
 * Given two Binary Search Trees. Find the nodes that are common in both of
 * them, ie- find the intersection of the two BSTs.
 * 
 * Example 1:
 * 
 * Input:
 * BST1:
 * 5
 * / \
 * 1 10
 * / \ /
 * 0 4 7
 * \
 * 9
 * BST2:
 * 10
 * / \
 * 7 20
 * / \
 * 4 9
 * Output: 4 7 9 10
 * 
 * Example 2:
 * 
 * Input:
 * BST1:
 * 10
 * / \
 * 2 11
 * / \
 * 1 3
 * BST2:
 * 2
 * / \
 * 1 3
 * Output: 1 2 3
 * 
 * Input:
 * 1
 * 36 22 49 7 23 45 50 2 14 N 33 42 47
10 9 23 2 N 14 29 1 4 11 15 27 47 N N 3 5
    Output:
        2 14 23 47 
 * Your Task:
 * You don't need to read input or print anything. Your task is to complete the
 * function findCommon() that takes roots of the two BSTs as input parameters
 * and returns a list of integers containing the common nodes in sorted order.
 * 
 * Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2
 * BSTs.
 * Expected Auxiliary Space: O(H1 + H2) where H1 and H2 are the heights of the 2
 * BSTs.
 * 
 * Constraints:
 * 1 <= Number of Nodes <= 105
 * 
 */

//{ Driver Code Starts
//Initial Template for Java

import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;
// import java.math.*;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

// } Driver Code Ends
// User function Template for Java

class Solution {
    // Function to find the nodes that are common in both BST.
    static void inorder(Node root, HashMap<Integer, Integer> map) {
        if (root == null)
            return;

        inorder(root.left, map);

        Integer count = map.get(root.data);

        if (count == null) {
            map.put(root.data, 1);
        } else {
            map.put(root.data, count + 1);

        }

        inorder(root.right, map);

    }

    public static ArrayList<Integer> findCommon(Node root1, Node root2) {
        // code here
        ArrayList<Integer> al = new ArrayList<>();

        if (root1 == null || root2 == null)
            return al;

        HashMap<Integer, Integer> map = new HashMap<>();

        inorder(root1, map);
        inorder(root2, map);

        for (Map.Entry<Integer, Integer> mapElement : map.entrySet()) {
            if (mapElement.getValue() >= 2)
                al.add(mapElement.getKey());

            // System.out.println(map.get(root.data));
        }

        Collections.sort(al);

        return al;
    }
}

// { Driver Code Starts.
class FindCommonNodesTwoBSTs {
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
            Node root1 = buildTree(s);

            s = br.readLine();
            Node root2 = buildTree(s);

            // Solution g = new Solution();
            ArrayList<Integer> res = new ArrayList<Integer>();
            // res = g.findCommon(root1, root2);
            res = Solution.findCommon(root1, root2);
            for (int i = 0; i < res.size(); i++)
                System.out.print(res.get(i) + " ");
            System.out.println();

            t--;
        }
    }
}
// } Driver Code Ends