/**
 * @file InfixToPostfixStack.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Convert infix expression to postfix expression star_border
Given an infix expression, convert the infix to postfix expression.

Input

The first line of input contains an integer T denoting the number of test cases. The next T line contains an infix expression. An expression in infix form will consist of all characters and following five operators: +, -, *, /, ^ along with two braces (, ).

The operators have the following properties:
a. Expressions within brackets are always evaluated first.
b. Precedence of Power (^) is highest, then Multiply(*) and Division (/), at last Addition (+) and Subtraction (-) have lowest precedence.
c. All operators have left to right associativity.
Output

The postfix expression equivalents to given infix expression. Complete the function given below.
Sample Input

2
A*(B+C)/D
(A-(B+C))*D
Sample Output

ABC+*D/
ABC+-D*

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
int peek()
{
    if (top == -1)
        return -1;
    else
        return (Stack[top]);
}
/*
int Stack[SIZE], top=-1;
int isFull();
int isEmpty();
int push(int item);
int pop();

Above variables are used for Stack, SIZE and top and all are global variables. Also above push and pop functions are provided. */

/**
 * @brief Stack Applications: infix to Postfix Conversion


Conversion from infix to postfix expression

We can use stack in converting infix expressions to postfix notation. For this, we have to hold information that's expressed inside parentheses while scanning to find the closing ')'. Also we have to hold information on operations that are of lower precedence on the stack.  The algorithm to do this can be written as below:

Create an empty stack and an empty postfix output string
Scan the infix input string left to right
while (input string is not empty)
  token = readNext();
  If (token is an operand)     // If Operand found
    Add it to the output string
  End if
  If (token is an operator)     // If Operator found
    Pop off all operators that have equal or higher precedence
    Append them to the output string.
    Push the token onto the stack.
  End if
  If (token is '(')    // If Left parentheses found
    Push it onto the stack
  End if
  If (token is ')')     // If Right parentheses found
    Pop off all operators and append them to the output string until a '(' is popped;
    Discard the '('.
  End if
End while
Pop all operators and append them to the output string.
Return the output string as final answer
Let us evaluate above algorithm with following expression: -

6 / ( 3 ^ 2 ) - 8



Current Symbol         Stack →Top is on right      Output            Remarks
6                                                    6               Add operand to output
/                         /                          6               No operators on stack so just push / on stack
(                         / (                        6               Push ( on stack
3                         / (                        6 3             Add operand to output
^                         / ( ^                      6 3             No operators on stack so just push ^ on stack
2                         / ( ^                      6 3 2           Add operand to output
)                         /                          6 3 2 ^         Pop all operators till ‘(’, add on output and discard ‘(‘
-                         -                          6 3 2 ^ /       Pop higher precedence operators and add them to output, then place current operator on stack
8                         -                          6 3 2 ^ / 8     Add operand to output
Empty                                                6 3 2 ^ / 8 -   Input is empty, so pop from stack and add to output
 *
 */

int isOperand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (isdigit(ch)));
}

int checkPrecedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return -1;
}

int infixToPostfix(char exp[], char output[])
{
    int k = 0, i = 0;

    while (exp[i])
    {

        if (isOperand(exp[i]))
            output[k++] = exp[i];
        else if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                output[k++] = pop();
            }
            pop();
        }
        else
        {
            while (!isEmpty() && checkPrecedence(exp[i]) <= checkPrecedence(peek()))
            {
                output[k++] = pop();
            }
            push(exp[i]);
        }

        i++;
    }

    while (!isEmpty())
    {
        if (peek() == '(')
            return -1;
        output[k++] = pop();
    }
    output[k++] = '\0';
}

/**
 * @brief OUTDATED AND DANGEROUS APPROACH NOT APPLYING PEEK AND USING POP TO COMPARE OPERATOR PRECEDENCE AND BEACKETS
 *
 */

/*
int infixToPostfix(char exp[], char output[])
{
    int k = 0, i = 0;
    while (exp[i])
    {
        if (isOperand(exp[i]))
            output[k++] = exp[i];
        else if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            int op = pop();
            while (!isEmpty() && op != '(')
            {
                output[k++] = op;
                op = pop();
            }
        }
        else
        {
            int op = pop();
            while (!isEmpty() && checkPrecedence(exp[i]) <= checkPrecedence(op))
            {
                output[k++] = op;
                op = pop();
            }

            push(op);
            push(exp[i]);
        }
        i++;
    }
    while (!isEmpty())
        output[k++] = pop();

    output[--k] = '\0';
}
*/

int main()
{
    int n;
    char *exp, input[100], output[100];
    cin >> n;
    exp = input;
    while (n--)
    {
        cin >> exp;
        infixToPostfix(exp, output);
        cout << output << endl;
    }
    return 0;
}