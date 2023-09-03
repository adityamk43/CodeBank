/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 30
 * @author ADITYA BHARDWAJ
 * 29/08/2023 12:18PM
 * 
 * @description
 * 74. Search a 2D Matrix
    Medium
    14.3K
    376
    Companies
    You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.

    

    Example 1:


    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true
    Example 2:


    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false
    

    Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104
    Accepted
    1.4M
    Submissions
    2.9M
    Acceptance Rate
    49.1%

 * @returns
    Accepted

    Runtime
    Details
    52ms
    Beats 82.58%of users with TypeScript

    Memory
    Details
    42.60MB
    Beats 98.61%of users with TypeScript
 */


// TIME COMPLEXITY: O(log n + log m)
// SPACE COMPLEXITY: O(1)
function binarySearch(nums: number[], target: number): boolean {
  let start: number = 0;
  let end: number = nums.length - 1;

  while (start <= end) {
    let mid: number = Math.floor(start + (end - start) / 2);

    // console.log(start);
    // console.log(end);
    // console.log(mid);

    if (target === nums[mid]) return true;
    else if (target < nums[mid]) end = mid - 1;
    else start = mid + 1;
  }

  return false;
}

function searchMatrix(matrix: number[][], target: number): boolean {
  // console.log(matrix.length);
  // console.log(matrix[0].length);

  let rowStart: number = 0;
  let rowEnd: number = matrix.length - 1;

  while (rowStart <= rowEnd) {
    let mid = Math.floor(rowStart + (rowEnd - rowStart) / 2);
    let colStart: number = 0;
    let colEnd: number = matrix[mid].length - 1;

    if (target === matrix[mid][colStart] || target === matrix[mid][colEnd])
      return true;
    else if (target > matrix[mid][colStart] && target < matrix[mid][colEnd])
      return binarySearch(matrix[mid], target);
    else if (target < matrix[mid][colStart]) rowEnd = mid - 1;
    else rowStart = mid + 1;
  }

  return false;
}

// Test Cases

//Case 1
let matrix:number[][] = [[1,3,5,7],[10,11,16,20],[23,30,34,60]];
let target:number=3;

//Case 2
// let matrix:number[][] = [[1,3,5,7],[10,11,16,20],[23,30,34,60]];
// let target:number=13;

console.log(searchMatrix(matrix, target));