/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 48
 * @author ADITYA BHARDWAJ
 *         21/09/2023 11:24AM
 * 
 * @description
 * 
 *              543. Diameter of Binary Tree
 *              Solved
 *              Easy
 *              Topics
 *              Companies
 *              Given the root of a binary tree, return the length of the
 *              diameter of the tree.
 * 
 *              The diameter of a binary tree is the length of the longest path
 *              between any two nodes in a tree. This path may or may not pass
 *              through the root.
 * 
 *              The length of a path between two nodes is represented by the
 *              number of edges between them.
 * 
 * 
 * 
 *              Example 1:
 * 
 * 
 *              Input: root = [1,2,3,4,5]
 *              Output: 3
 *              Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
 *              Example 2:
 * 
 *              Input: root = [1,2]
 *              Output: 1
 * 
 * 
 *              Constraints:
 * 
 *              The number of nodes in the tree is in the range [1, 104].
 *              -100 <= Node.val <= 100
 *              Accepted
 *              1.2M
 *              Submissions
 *              2M
 *              Acceptance Rate
 *              58.0%
 * 
 * @returns
 *          Accepted
 * 
 *          Runtime
 *          Details
 *          0ms
 *          Beats 100.00%of users with Java
 * 
 *          Memory
 *          Details
 *          41.10MB
 *          Beats 98.98%of users with Java
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
// Helper function build Binary tree
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

    @Override
    public String toString() {
        return "TreeNode{" +
                "val=" + val +
                ", left=" + (left != null ? left.val : "null") +
                ", right=" + (right != null ? right.val : "null") +
                '}';
    }
}

class Solution {

    private int maxDiameter;

    Solution() {
        this.maxDiameter = 0;
    }

    public int calculateHeight(TreeNode root) {
        if (root == null)
            return 0;

        int left = calculateHeight(root.left);
        int right = calculateHeight(root.right);

        maxDiameter = Math.max(maxDiameter, left + right);

        return 1 + Math.max(left, right);

    }

    public int diameterOfBinaryTree(TreeNode root) {

        calculateHeight(root);

        return maxDiameter;
    }
}

class Day48DiameterofBinaryTree {
    public static void main(String[] args) {

        Solution obj = new Solution();

        // Test Cases

        // Case 1
        // TreeNode root=new TreeNode(1);
        // root.left=new TreeNode(2);
        // root.right=new TreeNode(3);
        // root.left.left=new TreeNode(4);
        // root.left.right=new TreeNode(5);

        // Case 2
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);

        System.out.println(obj.calculateHeight(root));

    }
}