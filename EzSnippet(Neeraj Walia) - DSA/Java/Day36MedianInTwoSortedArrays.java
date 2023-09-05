/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 36
 * @author ADITYA BHARDWAJ
 *         05/09/2023 11:56PM
 * 
 * @description
 *              4. Median of Two Sorted Arrays
 *              Hard
 *              25.5K
 *              2.8K
 *              Companies
 *              Given two sorted arrays nums1 and nums2 of size m and n
 *              respectively, return the median of the two sorted arrays.
 * 
 *              The overall run time complexity should be O(log (m+n)).
 * 
 * 
 * 
 *              Example 1:
 * 
 *              Input: nums1 = [1,3], nums2 = [2]
 *              Output: 2.00000
 *              Explanation: merged array = [1,2,3] and median is 2.
 *              Example 2:
 * 
 *              Input: nums1 = [1,2], nums2 = [3,4]
 *              Output: 2.50000
 *              Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2
 *              = 2.5.
 * 
 * 
 *              Constraints:
 * 
 *              nums1.length == m
 *              nums2.length == n
 *              0 <= m <= 1000
 *              0 <= n <= 1000
 *              1 <= m + n <= 2000
 *              -106 <= nums1[i], nums2[i] <= 106
 *              Accepted
 *              2.1M
 *              Submissions
 *              5.5M
 *              Acceptance Rate
 *              37.3%
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
 *          44.58MB
 *          Beats 72.20%of users with Java
 */

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.length, n = nums2.length;
        int left = 0, right = m;

        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int maxLeftA = (partitionA == 0) ? Integer.MIN_VALUE : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? Integer.MAX_VALUE : nums1[partitionA];
            int maxLeftB = (partitionB == 0) ? Integer.MIN_VALUE : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? Integer.MAX_VALUE : nums2[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (Math.max(maxLeftA, maxLeftB) + Math.min(minRightA, minRightB)) / 2.0;
                } else {
                    return Math.max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } else {
                left = partitionA + 1;
            }
        }
        return 0.0;
    }
}

class Day36MedianInTwoSortedArrays {
    public static void main(String args[]) {

        Solution obj = new Solution();

        // Test Cases

        // Case 1
        // int[] nums1 = new int[] { 1, 3 };
        // int[] nums2 = new int[] { 2 };

        // Case 2
        int[] nums1 = new int[]{1, 2};
        int[] nums2 = new int[]{3, 4};

        System.out.println(obj.findMedianSortedArrays(nums1, nums2));

    }
};