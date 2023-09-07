/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 39
 * @author ADITYA BHARDWAJ
 *         08/09/2023 01:59AM
 * 
 * @description
 *              143. Reorder List
 *              Medium
 *              9.6K
 *              316
 *              Companies
 *              You are given the head of a singly linked-list. The list can be
 *              represented as:
 * 
 *              L0 → L1 → … → Ln - 1 → Ln
 *              Reorder the list to be on the following form:
 * 
 *              L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 *              You may not modify the values in the list's nodes. Only nodes
 *              themselves may be changed.
 * 
 * 
 * 
 *              Example 1:
 * 
 * 
 *              Input: head = [1,2,3,4]
 *              Output: [1,4,2,3]
 *              Example 2:
 * 
 * 
 *              Input: head = [1,2,3,4,5]
 *              Output: [1,5,2,4,3]
 * 
 * 
 *              Constraints:
 * 
 *              The number of nodes in the list is in the range [1, 5 * 104].
 *              1 <= Node.val <= 1000
 *              Accepted
 *              735K
 *              Submissions
 *              1.4M
 *              Acceptance Rate
 *              54.2%
 * 
 * @returns
 *          Accepted
 * 
 *          Runtime
 *          Details
 *          2ms
 *          Beats 71.62%of users with Java
 * 
 *          Memory
 *          Details
 *          45.59MB
 *          Beats 91.99%of users with Java
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

class Solution {

    public ListNode reverseList(ListNode head) {

        if (head == null)
            return null;

        ListNode curr = head;
        ListNode prev = null;

        while (curr != null) {
            ListNode forward = curr.next;
            curr.next = prev;
            prev = curr;
            curr = forward;
        }

        // System.out.println(curr.next.val);

        return prev;

    }

    public void reorderList(ListNode head) {

        if (head == null || head.next == null || head.next.next == null)
            return;

        ListNode fast = head, slow = head;
        ListNode prevSlow = null;

        // to find middle element
        while (fast != null && fast.next != null) {
            prevSlow = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode reversedList = null;
        if (fast == null) {
            reversedList = reverseList(slow);
            prevSlow.next = null;
        } else {
            reversedList = reverseList(slow.next);
            slow.next = null;
        }

        ListNode fh = head, sh = reversedList;
        while (fh != null && sh != null) {
            ListNode next1 = fh.next;
            ListNode next2 = sh.next;

            fh.next = sh;
            sh.next = next1;

            fh = next1;
            sh = next2;
        }

    }
}

class Day39ReorderLinkedList {

    public static void main(String[] args) {
        Solution obj = new Solution();

        // Test Cases

        // Case 1
        // ListNode head = new ListNode(1, null);
        // head.next = new ListNode(2, null);
        // head.next.next = new ListNode(3, null);
        // head.next.next.next = new ListNode(4, null);
  
        // Case 2
        ListNode head = new ListNode(1, null);
        head.next = new ListNode(2, null);
        head.next.next = new ListNode(3, null);
        head.next.next.next = new ListNode(4, null);
        head.next.next.next.next = new ListNode(5, null);

        obj.reorderList(head);
        System.out.println(head);
    }

};