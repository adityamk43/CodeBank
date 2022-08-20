/**
 * @file ReverseStringUsingStack.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Reverse a string using stack star_border
Given a string, the task is to reverse the string using stack data structure.

Complete the function reverseString() that accepts the string, and reverses the string.

Input Format

The first line of input will contains an integer T denoting the no of test cases. Then T test cases follow. 
Each test case contains a number N.
Then N strings follow which are to be reversed
Output Format

For each test case, you have to reverse the string in the array given. You are required to complete the methods given only.
Constraints

1 <= T <= 10
﻿0 <= N <= 100
Given strings consist of uppercase and lowercase English letters.
Sample Input

1 // No. of test cases
2 // No. of strings
CodeQuotient
Code
Sample Output

tneitouQedoC
edoC﻿

 * @version 0.1
 * @date 2022-06-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class CQStack
{
    int maxSize; // size of stack array
    int *stackArray;
    int top; // top of stack

public:
    // constructor
    CQStack(int s)
    {
        maxSize = s;                   // set array size
        stackArray = new int[maxSize]; // create array
        top = -1;                      // no items yet
    }

    // Add element on the top of the stack
    void push(int j)
    {
        if (isFull())
        {
            return;
        }
        else
        {
            stackArray[++top] = j; // increment top, insert item
        }
    }

    // Remove element from the top of the stack
    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            int temp = stackArray[top--];
            return temp; // access item, decrement top
        }
    }

    // Return true is stack is empty
    bool isEmpty()
    {
        return (top == -1);
    }

    // Return true if stack is full
    bool isFull()
    {
        return (top == maxSize - 1);
    }
};
/* class CQStack{
    public:
        CQStack(int s); // constructor
        void push(int j); // Add element on the top of the stack
        int pop();  // Remove element from the top of the stack
        bool isEmpty(); // Return true is stack is empty
        bool isFull(); // Return true if stack is full
    };
    CQStack class already defined as per the above blueprint
*/

/**
 * @brief  
The idea is to use a stack because in stack, elements are stored in LIFO manner.

Algorithm:

Declare a stack.
Traverse the given string character by character from left to right, and keep inserting them in the stack.
Note: Do not insert the null char(‘\0’ - that marks the end of the string) in the stack.
After all the characters are inserted in the stack, then start popping them one by one from the stack and parallely insert them in the given string starting from 0 index.
Print the modified string.


Time Complexity: O(string_length)

Space Complexity: O(string_length)
 * 
 */
string reverseString(CQStack *stack, string s)
{

    for (int i = 0; i < s.length(); i++)
    {
        stack->push(s[i]);
    }
    string rev = "";

    while (!stack->isEmpty())
    {
        rev.push_back(stack->pop());
    }

    // for (int j = 0; j < s.length(); j++)
    // {
    //     rev = rev + char(stack->pop());
    // }

    return rev;
}
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> n;
        while (n--)
        {
            CQStack *stack = new CQStack(1000);
            cin >> s;
            s = reverseString(stack, s);
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}