/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 33
 * @author ADITYA BHARDWAJ
 * 01/08/2023 11:45PM - 02/08/2023 12:14AM
 *
 * @description
 * 33. Search in Rotated Sorted Array
    Medium
    24K
    1.4K
    Companies
    There is an integer array nums sorted in ascending order (with distinct values).

    Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

    Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

    You must write an algorithm with O(log n) runtime complexity.

    

    Example 1:

    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
    Example 2:

    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1
    Example 3:

    Input: nums = [1], target = 0
    Output: -1
    

    Constraints:

    1 <= nums.length <= 5000
    -104 <= nums[i] <= 104
    All values of nums are unique.
    nums is an ascending array that is possibly rotated.
    -104 <= target <= 104
    Accepted
    2.3M
    Submissions
    5.7M
    Acceptance Rate
    39.9%
 * 
 * @returns
 * Accepted

    Runtime
    Details
    47ms
    Beats 95.00%of users with TypeScript

    Memory
    Details
    42.92MB
    Beats 94.06%of users with TypeScript
 */

// Using Binary Search
function search(nums: number[], target: number): number {
  let start: number = 0;
  let end: number = nums.length - 1;

  while (start <= end) {
    let mid: number = Math.floor((start + end) / 2);
    // console.log(start)
    // console.log(end)
    // console.log(mid)

    // Case 1: find target
    if (target === nums[mid]) return mid;
    // Case 2: subarray on mid's left is sorted
    else if (nums[start] <= nums[mid]) {
      // console.log("YO if if")
      if (target >= nums[start] && target < nums[mid]) end = mid - 1;
      else start = mid + 1;
    }
    // Case 3: subarray on mid's right is sorted
    else {
      // console.log("YO if if else else")
      if (target <= nums[end] && target > nums[mid]) start = mid + 1;
      else end = mid - 1;
    }
  }

  return -1;
}

//Test Cases

//Case 1
let nums:number[] = [4,5,6,7,0,1,2];
let target:number= 0;

//Case 2
// let nums:number[] = [4,5,6,7,0,1,2];
// let target:number= 3;

//Case 3
// let nums:number[] = [1];
// let target:number= 0;

//Case 4
// let nums:number[] = [6,7,0,1,2,4,5];
// let target:number= 0;

//Case 5
// let nums:number[] = [4,5,6,7,0,1,2];
// let target:number= 7;

//Case 6
// let nums:number[] = [4,5,6,7,0,1,2];
// let target:number= 4;

//Case 7
// let nums:number[] = [5,1,3];
// let target:number= 5;

console.log(search(nums, target));