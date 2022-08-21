/**
 * @file GenerateSubsets.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-21 10:40PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

void generateSubsets(string &str, int start=0, string current="")
{
    if (str.length() == start)
    {
        if (current == "")
            cout << "{Empty Set}" << " ";
        
        else
            cout << current << " ";
        
        return;
    }

    generateSubsets(str, start+1, current);
    generateSubsets(str, start+1, current + str[start]);
}

int main()
{
    string str = "ABC";
    generateSubsets(str);
    return 0;
}