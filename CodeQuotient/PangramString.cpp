/*
Solution Approach 2

In the previous approach, we were finding all the substrings that start from a vowel, but our task is not to find the substrings. instead we just need to get their count.

Now if we observe, the total number of substrings starting from a character is equal to the number of characters to the right of it, also including the current character. Therefore,

No of substrings starting from str[i] =  n - i ;	where n is the length of str

Using the above observation we can count the number of strings starting from a vowel, in linear time.

Time Complexity: O(n); n is the length of the given string

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'isPangrams' function below.
 * @params
 *   str -> a string that is to be tested for pangram
 *
 * @return
 *   boolean value, based on the fact, whether
 *   the given string is a pangram or not.
 */

bool isPangram(string str)
{
    // Write your code here
    int count[26] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            count[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    getchar();
    string str;
    while (t--)
    {
        getline(cin, str);
        if (isPangram(str))
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
        cout << endl;
    }
}