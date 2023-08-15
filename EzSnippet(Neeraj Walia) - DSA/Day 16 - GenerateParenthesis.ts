/**
 * 
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 16
 * @author ADITYA BHARDWAJ
 * 14/08/2023 12:25 PM
 * 
 * @description
 * 22. Generate Parentheses
    Medium
    19.2K
    764
    Companies
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    

    Example 1:

    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]
    Example 2:

    Input: n = 1
    Output: ["()"]
    

    Constraints:

    1 <= n <= 8
    Accepted
    1.5M
    Submissions
    2M
    Acceptance Rate
    73.2%
 */

let pairOfParenthesis: string[];
const myGenerateParenthesis = (
  s: string,
  openBrackets: number,
  closeBrackets: number
) => {
  if (openBrackets === 0 && closeBrackets === 0) {
    pairOfParenthesis.push(s);
    return;
  }

  if (openBrackets > 0)
    myGenerateParenthesis(s + "(", openBrackets - 1, closeBrackets);

  if (closeBrackets > 0 && openBrackets !== closeBrackets)
    myGenerateParenthesis(s + ")", openBrackets, closeBrackets - 1);
};

function generateParenthesis(n: number): string[] {
  pairOfParenthesis = [];
  myGenerateParenthesis("(", n - 1, n);
  return pairOfParenthesis;
}

//Test Cases

//Case 1
let n: number = 3;

//Case 2
// let n:number=1;

console.log(generateParenthesis(n));
