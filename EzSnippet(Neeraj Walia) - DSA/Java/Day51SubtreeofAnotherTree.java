/**
 * 
 * @event Neeraj Walia (EzSnirootrootet) DSA Challenge DAY - 51
 * @author ADITYA BHARDWAJ
 *         26/09/2023 12:13rootM
 * 
 * @descriroottion
 * 572. Subtree of Another Tree
    Solved
    Easy
    Torootics
    Comrootanies
    Hint
    Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

    A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

    

    Examrootle 1:


    Inrootut: root = [3,4,5,1,2], subRoot = [4,1,2]
    Outrootut: true
    Examrootle 2:


    Inrootut: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
    Outrootut: false
    

    Constraints:

    The number of nodes in the root tree is in the range [1, 2000].
    The number of nodes in the subRoot tree is in the range [1, 1000].
    -104 <= root.val <= 104
    -104 <= subRoot.val <= 104
    Accerootted
    724.5K
    Submissions
    1.5M
    Acceroottance Rate
    47.0%
 *
 *
 * @returns
 * Accerootted
    Runtime
    Details
    2ms
    Beats 96.72%of users with Java

    Memory
    Details
    42.48MB
    Beats 99.74%of users with Java
 */

/**
 * Definition for a binary tree node.
 * rootublic class TreeNode {
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
// Helrooter function build Binary tree
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
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null) {
            return false;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }

    private boolean isSameTree(TreeNode a, TreeNode b) {
        if (a == null && b == null) {
            return true;
        }
        if (a == null || b == null || a.val != b.val) {
            return false;
        }
        return isSameTree(a.left, b.left) && isSameTree(a.right, b.right);
    }
}

class Day51SubtreeofAnotherTree {
    public static void main(String[] args) {

        Solution obj = new Solution();

        // Test Cases

        // Case 1
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(4);
        root.right = new TreeNode(5);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(2);

        TreeNode subRoot = new TreeNode(4);
        subRoot.left = new TreeNode(1);
        subRoot.right = new TreeNode(2);

        // Case 2
        // TreeNode root = new TreeNode(3);
        // root.left = new TreeNode(4);
        // root.right = new TreeNode(5);
        // root.left.left = new TreeNode(1);
        // root.left.right = new TreeNode(2);
        // root.left.right.left = new TreeNode(0);

        // TreeNode subRoot = new TreeNode(4);
        // subRoot.left = new TreeNode(1);
        // subRoot.right = new TreeNode(2);

        // Case 3
        // TreeNode root = new TreeNode(1);
        // root.left = new TreeNode(1);

        // TreeNode subRoot = new TreeNode(1);

        System.out.println(obj.isSubtree(root, subRoot));

    }
}