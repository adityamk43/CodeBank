/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 1
 * @author ADITYA BHARDWAJ
 * It's Day 1 challenge question but I am solving this later on so that's why late date
 * 18/08/2023 12:34 PM
 * 
 * @description
 * 1. Two Sum
    Easy
    50.2K
    1.6K
    Companies
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.

    

    Example 1:

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    Example 2:

    Input: nums = [3,2,4], target = 6
    Output: [1,2]
    Example 3:

    Input: nums = [3,3], target = 6
    Output: [0,1]
    

    Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
    

    Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

    @return
    Accepted

    Runtime
    Details
    59ms
    Beats 89.71%of users with TypeScript

    Memory
    Details
    44.95MB
    Beats 51.76%of users with TypeScript
 */

//Using Hashmap
function twoSum(nums: number[], target: number): number[] {
  let hashMap: { [key: number]: number } = {};

  hashMap[target - nums[0]] = 0;

  let i = 1;
  while (i < nums.length && !hashMap.hasOwnProperty(nums[i])) {
    hashMap[target - nums[i]] = i;
    i++;
  }

  return [hashMap[nums[i]], i];
}

// Using Two Pointers
// function twoSum(nums: number[], target: number): number[] {

//     let i = 0;
//     let j = nums.length-1;

//    let numsMap = [];

//     for (let i=0; i<nums.length; i++)
//         numsMap.push([i, nums[i]]);

//     numsMap.sort((a, b) => a[1]-b[1])

//     while (i < j && !(numsMap[i][1] + numsMap[j][1] === target)) {
//         if (numsMap[i][1] + numsMap[j][1] > target)
//             j--;
//         else
//             i++;
//     }

//     return [numsMap[i][0], numsMap[j][0]];

// };

//Test Cases

//Case 1
// let numbers: number[] = [2, 7, 11, 15];
// let target: number = 9;

//Case 2
let numbers:number[]=[3,2,4];
let target:number = 6;

//Case 1
// let numbers:number[]=[3,3];
// let target:number = 6;

console.log(twoSum(numbers, target));
