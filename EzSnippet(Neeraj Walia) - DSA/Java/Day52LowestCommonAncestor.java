/**
 * @event Neeraj Walia (EzSnirootrootet) DSA Challenge DAY - 52
 * @author ADITYA BHARDWAJ
 *         28/09/2023 12:01AM
 * 
 * @description
 * 236. Lowest Common Ancestor of a Binary Tree
    Solved
    Medium
    Topics
    Companies
    Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

    According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself)."

    

    Example 1:


    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3
    Explanation: The LCA of nodes 5 and 1 is 3.
    Example 2:


    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    Output: 5
    Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
    Example 3:

    Input: root = [1,2], p = 1, q = 2
    Output: 1
    

    Constraints:

    The number of nodes in the tree is in the range [2, 105].
    -109 <= Node.val <= 109
    All Node.val are unique.
    p != q
    p and q will exist in the tree.
    Accepted
    1.4M
    Submissions
    2.3M
    Acceptance Rate
    60.3%
 * 
 * @returns
 * Accepted

    Runtime
    Details
    6ms
    Beats 97.80%of users with Java

    Memory
    Details
    43.28MB
    Beats 90.82%of users with Java
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
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
    public String

            toString() {
        return "TreeNode{" +
                "val=" + val +
                ", left=" + (left != null ? left.val : "null") +
                ", right=" + (right != null ? right.val : "null") +
                '}';
    }
}

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        // TreeNode curr = root;

        // while (curr!=null)
        // {
        // if (curr.val > p.val && curr.val > q.val)
        // curr=curr.right;
        // else if (curr.val < p.val && curr.val < q.val)
        // curr=curr.left;
        // else
        // break;
        // }

        // return curr;

        if (root == null)
            return null;

        if (root.val == p.val || root.val == q.val)
            return root;

        TreeNode lca1 = lowestCommonAncestor(root.left, p, q);
        TreeNode lca2 = lowestCommonAncestor(root.right, p, q);

        if (lca1 != null && lca2 != null)
            return root;

        if (lca1 != null)
            return lca1;
        else
            return lca2;

    }
}

class Day52LowestCommonAncestor {
    public static void main(String[] args) {

        Solution obj = new Solution();

        // Test Cases

        // Case 1
        // TreeNode root = new TreeNode(3);
        // root.left = new TreeNode(5);
        // root.right = new TreeNode(1);
        // root.left.left = new TreeNode(6);
        // root.left.right = new TreeNode(2);
        // root.left.right.left = new TreeNode(7);
        // root.left.right.right = new TreeNode(4);
        // root.right.left = new TreeNode(0);
        // root.right.right = new TreeNode(8);

        // TreeNode p = new TreeNode(5);
        // TreeNode q = new TreeNode(1);

        // Case 2
        // TreeNode root = new TreeNode(3);
        // root.left = new TreeNode(5);
        // root.right = new TreeNode(1);
        // root.left.left = new TreeNode(6);
        // root.left.right = new TreeNode(2);
        // root.left.right.left = new TreeNode(7);
        // root.left.right.right = new TreeNode(4);
        // root.right.left = new TreeNode(0);
        // root.right.right = new TreeNode(8);

        // TreeNode p = new TreeNode(5);
        // TreeNode q = new TreeNode(4);

        // Case 3
        // TreeNode root = new TreeNode(1);
        // root.left = new TreeNode(2);

        // TreeNode p = new TreeNode(1);
        // TreeNode q = new TreeNode(2);

        // Case 4
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(3);

        TreeNode p = new TreeNode(2);
        TreeNode q = new TreeNode(3);

        System.out.println(obj.lowestCommonAncestor(root, p, q));
    }
}