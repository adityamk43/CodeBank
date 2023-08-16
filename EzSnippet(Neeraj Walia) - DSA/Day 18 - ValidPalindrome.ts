/**
 * @event Neeraj Walia (EzSnippet) DSA Challenge DAY - 18
 * @author ADITYA BHARDWAJ
 * 16/08/2023 11:35 PM
 * 
 * @desciption
 * 125. Valid Palindrome
    Easy
    7.8K
    7.6K
    Companies
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

    

    Example 1:

    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
    Example 2:

    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.
    Example 3:

    Input: s = " "
    Output: true
    Explanation: s is an empty string "" after removing non-alphanumeric characters.
    Since an empty string reads the same forward and backward, it is a palindrome.
    

    Constraints:

    1 <= s.length <= 2 * 105
    s consists only of printable ASCII characters.
    Accepted
    2.2M
    Submissions
    4.8M
    Acceptance Rate
    45.3%

 * 
 * @return
 * Accepted
    Runtime
    Details
    55ms
    Beats 98.37%of users with TypeScript

    Memory
    Details
    44.46mb
    Beats 95.04%of users with TypeScript
 */

function isPalindrome(s: string): boolean {
  s = s.toLowerCase().replace(/[^a-z0-9]/gi, "");

  let i = 0,
    j = s.length - 1;
  while (s.length !== 0 && i <= j) {
    if (s.charAt(i) !== s.charAt(j)) return false;

    i++;
    j--;
  }
  return true;
}

//Test Case

//Case 1
let s:string="A man, a plan, a canal: Panama";

//Case 2
// let s:string="race a car";

//Case 1
// let s:string=" ";

console.log(isPalindrome(s));
