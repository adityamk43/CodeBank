/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 40
 * @author ADITYA BHARDWAJ
 *         08/09/2023 10:59PM
 * 
 * @description
    19. Remove Nth Node From End of List
    Medium
    17.1K
    702
    Companies
    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    

    Example 1:


    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
    Example 2:

    Input: head = [1], n = 1
    Output: []
    Example 3:

    Input: head = [1,2], n = 1
    Output: [1]
    

    Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
    

    Follow up: Could you do this in one pass?

    Accepted
    2.2M
    Submissions
    5.2M
    Acceptance Rate
    42.4%
 * 
 * @returns
 *  Accepted

    Runtime
    Details
    0ms
    Beats 100.00%of users with Java

    Memory
    Details
    40.37MB
    Beats 78.18%of users with Java
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
    public ListNode removeNthFromEnd(ListNode head, int n) {

        // My Approach
        // if (head==null || (head.next==null && n==1))
        // return null;

        // ListNode curr=head;
        // int count=0;
        // while(curr!=null)
        // {
        // count++;
        // curr=curr.next;
        // }

        // curr=head;
        // while (curr!=null)
        // {
        // if (count==n)
        // {
        // head=curr.next;
        // break;
        // }
        // else if (count-1==n)
        // {
        // ListNode nthNode=curr.next;
        // curr.next=curr.next.next;
        // nthNode.next=null;
        // break;
        // }
        // curr=curr.next;
        // count--;
        // }

        // return head;

        // Another good approach using two pointer method
        ListNode fast = head, slow = head;
        for (int i = 0; i < n; i++)
            fast = fast.next;
        if (fast == null)
            return head.next;
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return head;

    }
}

class Day40RemoveNthNodeFromList {

    public static void main(String[] args) {

        Solution obj = new Solution();

        // Test Cases

        // Case 1
        int n=2;

        ListNode head = new ListNode(1, null);
        head.next = new ListNode(2, null);
        head.next.next = new ListNode(3, null);
        head.next.next.next = new ListNode(4, null);
        head.next.next.next.next = new ListNode(5, null);

        // Case 2
        // int n=1;

        // ListNode head = new ListNode(1, null);

        // Case 3
        // int n=1;

        // ListNode head = new ListNode(1, null);
        // head.next = new ListNode(2, null);

        // Case 4
        // int n = 2;

        // ListNode head = new ListNode(1, null);
        // head.next = new ListNode(2, null);

        System.out.println(obj.removeNthFromEnd(head, n));

    }

};