/**
 * @file PostfixEvaluation.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Evaluate the postfix expression using Stack star_border
Given a postfix expression, evaluate it using stack and print the final output.

Input

The first line of input contains an integer T denoting the number of test cases. The next T line contains a postfix expression. An expression in postfix form will consist of all digits and following five operators: +, -, *, /, ^.
Output

Print the final output of postfix expression evaluation in new line for each test case.
Sample Input

2
8425+-*
546+*493/+*
Sample Output

-24
350

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

/**
 * @brief Stack Applications: Postfix evaluation
  
 
The linear data structure stack can be used in the following situations.

1. It can be used to process function calls.

2. Implementing recursive functions in high level languages

3. Converting and evaluating expressions.

4. Backtracking in searching techniques

And many more

Let us see the use of stack in evaluating and expressing expressions in different formats.  In general there are 3 kinds of expressions available depending on the placement of the operators & operands.

a. Infix expression: - It is the general notation used for representing expressions. “In this expression the operator is fixed in between the operands”. Ex: a + b 

b. Post fix expression: - Also known as reverse polish notation. “In this expression the operator is placed after the operands”. Ex : ab+

c. Prefix expression: - Also known as polish notation. “In this expression the operators are followed by operands i.e the operators are fixed before the operands”. Ex : +ab

All the infix expressions can be converted into post fix notation with the help of stack and stack will be useful in evaluating the postfix expressions also.

Following are the common operators used in these expressions and their hierarchy of evaluation:-



Operator                                     Hierarchy
^, **, ↑, $ (Exponentiation or Power)        Highest Level
/ (Division)                                 Second level
* (Multiplication)                           Second level
+ (Addition)                                 Third level
- (Subtraction)                              Third level
Postfix Evaluation using stack
 
Assume we have a string of operands and operators, then to evaluate it without computer we use following steps: -

Scan the expression left to right
Skip values or variables (operands)
When an operator is found, apply the operation to the preceding two operands
Replace the two operands and operator with the calculated value (three symbols are replaced with one operand)
Continue scanning until only a value remains i.e. the result of the expression
The time complexity is O(n) because each operand is scanned once, and each operation is performed once.

We can use stack to do this as an algorithm and make use of computers to do this as below: -

Create a new stack
while (input stream is not empty)
  data = readNext();
  if(data is an operand)
    push(data);
  else if (data is an operator)
    op2 = pop();
    op1 = pop();
    result = (op1) data (op2);
    push(result);
  end if
end while
answer = pop()
return answer;
Let us evaluate above algorithm with following expression: -

6 3 2 + 7 * +



Step                                                                              Stack → top on right side
1. read 6, it is an operand so push on stack                                           6
2. read 3, it is an operand so push on stack                                           6 3
3. read 2, it is an operand so push on stack                                           6 3 2
4. read +, it is an operator so pop from stack two times and we get 2, 3. 
   Now evaluate 3 + 2 and push the result back                                         6 5
5. read 7, it is an operand so push on stack                                           6 5 7
6. read *, it is an operator so pop from stack two times and we get 7, 5. 
   Now evaluate 5 * 7 and push the result back                                         6 35
7. read +, it is an operator so pop from stack two times and we get 35, 6. 
   Now evaluate 6 + 35 and push the result back                                        41
8. expression ends, so pop from stack and return the answer
 * 
 */


/**
 * @brief MY EFFICIENT IMPLEMENTATION
 * 
 */

/* pop(),push(int j) already defined in stack */
int evalPostfix(CQStack *stack, string exp)
{

    for (int i = 0; i < exp.length(); i++)
    {
        if (isdigit(exp[i]))
        {
            stack->push(exp[i] - '0');
        }
        else
        {
            int opd2 = stack->pop();
            int opd1 = stack->pop();

            if (exp[i] == '+')
            {
                stack->push(opd1 + opd2);
            }
            else if (exp[i] == '-')
            {
                stack->push(opd1 - opd2);
            }
            else if (exp[i] == '/')
            {
                stack->push(opd1 / opd2);
            }
            else if (exp[i] == '*')
            {
                stack->push(opd1 * opd2);
            }
            else if (exp[i] == '^')
            {
                stack->push(pow(opd1, opd2));
            }
        }
    }

    int result = stack->pop();

    return result;
}

/**
 * @brief MY FIRST APPROACH IMPLEMENTATION
 * 
 */

/*
int evalPostfix(CQStack *stack,string exp){
  
  for (int i = 0; i<exp.length(); i++)
  {
    if (exp[i] == '+')
    {
      int item = stack->pop() + stack->pop();
      //cout << endl << item << endl;
      stack->push(item);
    }
    else if (exp[i] == '-')
    {
      int item = (stack->pop() - stack->pop());
      //cout << endl << "- wala op " << item << endl;
      stack->push(-item);
    }
    else if (exp[i] == '/')
    {
      int item = stack->pop();
      stack->push(stack->pop()/item);
    }
    else if (exp[i] == '*')
    {
      stack->push(stack->pop()*stack->pop());
    }
    else if (exp[i] == '^')
    {
      int item = stack->pop();
      stack->push(pow(stack->pop(), item));
    }
    else{
      //cout << endl << exp[i] << endl;
      stack->push(exp[i]-'0');
    }
  }
  
  int result = stack->pop();
  
  return result;
    
}
*/

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        string expr;
        CQStack *stack = new CQStack(1000);
        cin >> expr;
        int result = evalPostfix(stack, expr);
        cout << result << endl;
    }
    return 0;
}