/**
 * @file Permutations.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 * @version 0.1
 * @date 2022-08-25 9:10AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutations(string &s, vector<string> &curr, int i = 0)
{
    if (i == s.length()-1)
    {
        curr.push_back(s);
        return;
    }

    for (int j=i; j<s.length(); j++)
    {
        swap(s[i], s[j]);
        permutations(s, curr, i+1);
        swap(s[i], s[j]);
    }
}

vector<string> myPermutations(string &s)
{
    vector<string> curr;
    permutations(s, curr);
    sort(curr.begin(), curr.end());
    return curr;
}

int main()
{
    // string s = "ABC";
    string s = "ABCD";
    vector<string> perm = myPermutations(s);

    for (auto elem : perm)
        cout << elem << " ";
    return 0;
}