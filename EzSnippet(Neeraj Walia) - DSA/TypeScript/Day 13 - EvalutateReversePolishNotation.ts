/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 13
 * 
 * @author ADITYA BHARDWAJ
 * 12/08/2023 12:30 PM
 * 
 * @description
 * 150. Evaluate Reverse Polish Notation
    Medium
    6.3K
    920
    Companies
    You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

    Evaluate the expression. Return an integer that represents the value of the expression.

    Note that:

    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.
    

    Example 1:

    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9
    Example 2:

    Input: tokens = ["4","13","5","/","+"]
    Output: 6
    Explanation: (4 + (13 / 5)) = 6
    Example 3:

    Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    Output: 22
    Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    = ((10 * (6 / (12 * -11))) + 17) + 5
    = ((10 * (6 / -132)) + 17) + 5
    = ((10 * 0) + 17) + 5
    = (0 + 17) + 5
    = 17 + 5
    = 22
    

    Constraints:

    1 <= tokens.length <= 104
    tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
    Accepted
    721.6K
    Submissions
    1.5M
    Acceptance Rate
    47.0%
 */

const operators: string[] = ["+", "-", "*", "/"];

function evalRPN(tokens: string[]): number | undefined {
  let stack: number[] = [];

  for (let i = 0; i < tokens.length; i++) {
    let num: number = parseInt(tokens[i]);
    if (!isNaN(num)) {
      stack.push(num);
    } else if (operators.includes(tokens[i])) {
      let a: number | undefined = stack.pop();
      let b: number | undefined = stack.pop();

      if (a !== undefined && b !== undefined) {
        switch (tokens[i]) {
          case "+":
            stack.push(b + a);
            break;
          case "-":
            stack.push(b - a);
            break;
          case "*":
            stack.push(b * a);
            break;
          case "/":
            stack.push(Math.trunc(b / a));
            break;
        }
      }
    }
  }

  return stack.length === 0 ? -1 : stack.pop();
}

// Case 1
/**
 * Output: 9
    Explanation: ((2 + 1) * 3) = 9
 */
// let tokens: string[] = ["2", "1", "+", "3", "*"];

// Case 2
/**
 * Output: 6
    Explanation: (4 + (13 / 5)) = 6
 */
// let tokens: string[] = ["4","13","5","/","+"];

// Case 3
/**
 * Output: 22
    Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    = ((10 * (6 / (12 * -11))) + 17) + 5
    = ((10 * (6 / -132)) + 17) + 5
    = ((10 * 0) + 17) + 5
    = (0 + 17) + 5
    = 17 + 5
    = 22
 */
let tokens: string[] = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"];

console.log(evalRPN(tokens));

