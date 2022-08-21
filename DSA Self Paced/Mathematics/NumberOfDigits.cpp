/**
 * @file NumberOfDigits.cpp
 * @author ADITYA BHARDWAJ (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-15 or 2022-06-16 or 2022-06-13 or 2022-06-12 
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

//Iterative Solution
int NumberOfDigits(long);

//Recursive Solution
int countDigits(long); 

//Logarithmic Solution
int countDigitsLog(long);

int main()
{
    long n;
    int count, option;

    cout << "Enter the Number: ";
    cin >> n;

    cout << endl << "1. Iterative Solution" << endl;
    cout << "2. Recursive Solution" << endl;
    cout << "3. Logarithmic Solution" << endl;
    cin >> option;
    
    switch(option)
    {
        case 1:
        {
            count = NumberOfDigits(n);
            break;
        }

        case 2:
        {
            count = countDigits(n);
            break;
        }

        case 3:
        {
            count = countDigitsLog(n);
            break;
        }

        default: 
        {
            cout << "Incorrect option!!";
            break;
        }
    }

    cout << "Number of Digits in the Number: " << n << " is: " << count << endl;

    return 0;
}

//Iterative Solution - O(n)
int NumberOfDigits(long n)
{
    long temp = n;
    int count = 0;

    while(temp!=0)
    {
        temp=temp/10;
        count++;
    }

    return count;
}

//Recursive Solution - O(logn)
int countDigits(long n)
{
    if (n==0)
        return 0;
    
    return 1 + countDigits(n/10);
}

//Logarithmic Solution - Best Case - O(1)
int countDigitsLog(long n)
{
    return floor(log10(n) + 1);
}