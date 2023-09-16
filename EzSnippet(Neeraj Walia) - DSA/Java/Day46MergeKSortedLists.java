/**
 * 
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 46
 * @author ADITYA BHARDWAJ
 *         16/09/2023 10:47PM
 * 
 * @description
 *              23. Merge k Sorted Lists
 *              You are given an array of k linked-lists lists, each linked-list
 *              is sorted in ascending order.
 * 
 *              Merge all the linked-lists into one sorted linked-list and
 *              return it.
 * 
 * 
 * 
 *              Example 1:
 * 
 *              Input: lists = [[1,4,5],[1,3,4],[2,6]]
 *              Output: [1,1,2,3,4,4,5,6]
 *              Explanation: The linked-lists are:
 *              [
 *              1->4->5,
 *              1->3->4,
 *              2->6
 *              ]
 *              merging them into one sorted list:
 *              1->1->2->3->4->4->5->6
 *              Example 2:
 * 
 *              Input: lists = []
 *              Output: []
 *              Example 3:
 * 
 *              Input: lists = [[]]
 *              Output: []
 * 
 * 
 *              Constraints:
 * 
 *              k == lists.length
 *              0 <= k <= 104
 *              0 <= lists[i].length <= 500
 *              -104 <= lists[i][j] <= 104
 *              lists[i] is sorted in ascending order.
 *              The sum of lists[i].length will not exceed 104.
 *              Accepted
 *              1.7M
 *              Submissions
 *              3.4M
 *              Acceptance Rate
 *              50.9%
 * 
 * @returns
 *          Accepted
 * 
 *          Runtime
 *          Details
 *          1ms
 *          Beats 100.00%of users with Java
 * 
 *          Memory
 *          Details
 *          42.81MB
 *          Beats 96.06%of users with Java
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// Helper class - LinkedList Data Structure
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }

    @Override
    public String toString() {
        return val + " " + next;
    }

};

// Using Merge Sort
/**
 * NOTE 1 - PLEASE READ INTUITION AND APPROACH FIRST THEN SEE THE CODE. YOU WILL
 * DEFINITELY UNDERSTAND THE CODE LINE BY LINE AFTER SEEING THE APPROACH.
 * 
 * NOTE 2 - BEFORE SOLVING THIS PROBELM, I WILL HIGHLY RECOMMEND YOU TO SOLVE
 * BELOW PROBLEM FOR BETTER UNDERSTANDING.
 * 21. Merge Two Sorted Lists :
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 * SOLUTION :
 * https://leetcode.com/problems/merge-two-sorted-lists/solutions/3288537/o-m-n-time-and-o-1-space-easiest-beginner-friendly-solution/
 * 
 * Intuition of this Problem:
 * This solution uses the merge sort algorithm to merge all the linked lists in
 * the input vector into a single sorted linked list. The merge sort algorithm
 * works by recursively dividing the input into halves, sorting each half
 * separately, and then merging the two sorted halves into a single sorted
 * output.
 * 
 * Approach for this Problem:
 * 1.) Define a function merge that takes two pointers to linked lists as input
 * and
 * merges them in a sorted manner.
 * 
 * a. Create a dummy node with a value of -1 and a temporary node pointing to
 * it.
 * b. Compare the first node of the left and right linked lists, and append the
 * smaller one to the temporary node.
 * c. Continue this process until either of the lists becomes empty.
 * d. Append the remaining nodes of the non-empty list to the temporary node.
 * e. Return the next node of the dummy node.
 * 
 * 2.) Define a function mergeSort that takes three arguments - a vector of
 * linked
 * lists, a starting index, and an ending index. It performs merge sort on the
 * linked lists from the starting index to the ending index.
 * 
 * a. If the starting index is equal to the ending index, return the linked list
 * at that index.
 * b. Calculate the mid index and call mergeSort recursively on the left and
 * right halves of the vector.
 * c. Merge the two sorted linked lists obtained from the recursive calls using
 * the merge function and return the result.
 * 
 * 3.) Define the main function mergeKLists that takes the vector of linked
 * lists as
 * input and returns a single sorted linked list.
 * 
 * a. If the input vector is empty, return a null pointer.
 * b. Call the mergeSort function on the entire input vector, from index 0 to
 * index k-1, where k is the size of the input vector.
 * c. Return the merged linked list obtained from the mergeSort function call.
 * 
 * 4.) End of algorithm.
 * 
 * @Time Complexity and Space Complexity:
 * Time complexity: O(N log k), where N is the total number of nodes in all the
 * linked lists, and k is the number of linked lists in the input vector. This
 * is because the merge sort algorithm requires O(N log N) time to sort N items,
 * and in this case, N is the total number of nodes in all the linked lists. The
 * number of levels in the recursion tree of the merge sort algorithm is log k,
 * where k is the number of linked lists in the input vector. Each level of the
 * recursion tree requires O(N) time to merge the sorted lists, so the total
 * time complexity is O(N log k).
 * 
 * @Space complexity: O(log k), which is the maximum depth of the recursion tree
 * of the merge sort algorithm. The space used by each recursive call is
 * constant, so the total space used by the algorithm is proportional to the
 * maximum depth of the recursion tree. Since the depth of the tree is log k,
 * the space complexity of the algorithm is O(log k).
 */
class Solution {

    public ListNode merge(ListNode left, ListNode right) {
        ListNode newNode = new ListNode(-1);
        ListNode temp = newNode;

        while (left != null && right != null) {
            if (left.val < right.val) {
                temp.next = left;
                left = left.next;
            } else {
                temp.next = right;
                right = right.next;
            }

            temp = temp.next;
        }

        while (left != null) {
            temp.next = left;
            temp = temp.next;
            left = left.next;
        }

        while (right != null) {
            temp.next = right;
            temp = temp.next;
            right = right.next;
        }

        return newNode.next;
    }

    public ListNode mergeSort(ListNode[] lists, int start, int end) {
        if (start == end)
            return lists[start];

        int mid = (start + end) / 2;

        ListNode left = mergeSort(lists, start, mid);
        ListNode right = mergeSort(lists, mid + 1, end);

        return merge(left, right);

    }

    public ListNode mergeKLists(ListNode[] lists) {

        if (lists.length == 0)
            return null;

        return mergeSort(lists, 0, lists.length - 1);
    }
}

public class Day46MergeKSortedLists {
    public static void main(String[] args) {

        Solution obj = new Solution();

        // Test Cases

        // Case 1
        ListNode[] lists = new ListNode[3];

        ListNode list1 = new ListNode(1, null);
        list1.next = new ListNode(4, null);
        list1.next.next = new ListNode(5, null);

        ListNode list2 = new ListNode(1, null);
        list2.next = new ListNode(3, null);
        list2.next.next = new ListNode(4, null);

        ListNode list3 = new ListNode(2, null);
        list3.next = new ListNode(6, null);

        lists[0] = list1;
        lists[1] = list2;
        lists[2] = list3;

        // Case 2
        // ListNode[] lists = new ListNode[0];

        // Case 3
        // ListNode[] lists = new ListNode[1];
        // lists[0]=null;

        System.out.println(obj.mergeKLists(lists));
    }
}
