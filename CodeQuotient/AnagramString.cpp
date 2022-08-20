/*
Solution Approach 1 - Using sorting

For the two strings to be anagram of each other, their length must be the same. So firstly we will compare their length and if it is the same then:

1. Sort both the strings

2. Compare the sorted string, if they are equal that means they are anagram, else they are not.

Time Complexity: O(nlog(n))
*/

/*
#include <bits/stdc++.h>
using namespace std;

bool areAnagram(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();

    if (n1 != n2)
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

int main() {
    string str1 = "LISTEN";
    string str2 = "SILENT";

    if (areAnagram(str1, str2))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
*/

/*
Solution Approach 2 - Count Characters

In this approach, it is assumed that characters are stored using 8 bits and there can be 256 possible characters.

1. Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0.

2. Iterate through every character of both strings and increment the count of character in the corresponding count arrays.

3. Compare count arrays. If both count arrays are the same, then the two strings are anagram else they are not.

Time Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string str1, string str2)
{
    // Write your code here

    if (str1.length() != str2.length())
        return false;

    int count[256] = {0};

    for (int i = 0; str1[i] && str2[i]; i++)
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    int t, i, j = 0;
    string a, b;
    cin >> t;
    while (t--)
    {
        cin >> a;
        cin >> b;
        if (isAnagram(a, b))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
