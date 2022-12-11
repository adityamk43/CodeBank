/**
 * @file PermutationsWithoutAB.cpp
 * @author ADITYA BHARDWAJ
 * @brief we have to print all permutations of given strings whose permutation doesn't contains specific substring.
 * Eg: Printing Permutation of "ABCD" whose permutation doesn't contains "AB" as a substring!!
 * Normally it will take O(n * n!) as we did in recursion track but with the help of backtracking we can cut down a lot of recursive function stack calls which will make Time Complexity much less than O(n * n!).
 * 
 * THERE IS ONE THING COMMON IN MOST BACKTRACKING SOLUTIONS. THAT IS, WE USE is_Safe() FUNCTION TO BACKTRACK WHEN WE DOESN'T GET THE MATCHING CRITERIA.
 * 
 * LIKE IN THIS PROBLEM AS SOON AS WE SEE THAT AFTER SWAPPING WE GET "AB" AS A SUBSTRING, WE STOP AND BACKTRACK FROM THERE REDUCING RECURSION BY NOT PRINTING THAT PERMUTATIONSSS.
 * 
 * @version 0.1
 * @date 2022-12-11 08:26 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
using namespace std;

bool isSafe(string s, int i, int l)
{
    if (l!=0 && s[l-1]=='A' && s[i] == 'B')
        return false;
    if (s.length()-1==(l+1) && s[i] == 'A' && s[l] == 'B')
        return false;
    
    return true;
}

void printPermutation(string s, int l)
{
    if (s.length()-1 == l)
    {
        cout << s << endl;
        return;
    }

    for (int i=l; i<s.length(); i++)
    {
        if (isSafe(s, i, l))
        {
            swap(s[i], s[l]);
            printPermutation(s, l+1);
            swap(s[i], s[l]);
        }
    }
}

int main()
{
    string s = "ABCD";
    // string s = "ABC";

    printPermutation(s, 0);

    return 0;
}