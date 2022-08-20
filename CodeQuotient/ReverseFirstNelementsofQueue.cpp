/**
 * @file ReverseFirstNelementsofQueue.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief Reverse first N elements of a given queue star_border
Given a queue of integer elements and an integer k, your task is to reverse first k elements of the queue, leaving the other elements in same order.

Input Format

The first line of input will contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a number N followed by another number K. 
In second line of each test case N number of elements are given in order in which they will be inserted in queue.
The function void reverseKelementsQueue(int q[], int K) takes the queue and K as input and reverse first K elements of the queue.
Output Format

For each test case, you have to reverse the first k elements of queue in the array given. You are required to complete the methods given only.
Constraints

1 <= T <= 10
﻿1 <= N <= 100
﻿0 <= K <= N
Sample Input

2
4 2
1 2 3 4
5 3
10 20 30 40 50
Sample Output

2 1 3 4
30 20 10 40 50

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

class Queue
{
    int *queue;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size)
    {
        this->capacity = size;
        queue = new int[size];
        front = 0;
        rear = 0;
    }
    void enQueue(int data)
    {
        if (rear == capacity)
        {
            cout << "Overflow\n";
            return;
        }
        queue[rear++] = data;
    }
    int deQueue()
    {
        if (front == rear)
        {
            return -1;
        }
        return queue[front++];
    }
    bool isEmpty()
    {
        return front == rear;
    }
    int size()
    {
        return rear - front;
    }
};
// class Queue{
//   void enQueue(data);
//   int deQueue(data);
//   bool isEmpty();
// }
// The above class is used to declare the functions


#include <stack>

/**
 * @brief Solution Approach - Using Stack
 
The idea is to move first k elements from the queue to a stack. As in the stack the elements are stored in ‘Last In First Out’(LIFO) order, therefore the Kth element of the queue will be present at the top of the stack in the reverse order. Then move all the elements from the stack back to the queue. Finally, dequeue (size - k) elements from the queue, and enqueue them one by one to the same queue.

Algorithm:

Dequeue first k elements from the queue and simultaneously push them into the stack.
Pop the elements from the stack and enqueue them back to the queue.
Dequeue (size - k) elements from the queue, and enqueue them one by one to the same queue.
Time Complexity: O(size + k)

Space Complexity: O(size)
 * 
 */



/*
MY IMPLEMENTATION
*/


// void reverseKElementsQueue(Queue *queue, int k)
// {
//     // Write your code here
//     Queue *queue1 = new Queue(100);

//     stack<char> s;

//     while (!queue->isEmpty())
//     {
//         queue1->enQueue(queue->deQueue());
//     }
//     int i = 0;
//     while (i < k && !queue1->isEmpty())
//     {
//         s.push(queue1->deQueue());
//         i++;
//     }

//     while (!s.empty())
//     {
//         queue->enQueue(s.top());
//         s.pop();
//     }

//     while (!queue1->isEmpty())
//     {
//         queue->enQueue(queue1->deQueue());
//     }
// }



/* MORE EFFICIENT FUNCTION OF MY IMPLEMENTATION IN CASE OF SPACE COMPLECITY WILL BE:*/

#include <stack>
void reverseKElementsQueue(Queue *queue, int k)
{
    // Write your code here
    //Queue *queue1 = new Queue(100);

    stack<char> s;

    // while (!queue->isEmpty())
    // {
    //     queue1->enQueue(queue->deQueue());
    // }
    if (k > queue->size())
        return;

    int i = 0;
    while (i < k && !queue->isEmpty())
    {
        s.push(queue->deQueue());
        i++;
    }

    while (!s.empty())
    {
        queue->enQueue(s.top());
        s.pop();
    }

//     while (!queue1->isEmpty())
//     {
//         queue->enQueue(queue1->deQueue());
//     }

    for (int j = 0; j<(queue->size()-k); j++)
    {
        queue->enQueue(queue->deQueue());
    }
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        Queue *queue = new Queue(100);
        while (n--)
        {
            int x;
            cin >> x;
            queue->enQueue(x);
        }
        reverseKElementsQueue(queue, k);
        while ((n = queue->deQueue()) != -1)
            cout << n << ' ';
        cout << endl;
    }
}