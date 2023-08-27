/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 29
 * @author ADITYA BHARDWAJ
 * 27/08/2023 10:36PM
 * 
 * @description
 * 704. Binary Search
    Easy
    10.6K
    212
    Companies
    Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

    You must write an algorithm with O(log n) runtime complexity.

    

    Example 1:

    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    Explanation: 9 exists in nums and its index is 4
    Example 2:

    Input: nums = [-1,0,3,5,9,12], target = 2
    Output: -1
    Explanation: 2 does not exist in nums so return -1
    

    Constraints:

    1 <= nums.length <= 104
    -104 < nums[i], target < 104
    All the integers in nums are unique.
    nums is sorted in ascending order.
    Accepted
    2M
    Submissions
    3.5M
    Acceptance Rate
    56.6%

    @returns
    Accepted

    Runtime
    Details
    47ms
    Beats 98.45%of users with TypeScript

    Memory
    Details
    45.82MB
    Beats 74.60%of users with TypeScript
 */

function search(nums: number[], target: number): number {
  let start: number = 0;
  let end: number = nums.length - 1;

  while (start <= end) {
    let mid: number = Math.floor(start + (end - start) / 2);

    // console.log(start);
    // console.log(end);
    // console.log(mid);

    if (target === nums[mid]) return mid;
    else if (target < nums[mid]) end = mid - 1;
    else start = mid + 1;
  }

  return -1;
}

//Test Cases

//Case 1
let nums:number[]=[-1,0,3,5,9,12];
let target:number=9;

//Case 2
// let nums:number[]=[-1,0,3,5,9,12];
// let target:number=2;

console.log(search(nums, target));