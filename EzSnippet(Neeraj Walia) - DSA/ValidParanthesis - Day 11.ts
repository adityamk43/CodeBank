/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 11
 * @author ADITYA BHARDWAJ
 * 10/08/2022 08:26 PM
 * 1 Day late due to office work!
 * 
 * @description
 * 20. Valid Parentheses
    Easy
    21.3K
    1.4K
    Companies
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
    

    Example 1:

    Input: s = "()"
    Output: true
    Example 2:

    Input: s = "()[]{}"
    Output: true
    Example 3:

    Input: s = "(]"
    Output: false
    

    Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
    Accepted
    3.6M
    Submissions
    9M
    Acceptance Rate
    40.2%

 */

// My implementation
// function isValid(s: string): boolean {
//   let stack: string[] = [];

//   for (let i: number = 0; i < s.length; i++) {
//     if (stack.length !== 0) {
//       if (
//         stack[stack.length - 1] === "(" ||
//         stack[stack.length - 1] === "[" ||
//         stack[stack.length - 1] === "{"
//       ) {
//         if (
//           (s[i] === ")" && stack[stack.length - 1] === "(") ||
//           (s[i] === "}" && stack[stack.length - 1] === "{") ||
//           (s[i] === "]" && stack[stack.length - 1] === "[")
//         ) {
//           stack.pop();
//         } else stack.push(s[i]);
//       } else stack.push(s[i]);
//     } else stack.push(s[i]);
//   }

//   //   console.log(stack);

//   if (stack.length === 0) return true;

//   return false;
// }

// More Faster Solution using hashmap and short inliner codes
const brackets: { [key: string]: string } = {
  ")": "(",
  "}": "{",
  "]": "["
}

function isValid(s: string): boolean {

  let stack: string[] = [];

  for (let i: number = 0; i < s.length; i++) {
      if (stack.length === 0) {
          stack.push(s[i]);
      }
      else if (brackets[s[i]] !== stack[stack.length - 1]) {
          stack.push(s[i]);
      }
      else
          stack.pop();

  }

  // console.log(stack);
 return (stack.length === 0);
};

//  Case 1 O.P. -> true
// let s:string = "()"

//  Case 2 O.P. -> true
// let s:string = "()[]{}"

//  Case 3 O.P. -> false
// let s:string = "(]"

//  Case 4 O.P. -> true
let s: string = "([{}])";

//  Case 5 O.P. -> false
// let s:string = "([{})"

console.log(isValid(s));
