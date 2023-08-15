/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 14
 * 
 * @author ADITYA BHARDWAJ
 * 13/08/2023 01:43 AM
 * 
 * @description
 * 739. Daily Temperatures
    Medium
    11.4K
    250
    Companies
    Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

    

    Example 1:

    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]
    Example 2:

    Input: temperatures = [30,40,50,60]
    Output: [1,1,1,0]
    Example 3:

    Input: temperatures = [30,60,90]
    Output: [1,1,0]
    

    Constraints:

    1 <= temperatures.length <= 105
    30 <= temperatures[i] <= 100
    Accepted
    668.5K
    Submissions
    1M
    Acceptance Rate
    66.0%
 */

function dailyTemperatures(temperatures: number[]): number[] {
  const stack: number[][] = [];
  const res: number[] = new Array(temperatures.length).fill(0);

  for (let i = 0; i < temperatures.length; i++) {
    let num = temperatures[i];

    while (stack.length !== 0 && stack[stack.length - 1][1] < num) {
      res[stack[stack.length - 1][0]] = i - stack[stack.length - 1][0];
      stack.pop();
    }
    stack.push([i, num]);
  }

  return res;
}

//Test Cases
//Case 1
// let temperatures:number[] = [73,74,75,71,69,72,76,73];

//Case 2
// let temperatures:number[] = [30,40,50,60];

//Case 3
let temperatures:number[] = [30,60,90];

console.log(dailyTemperatures(temperatures));
