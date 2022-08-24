/**
 * @file PossibleWordsFromPhoneDigits.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-24 10:17AM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;


void possibleWords(int a[], vector<char> words[], int n, string curr = "", int index = 0)
{
    if (index == n)
    {
        cout << curr << endl;
        return;
    }
    
    int element = a[index];
    
    int len = words[element].size();

    for (int i=0; i<len; i++)
    {
        possibleWords(a, words, n, curr + words[element][i], index + 1);
    }
}

int main()
{
    vector<char> words[] = { 
        {}, {}, 
        {'a', 'b', 'c'}, 
        {'d', 'e', 'f'}, 
        {'g', 'h', 'i'}, 
        {'j', 'k', 'l'}, 
        {'m', 'n', 'o'}, 
        {'p', 'q', 'r', 's'}, 
        {'t', 'u', 'v'}, 
        {'w', 'x', 'y', 'z'}
    };


    int a[] = {2,3,4};
    int n = sizeof(a)/sizeof(a[0]);
    possibleWords(a, words, n);
    return 0;
}

/*
// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find all possible combinations by
// replacing key's digits with characters of the
// corresponding list
void findCombinations(vector<char> keypad[],
					int input[], string res, int index, int n)
{
	// If processed every digit of key, print result
	if (index == n) {
		cout << res << " ";
		return;
	}

	// Stores current digit
	int digit = input[index];

	// Size of the list corresponding to current digit
	int len = keypad[digit].size();

	// One by one replace the digit with each character in the
	// corresponding list and recur for next digit
	for (int i = 0; i < len; i++) {
		findCombinations(keypad, input, res + keypad[digit][i], index + 1, n);
	}
}

// Driver Code
int main()
{
	// Given mobile keypad
	vector<char> keypad[] =
	{
		{}, {},	 // 0 and 1 digit don't have any characters associated
		{ 'a', 'b', 'c' },
		{ 'd', 'e', 'f' },
		{ 'g', 'h', 'i' },
		{ 'j', 'k', 'l' },
		{ 'm', 'n', 'o' },
		{ 'p', 'q', 'r', 's'},
		{ 't', 'u', 'v' },
		{ 'w', 'x', 'y', 'z'}
	};

	// Given input array
	int input[] = { 2, 3, 4 };
	
	// Size of the array
	int n = sizeof(input)/sizeof(input[0]);

	// Function call to find all combinations
	findCombinations(keypad, input, string(""), 0, n );

	return 0;
}

*/