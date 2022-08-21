/**
 * @file sortastack.cpp
 * @author ADITYA BHARDWAJ  (you@domain.com)
 * @brief Sort A Stack
    Given a stack output a sorted stack ?
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * @brief Sort a stack
Easy Accuracy: 50.51% Submissions: 67788 Points: 2
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
Your Task:
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.

Constraints:
1<=N<=100

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
 *
 */

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        SortedStack *ss = new SortedStack();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
} // } Driver Code Ends

/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

void sortStack(stack<int> &s, int top)
{
    if (s.empty() || top > s.top())
    {
        s.push(top);
    }
    else
    {
        int temp = s.top();
        s.pop();
        sortStack(s, top);
        s.push(temp);
    }
}

/**
 * @brief Recursively sort the stack: 
 * We can use the below algorithm to sort stack elements:

sortStack(stack S)
    if stack is not empty:
        temp = pop(S);  
        sortStack(S); 
        sortedInsert(S, temp);
Below algorithm is to insert element is sorted order:

sortedInsert(Stack S, element)
    if stack is empty OR element > top element
        push(S, elem)
    else
        temp = pop(S)
        sortedInsert(S, element)
        push(S, temp)
 * 
 */

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort()
{
    // Your code here
    if (s.empty())
        return;

    else if (!s.empty())
    {
        int top_el = s.top();
        s.pop();
        sort();
        sortStack(s, top_el);
    }
}