/**
 * @file SetCpp.cpp
 * @author ADITYA BHARDWAJ
 * @brief Map Basic usage
 * @version 0.1
 * @date 2022-11-09 11:07 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Maps in cpp are implemented using BST i.e. Red Black BST Tree.
 *      Difference between Maps and Sets is that Maps holds key and its values pairs
 *      whereas sets only holds values
 */
#include <iostream>
#include <map>

using namespace std;

int main()
{
    //simple increasing order of BST
    map<int, int> m;
    //If we want decreasing order
    // map<int, int, greater<int>> m;
    m.insert({1, 10});
    m.insert({3, 50});
    m.insert({7, 20});
    m.insert({12, 60});
    m.insert({10, 40});
    m[20] = 90;

    //empty() function can be used to check if map is empty or not

    //size
    cout << m.size() << endl;
    //this operator creates key value pair with default values as per the datatype
    m[32];
    //at operator can be used to update the value same as this above square bracket operator but the difference is that it doesn't create a default key value pair as described above rather if we tried to access unexisting key then it will raise "out of range" error
    m.at(32) = 5; //m[32] = 5;
    //Causes "out of range" error
    // m.at(31) = 5;
    cout << m.size() << endl;

    //simple traversal
    // for (auto &x:m)
    // {
    //     cout << x.first << " ";
    //     cout << x.second << " ";
    //     cout << endl;
    // }

    //using iterator
    // for (auto it=m.begin(); it!=m.end(); it++)
    // {
    //     cout << (*it).first << " ";
    //     cout << (*it).second << " ";
    //     cout << endl;
    // }

    //to clear the whole map
    // m.clear();
    
    //using reverse iterator
    for (auto it=m.rbegin(); it!=m.rend(); it++)
    {
        cout << (*it).first << " ";
        cout << (*it).second << " ";
        cout << endl;
    }
    cout << endl;

    // auto it= m.find(20);
    // auto it= m.find(200);

    // if (it==m.end())
    //     cout << "Not Found" << endl;
    // else
    //     cout << "Found" << endl;
    
    // int count = m.count(20);
    // int count = m.count(200);
    // cout << count << endl;

    // cout << m.erase(20) << endl;
    // auto it3 = m.find(20);
    // auto it3 = m.find(200);

    //erase using iterator takes amortised O(1) time but with key it takes O(logn)
    // m.erase(it3);

    // m.erase(m.find(20), m.end());

    // for (auto it=m.rbegin(); it!=m.rend(); it++)
    // {
    //     cout << (*it).first << " ";
    //     cout << (*it).second << " ";
    //     cout << endl;
    // }
    // cout << endl;


    auto it4 = m.lower_bound(10);
    // auto it4 = m.lower_bound(5);
    // auto it4 = m.lower_bound(100);

    auto it5 = m.upper_bound(10);
    // auto it5 = m.upper_bound(21);
    // auto it5 = m.upper_bound(210);

    if (it4!=m.end())
    {
        cout << (*it4).first << " ";
        cout << (*it4).second << " ";
    }
    else
        cout << "No equal or Greater Value";
    cout << endl;

    if (it5!=m.end())
    {
        cout << (*it5).first << " ";
        cout << (*it5).second << " ";
    }
    else
        cout << "No Greater Value";
    cout << endl;


    return 0;
}