/* @Author: ADITYA BHARDWAJ
    @Date: 12-09-2022 12:04 AM


 * Diameter of a Binary Tree
 * EasyAccuracy: 50.01%Submissions: 100k+Points: 2
 * Lamp
 * This problem is part of GFG SDE Sheet. Click here to view more.
 * 
 * The diameter of a tree (sometimes called the width) is the number of nodes on
 * the longest path between two end nodes. The diagram below shows two trees
 * each with diameter nine, the leaves that form the ends of the longest path
 * are shaded (note that there is more than one path in each tree of length
 * nine, but no path longer than nine nodes).
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 1
 * / \
 * 2 3
 * Output: 3
 * Example 2:
 * 
 * Input:
 * 10
 * / \
 * 20 30
 * / \
 * 40 60
 * Output: 4
 * Your Task:
 * You need to complete the function diameter() that takes root as parameter and
 * returns the diameter.
 * 
 * Expected Time Complexity: O(N).
 * Expected Auxiliary Space: O(Height of the Tree).
 * 
 * Constraints:
 * 1 <= Number of nodes <= 10000
 * 1 <= Data of a node <= 1000
 */

//{ Driver Code Starts
// Initial Template for Java

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

class DiameterBinaryTree {

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
            if (i >= ip.length) break;

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
    static void printInorder(Node root) {
        if (root == null) return;

        printInorder(root.left);
        System.out.print(root.data + " ");

        printInorder(root.right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t > 0) {
            String s = br.readLine();
            Node root = buildTree(s);
            Solution g = new Solution();
            System.out.println(g.diameter(root));
            t--;
        }
    }
}

// } Driver Code Ends


// User function Template for Java

/*class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}*/
class d{
    int res;
    
    d(int res)
    {
        this.res = res;
    }
}

class Solution {
    // Function to return the diameter of a Binary Tree.
    
    static int myDiameter(Node root, d dia) {
        // Your code here
        if (root == null)
            return 0;
    
        int lh = myDiameter(root.left, dia);
        int rh = myDiameter(root.right, dia);

        dia.res = Math.max(dia.res, 1 + lh + rh);
    
        return 1 + Math.max(lh, rh);
    }
    
    /*
     * I/P:
     *  1
        10 20 30 40 60
     */
    int diameter(Node root)
    {
        d dia = new d(0);
        
        myDiameter(root, dia);
        return dia.res;
    }
    
}
