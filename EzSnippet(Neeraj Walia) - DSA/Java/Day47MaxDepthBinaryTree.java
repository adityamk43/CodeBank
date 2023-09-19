/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 47
 * @author ADITYA BHARDWAJ
 *         19/09/2023 10:27PM
 * 
 * @description
 * 
 *              104. Maximum Depth of Binary Tree
 *              Solved
 *              Easy
 *              Topics
 *              Companies
 *              Given the root of a binary tree, return its maximum depth.
 * 
 *              A binary tree's maximum depth is the number of nodes along the
 *              longest path from the root node down to the farthest leaf node.
 * 
 * 
 * 
 *              Example 1:
 * 
 * 
 *              Input: root = [3,9,20,null,null,15,7]
 *              Output: 3
 *              Example 2:
 * 
 *              Input: root = [1,null,2]
 *              Output: 2
 * 
 * 
 *              Constraints:
 * 
 *              The number of nodes in the tree is in the range [0, 104].
 *              -100 <= Node.val <= 100
 *              Accepted
 *              2.6M
 *              Submissions
 *              3.5M
 *              Acceptance Rate
 *              74.5%
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
 *          41.37MB
 *          Beats 66.47%of users with Java
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
    public int maxDepth(TreeNode root) {

        if (root == null)
            return 0;

        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}

class Day47MaxDepthBinaryTree {
    public static void main(String[] args) {
        Solution obj = new Solution();

        // Test Cases

        // Case 1
        // TreeNode root=new TreeNode(3);
        // root.left=new TreeNode(9);
        // root.right=new TreeNode(20);
        // root.right.left=new TreeNode(15);
        // root.right.right=new TreeNode(7);

        // Case 2
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);

        System.out.println(obj.maxDepth(root));
    }
}