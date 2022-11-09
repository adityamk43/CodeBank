/**
 * @file SetCpp.cpp
 * @author ADITYA BHARDWAJ
 * @brief Sets Basic usage
 * @version 0.1
 * @date 2022-11-09 10:07 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Sets in cpp are implemented using BST i.e. Red Black BST Tree 
 */
#include <iostream>
#include <set>

using namespace std;

int main()
{
    //simple increasing order of BST
    set<int> s;
    //If we want decreasing order
    // set<int, greater<int>> s;
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(60);
    s.insert(40);

    //size
    cout << s.size() << endl;

    //empty() function can be used to check if set is empty or not

    //simple traversal
    // for (int x:s)
        // cout << x << " ";

    //using iterator
    // for (auto it=s.begin(); it!=s.end(); it++)
    //     cout << *it << " ";
    
    //using reverse iterator
    for (auto it=s.rbegin(); it!=s.rend(); it++)
        cout << *it << " ";
    cout << endl;

    auto it= s.find(20);
    // auto it= s.find(200);

    if (it==s.end())
        cout << "Not Found" << endl;
    else
        cout << "Found" << endl;
    
    int count = s.count(20);
    // int count = s.count(200);
    cout << count << endl;

    // cout << s.erase(20) << endl;
    // auto it3 = s.find(20);
    // auto it3 = s.find(200);

    //erase using iterator takes amortised O(1) time but with value it takes O(logn)
    // s.erase(it3);

    // s.erase(s.find(20), s.end());

    // for (auto it=s.begin(); it!=s.end(); it++)
        // cout << *it << " ";
    // cout << endl;

    auto it4 = s.lower_bound(10);
    // auto it4 = s.lower_bound(5);
    // auto it4 = s.lower_bound(100);

    auto it5 = s.upper_bound(10);
    // auto it5 = s.upper_bound(21);
    // auto it5 = s.upper_bound(210);

    if (it4!=s.end())
    {
        cout << *it4 << endl;
    }
    else
        cout << "No equal or Greater Value";
    cout << endl;

    if (it5!=s.end())
    {
        cout << *it5 << endl;
    }
    else
        cout << "No Greater Value";
    cout << endl;

    return 0;
}