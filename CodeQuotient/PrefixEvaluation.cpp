/**
 * @file PrefixEvaluation.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Evaluate the prefix expression using Stack star_border
Given a prefix expression, evaluate it using stack and print the final output.

Complete the evalPrefix() function and return the final output.

Input Format

The first line of input contains an integer T denoting the number of test cases. The next T lines contain a prefix expression.
An expression in prefix form will consist of all digits and following five operators: +, -, *, /, ^
Output Format

Print the final output of prefix expression evaluation in new line for each test case.
Sample Input

1
+-*235/^234
Sample Output

3

 * @version 0.1
 * @date 2022-06-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;
#define SIZE 100

int Stack[SIZE], top = -1;

int isFull()
{
    return top == (SIZE - 1);
}

int isEmpty()
{
    return top == -1;
}

// Function to add an item to stack.  It increases top by 1
int push(int item)
{
    if (isFull())
    {
        return -1;
    }
    Stack[++top] = item;
}

// Function to remove an item from stack.  It decreases top by 1
int pop()
{
    int temp;
    if (isEmpty())
    {
        return -1;
    }
    temp = Stack[top--];
    return temp;
}
/*
int Stack[SIZE], top=-1;
int isFull();
int isEmpty();
int push(int item);
int pop();

Above variables are used for Stack, SIZE and top and all are global variables. Also above push and pop functions are provided. */

/**
 * @brief 
Stack Applications: Prefix evaluation
  
 
Prefix Evaluation using stack: 

Similar to postfix evaluation we can evaluate prefix expressions also using stack. We can do it in two ways.

(i) Convert prefix to postfix expression and apply the same procedure.

(ii) Make below changes in postfix evaluation algorithm: 

	(a) Read input from last symbol to first symbol in reverse direction.

	(b) While evaluating any operator, change the operand positions.

So following algorithm will evaluate an prefix expression using stack

Create a new stack
while (input stream is not empty)
  data = readNext();    // Read from right most symbol to left most symbol
  if(data is an operand)
    push(data);
  else if (data is an operator)
    op1 = pop();
    op2 = pop();
    result = (op1) data (op2);
    push(result);
  end if
end while
answer = pop()
return answer;
Let us evaluate above algorithm with following expression: -

+ 6 * + 2 3 7


 
Step                                                                                   Stack → top on right side
1. read 7, it is an operand so push on stack                                                   7
2. read 3, it is an operand so push on stack                                                   7 3
3. read 2, it is an operand so push on stack                                                   7 3 2
4. read +, it is an operator so pop from stack two times and we get 2, 3. 
   Now evaluate 2 + 3 and push the result back                                                 7 5
5. read *, it is an operator so pop from stack two times and we get 5, 7. 
   Now evaluate 5 * 7 and push the result back                                                 35
6. read 6, it is an operand so push on stack                                                   35 6
7. read +, it is an operator so pop from stack two times and we get 6, 35. 
   Now evaluate 6 + 35 and push the result back                                                41
8. expression ends, so pop from stack and return the answer

 * 
 */


int evalPrefix(char *exp)
{
    for (int i = (strlen(exp) - 1); i >= 0; i--)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            int opd1 = pop();
            int opd2 = pop();

            if (exp[i] == '+')
            {
                push(opd1 + opd2);
            }
            else if (exp[i] == '-')
            {
                push(opd1 - opd2);
            }
            else if (exp[i] == '/')
            {
                push(opd1 / opd2);
            }
            else if (exp[i] == '*')
            {
                push(opd1 * opd2);
            }
            else if (exp[i] == '^')
            {
                push(pow(opd1, opd2));
            }
        }
    }

    int result = pop();

    return result;
}
int main()
{
    int n;
    char *exp, input[100];
    cin >> n;
    exp = input;
    while (n--)
    {
        cin >> exp;
        cout << evalPrefix(exp) << endl;
    }
    return 0;
}
