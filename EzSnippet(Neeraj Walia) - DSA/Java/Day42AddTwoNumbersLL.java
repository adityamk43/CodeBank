/**
 * 
 * NOTE: Day 41 code (138. Copy List with Random Pointer) solved in Daily change on Leetcode on Sept 5, 2023
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 42
 * @author ADITYA BHARDWAJ
 *         10/09/2023 10:53PM
 * 
 * @description
 *              2. Add Two Numbers
 *              Medium
 *              28.2K
 *              5.4K
 *              Companies
 *              You are given two non-empty linked lists representing two
 *              non-negative integers. The digits are stored in reverse order,
 *              and each of their nodes contains a single digit. Add the two
 *              numbers and return the sum as a linked list.
 * 
 *              You may assume the two numbers do not contain any leading zero,
 *              except the number 0 itself.
 * 
 * 
 * 
 *              Example 1:
 * 
 * 
 *              Input: l1 = [2,4,3], l2 = [5,6,4]
 *              Output: [7,0,8]
 *              Explanation: 342 + 465 = 807.
 *              Example 2:
 * 
 *              Input: l1 = [0], l2 = [0]
 *              Output: [0]
 *              Example 3:
 * 
 *              Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 *              Output: [8,9,9,9,0,0,0,1]
 * 
 * 
 *              Constraints:
 * 
 *              The number of nodes in each linked list is in the range [1,
 *              100].
 *              0 <= Node.val <= 9
 *              It is guaranteed that the list represents a number that does not
 *              have leading zeros.
 *              Accepted
 *              3.9M
 *              Submissions
 *              9.4M
 *              Acceptance Rate
 *              41.1%
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
 *          42.80MB
 *          Beats 96.82%of users with Java
 * 
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
      return val + " " +  next;
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

   // My Approach (the code can be further shorten by changing while logic from and
   // to or and merging other while loops into one) [as shown below]
   public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

      int carry = 0;
      int sum = l1.val + l2.val;

      if (sum > 9) {
         carry = sum / 10;
         sum = sum % 10;
      }

      ListNode ansHead = null, ans = null;
      ansHead = ans = new ListNode(sum, null);

      ListNode curr1 = l1.next, curr2 = l2.next;
      while (curr1 != null || curr2 != null || carry != 0) {
         sum = (curr1 != null ? curr1.val : 0) + (curr2 != null ? curr2.val : 0) + carry;
         carry = 0;

         if (sum > 9) {
            carry = sum / 10;
            sum = sum % 10;
         }

         ans.next = new ListNode(sum, null);
         ans = ans.next;

         curr1 = (curr1 == null ? null : curr1.next);
         curr2 = (curr2 == null ? null : curr2.next);

      }

      // while (curr1!=null && curr2!=null)
      // {
      // sum=curr1.val+curr2.val+carry;
      // carry=0;

      // if (sum>9)
      // {
      // carry=sum/10;
      // sum=sum%10;
      // }

      // ans.next=new ListNode(sum, null);
      // ans=ans.next;

      // curr1=curr1.next;
      // curr2=curr2.next;

      // }

      // while (curr1!=null)
      // {
      // sum=curr1.val+carry;
      // carry=0;

      // if (sum>9)
      // {
      // carry=sum/10;
      // sum=sum%10;
      // }

      // ans.next=new ListNode(sum, null);
      // ans=ans.next;

      // curr1=curr1.next;

      // }

      // while (curr2!=null)
      // {
      // sum=curr2.val+carry;
      // carry=0;

      // if (sum>9)
      // {
      // carry=sum/10;
      // sum=sum%10;
      // }

      // ans.next=new ListNode(sum, null);
      // ans=ans.next;
      // curr2=curr2.next;

      // }

      // if (carry!=0)
      // ans.next=new ListNode(carry);

      return ansHead;

   }
}

class Day42AddTwoNumbersLL {

   public static void main(String[] args) {

      Solution obj = new Solution();

      // Test Cases

      // Case 1
      // // Number - 243
      // ListNode l1 = new ListNode(2, null);
      // l1.next = new ListNode(4, null);
      // l1.next.next = new ListNode(3, null);

      // // Number - 807
      // ListNode l2 = new ListNode(5, null);
      // l2.next = new ListNode(6, null);
      // l2.next.next = new ListNode(4, null);

      // O.P. - 342+465=807

      // Case 2
      // ListNode l1 = new ListNode(0, null);
      // ListNode l2 = new ListNode(0, null);

      // O.P. - 0+0=0

      // Case 3
      // Number - 9999999
      ListNode l1 = new ListNode(9, null);
      l1.next = new ListNode(9, null);
      l1.next.next = new ListNode(9, null);
      l1.next.next.next = new ListNode(9, null);
      l1.next.next.next.next = new ListNode(9, null);
      l1.next.next.next.next.next = new ListNode(9, null);
      l1.next.next.next.next.next.next = new ListNode(9, null);

      // Number - 9999
      ListNode l2 = new ListNode(9, null);
      l2.next = new ListNode(9, null);
      l2.next.next = new ListNode(9, null);
      l2.next.next.next = new ListNode(9, null);

      // O.P. - 9999999+9999=10009998

      System.out.println(obj.addTwoNumbers(l1, l2));

   }

};