/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 19
 * @author ADITYA BHARDWAJ
 * 18/08/2023 11:43 AM
 * 
 * @description
 * 167. Two Sum II - Input Array Is Sorted
    Medium
    10.4K
    1.3K
    Companies
    Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.

    Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

    The tests are generated such that there is exactly one solution. You may not use the same element twice.

    Your solution must use only constant extra space.

    

    Example 1:

    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
    Example 2:

    Input: numbers = [2,3,4], target = 6
    Output: [1,3]
    Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
    Example 3:

    Input: numbers = [-1,0], target = -1
    Output: [1,2]
    Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
    

    Constraints:

    2 <= numbers.length <= 3 * 104
    -1000 <= numbers[i] <= 1000
    numbers is sorted in non-decreasing order.
    -1000 <= target <= 1000
    The tests are generated such that there is exactly one solution.
    Accepted
    1.6M
    Submissions
    2.6M
    Acceptance Rate
    60.2%

 * @return
    Accepted

    Runtime
    Details
    55ms
    Beats 91.08%of users with TypeScript

    Memory
    Details
    43.06MB
    Beats 93.67%of users with TypeScript
 */

// this code is also correct but I fixed the problem of typescript typechecking to make the return type of function as number[] union undefined also. Also optimised extra while loop run through optimising while condition in the new code by me given below
// function twoSum(numbers: number[], target: number): number[] | undefined {
//   let i: number = 0;
//   let j: number = numbers.length - 1;

//   while (i < j) {
//     if (numbers[i] + numbers[j] === target) return [i + 1, j + 1];
//     else if (numbers[i] + numbers[j] > target) j--;
//     else i++;
//   }
// }

// shorter and better readable code than above
function twoSum(numbers: number[], target: number): number[] {
  let i: number = 0;
  let j: number = numbers.length - 1;

  while (i < j && !(numbers[i] + numbers[j] === target)) {
    if (numbers[i] + numbers[j] > target) j--;
    else i++;
  }

  return [i + 1, j + 1];
}

//Test Cases

//Case 1
let numbers: number[] = [2, 7, 11, 15];
let target: number = 9;

//Case 2
// let numbers:number[]=[2,3,4];
// let target:number = 6;

//Case 1
// let numbers:number[]=[-1,0];
// let target:number = -1;

console.log(twoSum(numbers, target));
