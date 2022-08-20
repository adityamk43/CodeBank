/**
 * @file CheckBalancedParenthesis.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Check balanced parentheses in an expression star_border
Given an expression only containing upper-case alphabets: A-Z, operators: /, * , +, - and characters: (,),{,},[,] used to mark start and end of parentheses, validate whether the parentheses are balanced or not.

Examples:

()    ==>  YES
)(    ==>  NO
(2+2) ==> YES
{3+(2+5)} ==> YES
{} ==> YES
(3*4+(6) ==>  NO
({2+5)} ==>  NO
Input Format:

A string with alphanumeric characters or one of the characters '{', '}', '(','),'[' or ']'.
Output Format:

For each test case print "YES" if the string has balanced parentheses, else print "NO"
Sample Input 1

()
Sample Output 1

YES
Explanation 1

The String is balanced
Sample Input 2

)(
Sample Output 2

NO
Explanation﻿ 2

The string is not balanced

 * @version 0.1
 * @date 2022-06-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Solution Approach - Using Stack
 
Algorithm:

First declare a stack data structure.
Then start traversing the given expression from left to right.
Now for each character check,
  If it is an opening bracket (i.e. '(' or '{' or '['), then
    push it into the stack
  Else, If it is a closing bracket (i.e. ')' or '}' or ']') and the stack is not empty, then check
    If the top element in the stack is its matching opening bracket or not.
    If it is not, then the brackets are not balanced,
      so return false.
    Else,
      pop the top element from the stack.
  Else, If the stack was empty, that means the expression is not balanced.
    so return false.
After the traversal completes check,
if the stack is still not empty then,
  return false.
else, the given expression is balanced
  so return true.
Time Complexity: O(n)

Space Complexity: O(n)
 * 
 */
bool areBracketsBalanced(char exp[])
{
    // Write your code here
    stack<char> s;

    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            s.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (s.empty())
                return false;

            if (exp[i] != ')' && s.top() == '(')
                return false;
            else if (exp[i] != '}' && s.top() == '{')
                return false;
            else if (exp[i] != ']' && s.top() == '[')
                return false;

            s.pop();
        }
    }

    if (!s.empty())
        return false;

    return true;
}

int main()
{
    char exp[100];
    scanf("%s", exp);
    if (areBracketsBalanced(exp))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}