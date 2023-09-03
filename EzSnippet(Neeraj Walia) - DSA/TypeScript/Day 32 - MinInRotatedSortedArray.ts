/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 32
 * @author ADITYA BHARDWAJ
 * 31/08/2023 08:41PM
 * 
 * @description
 * 153. Find Minimum in Rotated Sorted Array
    Medium
    11.8K
    520
    Companies
    Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.
    Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

    Given the sorted rotated array nums of unique elements, return the minimum element of this array.

    You must write an algorithm that runs in O(log n) time.

    

    Example 1:

    Input: nums = [3,4,5,1,2]
    Output: 1
    Explanation: The original array was [1,2,3,4,5] rotated 3 times.
    Example 2:

    Input: nums = [4,5,6,7,0,1,2]
    Output: 0
    Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
    Example 3:

    Input: nums = [11,13,15,17]
    Output: 11
    Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
    

    Constraints:

    n == nums.length
    1 <= n <= 5000
    -5000 <= nums[i] <= 5000
    All the integers of nums are unique.
    nums is sorted and rotated between 1 and n times.
    Accepted
    1.4M
    Submissions
    2.9M
    Acceptance Rate
    49.4%
 * 
 * @returns
 * Accepted

    Runtime
    Details
    55ms
    Beats 75.43%of users with TypeScript

    Memory
    Details
    42.98MB
    Beats 87.72%of users with TypeScript
 */

// using Binary Search to find where the smaller element is in a rotated array
function findMin(nums: number[]): number {
  let start = 0;
  let end = nums.length - 1;

  let minNum: number = 5001;

  while (start <= end) {
    let mid: number = Math.floor((start + end) / 2);

    minNum = Math.min(minNum, nums[mid]);

    if (nums[end] < nums[mid]) start = mid + 1;
    else end = mid - 1;
  }

  return minNum;
}

//Test Cases

//Case 1
let nums:number[]=[3,4,5,1,2];

//Case 2
// let nums:number[]=[4,5,6,7,0,1,2];

//Case 3
// let nums:number[]=[11,13,15,17];

console.log(findMin(nums));