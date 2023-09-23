
/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 49
 * @author ADITYA BHARDWAJ
 *         23/09/2023 03:09PM
 * 
 * @description
 * 110. Balanced Binary Tree
    Solved
    Easy

    Given a binary tree, determine if it is 
    height-balanced
    .

    

    Example 1:


    Input: root = [3,9,20,null,null,15,7]
    Output: true
    Example 2:


    Input: root = [1,2,2,3,3,null,null,4,4]
    Output: false
    Example 3:

    Input: root = []
    Output: true
    

    Constraints:

    The number of nodes in the tree is in the range [0, 5000].
    -104 <= Node.val <= 104
    Accepted
    1.2M
    Submissions
    2.5M
    Acceptance Rate
    50.4%
 * 
 * @returns
 * Accepted

    Runtime
    Details
    0ms
    Beats 100.00%of users with Java

    Memory
    Details
    42.75MB
    Beats 91.90%of users with Java
 * 
 */

import java.util.Objects;

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

// Creating our custom Pair class as for some reason "javafx.util.Pair" class is
// not working
class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public void setKey(K key) {
        this.key = key;
    }

    public V getValue() {
        return value;
    }

    public void setValue(V value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return "(" + key + ", " + value + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        Pair<?, ?> pair = (Pair<?, ?>) obj;
        return Objects.equals(key, pair.key) &&
                Objects.equals(value, pair.value);
    }

    @Override
    public int hashCode() {
        return Objects.hash(key, value);
    }
}

class Solution {

    // public Pair<Boolean, Integer> myIsBalanced(TreeNode root)
    // {
    // if (root==null)
    // return new Pair<>(true, 0);

    // Pair<Boolean, Integer> left = myIsBalanced(root.left);
    // Pair<Boolean, Integer> right = myIsBalanced(root.right);

    // int height = 1 + Math.max(left.getValue(), right.getValue());

    // boolean balance = (left.getKey()==true && right.getKey()==true &&
    // Math.abs(left.getValue()-right.getValue())<=1) ? true : false;

    // return new Pair<>(balance, height);
    // }

    // public boolean isBalanced(TreeNode root) {
    // return myIsBalanced(root).getKey();
    // }

    public int myIsBalanced(TreeNode root) {
        if (root == null)
            return 0;

        int left = myIsBalanced(root.left);
        if (left == -1)
            return -1;

        int right = myIsBalanced(root.right);
        if (right == -1)
            return -1;

        if (Math.abs(left - right) > 1)
            return -1;

        return 1 + Math.max(left, right);
    }

    public boolean isBalanced(TreeNode root) {
        return myIsBalanced(root) == -1 ? false : true;
    }
}

public class Day49checkBalancedBinaryTree {

    public static void main(String[] args) {
        Solution obj = new Solution();

        // Test Cases

        // Case 1
        // TreeNode root = new TreeNode(3);
        // root.left = new TreeNode(9);
        // root.right = new TreeNode(20);
        // root.right.left = new TreeNode(15);
        // root.right.right = new TreeNode(7);

        // Case 2
        // TreeNode root = new TreeNode(3);
        // root.left = new TreeNode(2);
        // root.right = new TreeNode(2);
        // root.left.left = new TreeNode(3);
        // root.left.right = new TreeNode(3);
        // root.left.left.left = new TreeNode(4);
        // root.left.left.right = new TreeNode(4);

        // Case 3
        // TreeNode root = null;

        // Case 4
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.right.right = new TreeNode(3);
        root.left.left.left = new TreeNode(4);
        root.right.right.right = new TreeNode(4);

        System.out.println(obj.isBalanced(root));
    }

}
