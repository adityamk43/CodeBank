/**
 * @file PriorityQueue.cpp
 * @author ADITYA BHARDWAJ
 * @brief basics of priority queue in STL C++
 * 
 * APPLICATIONS OF PRIORITY QUEUE:
 * 
 * 1.) Dijkstra Algorithm
 * 2.) Prim Algorithm
 * 3.) Huffman Algorithm
 * 4.) Heap Sort
 * 5.) And any other place where heap is used
 * 
 * @version 0.1
 * @date 2022-11-19 05:01 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <queue>
using namespace std;
//Using priority Queue for pairs or custom user defined datatype based on custom comparisons
//For Pairs default comparison data is the first element present in pair

struct Person{
    int age;
    float ht;

    Person(int a, int h)
    {
        age=a;
        ht=h;
    }
};

struct myCmp{

    bool operator() (Person &p1, Person &p2)
    {
        //decreasing order
        return p1.ht<p2.ht;
        //increasing order
        // return p1.ht>p2.ht;
    }
};


int main()
{

    /**
     * @brief 
     * TIME COMPLEXITY:
     * O(logn):
     * push
     * pop;
     * O(1)
     * size
     * top
     * empty
     * O(n):
     * creating Priority Queue using exising Array
     * 
     */


    //Default priority queue is made from MaxHeap in C++
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(15);
    pq.push(35);

    cout << "MaxHeap" << endl;
    cout << "size: " << pq.size() << endl;
    cout << "Max Element(For MaxHeap) in PQ: " << pq.top() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    //MinHeap Example in C++ STL
    priority_queue<int, vector<int>, greater<int>> mpq;
    mpq.push(30);
    mpq.push(20);
    mpq.push(10);
    mpq.push(15);
    mpq.push(35);

    cout << "MinHeap" << endl;
    cout << "size: " << mpq.size() << endl;
    cout << "Min Element(For MinHeap) in PQ: " << mpq.top() << endl;

    while (!mpq.empty())
    {
        cout << mpq.top() << " ";
        mpq.pop();
    }
    cout << endl;


    //Creating a Priority Queue using an existing array
    int arr[] = {10, 5, 15};

    //This way of creating priority queue is less costlier as compared to pushing one by one as T.C. for this is O(n) (Sim like BuildHeap Function)
    priority_queue<int> pqe(arr, arr+3);

    cout << endl << "PQ Using Exising Array: " << endl;
    while (!pqe.empty())
    {
        cout << pqe.top() << " ";
        pqe.pop();
    }
    cout << endl;

    //Another way of creating MinHeap in a simpler way using MaxHeap in C++
    for (int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++)
        arr[i] = -arr[i];
    priority_queue<int> pqmm(arr, arr+3);


    cout << endl << "MinHeap Using MaxHeap: " << endl;
    while (!pqmm.empty())
    {
        cout << -pqmm.top() << " ";
        pqmm.pop();
    }
    cout << endl;

    //Using priority Queue for pairs or custom user defined datatype based on custom comparisons
    //For Pairs default comparison data is the first element present in pair
    priority_queue<Person, vector<Person>, myCmp> pqpp;

    Person p1(22, 175);
    Person p2(23, 162);
    Person p3(33, 180);
    Person p4(21, 155);
    Person p5(25, 170);

    pqpp.push(p1);
    pqpp.push(p2);
    pqpp.push(p3);
    pqpp.push(p4);
    pqpp.push(p5);

    cout << endl << "PQ of Custom Datatype: " << endl;
    while (!pqpp.empty())
    {
        cout << pqpp.top().age << ":" << pqpp.top().ht << " ";
        pqpp.pop();
    }
    cout << endl;

    return 0;
}