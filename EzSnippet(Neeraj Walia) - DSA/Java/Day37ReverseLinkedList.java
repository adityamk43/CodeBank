/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 37
 * @author ADITYA BHARDWAJ
 *         06/09/2023 12:58PM
 * 
 * @description
 * 206. Reverse Linked List
    Easy
    19.4K
    352
    Companies
    Given the head of a singly linked list, reverse the list, and return the reversed list.

    

    Example 1:


    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]
    Example 2:


    Input: head = [1,2]
    Output: [2,1]
    Example 3:

    Input: head = []
    Output: []
    

    Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000
    

    Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
 * 
 * @returns
 * Accepted

    Runtime
    Details
    0ms
    Beats 100.00%of users with Java

    Memory
    Details
    41.15MB
    Beats 71.78%of users with Java
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
}

class Day37ReverseLinkedList {

    public static void main(String args[])
    {
        Solution obj = new Solution();

        // Test Cases

        //Case 1
        ListNode head=new ListNode(1 , null);
        head.next=new ListNode(2, null);
        head.next.next=new ListNode(3, null);
        head.next.next.next=new ListNode(4, null);
        head.next.next.next.next=new ListNode(5, null);

        //Case 2
        // ListNode head=new ListNode(1 , null);
        // head.next=new ListNode(2, null);

        //Case 3
        // ListNode head=null;

        System.out.println(obj.reverseList(head).toString());
        
    }

};