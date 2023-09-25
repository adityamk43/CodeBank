/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 50
 * @author ADITYA BHARDWAJ
 *         25/09/2023 11:07AM
 * 
 * @description
 * 
    100. Same Tree
    Solved
    Easy
    Topics
    Companies
    Given the ps of two binary trees p and q, write a function to check if they are the same or not.

    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

    

    Example 1:


    Input: p = [1,2,3], q = [1,2,3]
    Output: true
    Example 2:


    Input: p = [1,2], q = [1,null,2]
    Output: false
    Example 3:


    Input: p = [1,2,1], q = [1,1,2]
    Output: false
    

    Constraints:

    The number of nodes in both trees is in the range [0, 100].
    -104 <= Node.val <= 104
    Accepted
    1.7M
    Submissions
    2.9M
    Acceptance Rate
    59.6%
 *
 * 
 * @returns
 * Accepted

    Runtime
    Details
    0ms
    Beats 100.00%of users with Java

    Memory
    Details
    39.40MB
    Beats 98.28%of users with Java
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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null)
            return true;

        if (p == null || q == null)
            return false;

        if (p.val != q.val)
            return false;

        return (isSameTree(p.left, q.left) && isSameTree(p.right, q.right));
    }
}

class Day50SameTree {
    public static void main(String[] args) {
        Solution obj = new Solution();

        // Test Cases

        // Case 1
        TreeNode p = new TreeNode(1);
        p.left = new TreeNode(2);
        p.right = new TreeNode(3);

        TreeNode q = new TreeNode(1);
        q.left = new TreeNode(2);
        q.right = new TreeNode(3);

        // Case 2
        // TreeNode p = new TreeNode(1);
        // p.left = new TreeNode(2);

        // TreeNode q = new TreeNode(1);
        // q.right = new TreeNode(2);

        // Case 3
        // TreeNode p = new TreeNode(1);
        // p.left = new TreeNode(2);
        // p.right = new TreeNode(1);

        // TreeNode q = new TreeNode(1);
        // q.left = new TreeNode(1);
        // q.right = new TreeNode(2);

        System.out.println(obj.isSameTree(p, q));
    }
}