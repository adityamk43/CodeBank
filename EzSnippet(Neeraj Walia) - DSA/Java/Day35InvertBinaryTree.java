/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 35
 * @author ADITYA BHARDWAJ
 * 03/09/2023 10:10PM
 * 
 * @description
 * 226. Invert Binary Tree
    Easy
    13K
    182
    Companies
    Given the root of a binary tree, invert the tree, and return its root.

    

    Example 1:


    Input: root = [4,2,7,1,3,6,9]
    Output: [4,7,2,9,6,3,1]
    Example 2:


    Input: root = [2,1,3]
    Output: [2,3,1]
    Example 3:

    Input: root = []
    Output: []
    

    Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
    Accepted
    1.7M
    Submissions
    2.2M
    Acceptance Rate
    75.6%

    @returns
    Accepted
    Editorial

    Details
    0ms
    Beats 100.00%of users with Java

    Memory
    Details
    39.71MB
    Beats 82.34%of users with Java
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
};

class Solution {
    public TreeNode invertTree(TreeNode root) {

        if (root == null)
            return null;

        TreeNode left = invertTree(root.left);
        TreeNode right = invertTree(root.right);

        root.right = left;
        root.left = right;

        return root;
    }

};
  

public class Day35InvertBinaryTree {

    // custom function to print Binary Tree
    public static void printBinaryTree(TreeNode root) {
        System.out.print(root.val + " ");

        if (root.left != null)
            printBinaryTree(root.left);
        if (root.right != null)
            printBinaryTree(root.right);
    }

    public static void main(String args[])
    {
        
        // Test Cases
        
        //Case 1
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(9);
        
        //Case 2
        TreeNode root1 = new TreeNode(2);
        root1.left = new TreeNode(1);
        root1.right = new TreeNode(3);

        Solution obj = new Solution();
        TreeNode invertedRoot = obj.invertTree(root);
        TreeNode invertedRoot1 = obj.invertTree(root1);

        printBinaryTree(invertedRoot);
        System.out.println();
        System.out.println("----------");
        printBinaryTree(invertedRoot1);
    }

}
