/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 17
 * @author ADITYA BHARDWAJ
 * 16/08/2023 4:39 PM
 * 
 * @description
    * 84. Largest Rectangle in Histogram
    Hard
    15.5K
    222
    Companies
    Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

    

    Example 1:


    Input: heights = [2,1,5,6,2,3]
    Output: 10
    Explanation: The above is a histogram where width of each bar is 1.
    The largest rectangle is shown in the red area, which has an area = 10 units.
    Example 2:


    Input: heights = [2,4]
    Output: 4
    

    Constraints:

    1 <= heights.length <= 105
    0 <= heights[i] <= 104
    Accepted
    720.7K
    Submissions
    1.7M
    Acceptance Rate
    43.1%

 * @returns
    Accepted

    Runtime
    Details
    103ms
    Beats 70.65%of users with TypeScript

    Memory
    Details
    78.65mb
    Beats 13.04%of users with TypeScript
 */

//my idea (space complexity is not that good as compared to others)
// function largestRectangleArea(heights: number[]): number {
//   let n: number = heights.length;

//   if (n == 1) return heights[0];

//   let largestArea: number = 0;
//   let stack: number[][] = [];

//   stack.push([0, heights[0]]);

//   for (let i = 1; i < n; i++) {
//     let index: number = i;
//     while (stack.length !== 0 && heights[i] < stack[stack.length - 1][1]) {
//       largestArea = Math.max(
//         largestArea,
//         (i - stack[stack.length - 1][0]) * stack[stack.length - 1][1]
//       );
//       index = stack[stack.length - 1][0];
//       stack.pop();
//     }
//     stack.push([index, heights[i]]);
//   }

//   // console.log(stack);

//   while (stack.length !== 0) {
//     largestArea = Math.max(
//       largestArea,
//       (n - stack[stack.length - 1][0]) * stack[stack.length - 1][1]
//     );
//     stack.pop();
//   }

//   return largestArea;
// }

//ShaalanMarwan more fast code than me
function largestRectangleArea(heights: number[]): number {
  // Initialize an empty stack and the maximum rectangle area
  const stack = [-1];
  let maxArea = 0;

  // Iterate over the heights
  for (let i = 0; i < heights.length; i++) {
    // Keep popping the stack until the top of the stack is -1 or the height of the top
    // of the stack is less than or equal to the current height
    while (
      stack[stack.length - 1] !== -1 &&
      heights[stack[stack.length - 1]] >= heights[i]
    ) {
      // Calculate the area of the rectangle formed by the popped bar
      // (the width is the difference between the current index and the index of the bar
      // at the top of the stack after popping, and the height is the height of the popped bar)
      maxArea = Math.max(
        maxArea,
        heights[stack.pop()!] * (i - stack[stack.length - 1] - 1)
      );
    }
    // Push the current index onto the stack
    stack.push(i);
  }

  // Keep popping the stack until it is empty
  while (stack[stack.length - 1] !== -1) {
    // Calculate the area of the rectangle formed by the popped bar
    // (the width is the difference between the end of the array and the index of the bar
    // at the top of the stack after popping, and the height is the height of the popped bar)

    maxArea = Math.max(
      maxArea,
      heights[stack.pop()!] * (heights.length - stack[stack.length - 1] - 1)
    );
  }

  // Return the maximum rectangle area
  return maxArea;
}

//Test Cases

//Case 1
// let heights: number[] = [2, 1, 5, 6, 2, 3];

//Case 2
// let heights:number[] = [2,4];

//Case 2
let heights:number[] = [2,1,2];

console.log(largestRectangleArea(heights));
