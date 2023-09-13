/**
 * 
 * NOTE: Day 43 code (Linked List Cycle) solved in Daily change on Leetcode on
 * Sept 4, 2023
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 44
 * @author ADITYA BHARDWAJ
 *         13/09/2023 10:52AM
 * 
 * @description
 * 
 *              287. Find the Duplicate Number
 *              Solved
 *              Medium
 *              Topics
 *              Companies
 *              Given an array of integers nums containing n + 1 integers where
 *              each integer is in the range [1, n] inclusive.
 * 
 *              There is only one repeated number in nums, return this repeated
 *              number.
 * 
 *              You must solve the problem without modifying the array nums and
 *              uses only constant extra space.
 * 
 * 
 * 
 *              Example 1:
 * 
 *              Input: nums = [1,3,4,2,2]
 *              Output: 2
 *              Example 2:
 * 
 *              Input: nums = [3,1,3,4,2]
 *              Output: 3
 * 
 * 
 *              Constraints:
 * 
 *              1 <= n <= 105
 *              nums.length == n + 1
 *              1 <= nums[i] <= n
 *              All the integers in nums appear only once except for precisely
 *              one integer which appears two or more times.
 * 
 * 
 *              Follow up:
 * 
 *              How can we prove that at least one duplicate number must exist
 *              in nums?
 *              Can you solve the problem in linear runtime complexity?
 *              Accepted
 *              1.3M
 *              Submissions
 *              2.2M
 *              Acceptance Rate
 *              59.0%
 *
 * 
 * @returns
 *          Accepted
 * 
 *          Runtime
 *          Details
 *          5ms
 *          Beats 63.42%of users with Java
 * 
 *          Memory
 *          Details
 *          55.85MB
 *          Beats 97.09%of users with Java
 */

class Solution {
   public int findDuplicate(int[] nums) {

      int slow = nums[0];
      int fast = nums[0];
      int i = nums[0];

      while (fast < nums.length) {
         slow = nums[slow];
         fast = nums[nums[fast]];

         if (slow == fast)
            break;
      }

      while (i != slow) {
         i = nums[i];
         slow = nums[slow];
         // System.out.println(i);
         // System.out.println(slow);
      }

      return i;
   }
}

class Day44FindDuplicateNumber {
   public static void main(String[] args) {
      Solution obj = new Solution();
      
      // Test Case

      // Case 1
      // int[] nums={1,3,4,2,2};
      
      // Case 2
      int[] nums={3,1,3,4,2};

      System.out.println(obj.findDuplicate(nums));
   }
};