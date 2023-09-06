/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 38
 * @author ADITYA BHARDWAJ
 *         06/09/2023 11:03PM
 * 
 * @description
 *              21. Merge Two Sorted Lists
 *              Easy
 *              19.9K
 *              1.8K
 *              Companies
 *              You are given the list1s of two sorted linked lists list1 and
 *              list2.
 * 
 *              Merge the two lists into one sorted list. The list should be
 *              made by splicing together the nodes of the first two lists.
 * 
 *              Return the list1 of the merged linked list.
 * 
 * 
 * 
 *              Example 1:
 * 
 * 
 *              Input: list1 = [1,2,4], list2 = [1,3,4]
 *              Output: [1,1,2,3,4,4]
 *              Example 2:
 * 
 *              Input: list1 = [], list2 = []
 *              Output: []
 *              Example 3:
 * 
 *              Input: list1 = [], list2 = [0]
 *              Output: [0]
 * 
 * 
 *              Constraints:
 * 
 *              The number of nodes in both lists is in the range [0, 50].
 *              -100 <= Node.val <= 100
 *              Both list1 and list2 are sorted in non-decreasing order.
 *              Accepted
 *              3.5M
 *              Submissions
 *              5.5M
 *              Acceptance Rate
 *              63.1%
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
 *          Beats 87.21%of users with Java
 */

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
        return "ListNode [val=" + val + ", next=" + next + "]";
    }

};

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
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        if (list1 == null)
            return list2;

        if (list2 == null)
            return list1;

        ListNode curr1 = list1;
        ListNode curr2 = list2;

        ListNode head = null;

        if (curr1.val <= curr2.val) {
            head = curr1;
            curr1 = curr1.next;
        } else {
            head = curr2;
            curr2 = curr2.next;
        }

        ListNode curr = head;

        while (curr1 != null && curr2 != null) {
            if (curr1.val <= curr2.val) {
                curr.next = curr1;
                curr1 = curr1.next;

            } else {
                curr.next = curr2;
                curr2 = curr2.next;
            }
            curr = curr.next;
        }

        if (curr2 != null)
            curr.next = curr2;
        else
            curr.next = curr1;

        return head;

    }
}

class Day38MergeTwoSortedLists {
    public static void main(String[] args) {
        Solution obj = new Solution();

        // Test Cases

        // Case 1
        ListNode list1 = new ListNode(1, null);
        list1.next = new ListNode(2, null);
        list1.next.next = new ListNode(4, null);

        ListNode list2 = new ListNode(1, null);
        list2.next = new ListNode(3, null);
        list2.next.next = new ListNode(4, null);

        // // Case 2
        // ListNode list1 = null;
        // ListNode list2 = null;

        // // Case 3
        // ListNode list1 = null;
        // ListNode list2 = new ListNode(0, null);

        // Case 4
        // ListNode list1 = new ListNode(2, null);
        // ListNode list2 = new ListNode(1, null);

        // Case 5
        // ListNode list1 = new ListNode(5, null);

        // ListNode list2 = new ListNode(1, null);
        // list2.next = new ListNode(2, null);
        // list2.next.next = new ListNode(4, null);

        System.out.println(obj.mergeTwoLists(list1, list2).toString());
    }
};