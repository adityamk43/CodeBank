/**
 * @file powerSet.cpp
 * @author Aditya Bhardwaj (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

void powSet(string str)
{
    int len = str.length();

    for (int counter=0; counter< pow(2, len); counter++)
    {

        for (int j=0; j<len; j++)
        {
            if ((counter & (1<<j)) != 0)
                cout << str[j];
        }
        cout << "\n";
    }
}
int main()
{
    string s = "abc";

    powSet(s);
    
    return 0;
}