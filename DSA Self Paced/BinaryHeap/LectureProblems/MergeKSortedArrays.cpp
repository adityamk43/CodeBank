/**
 * @file MergeKSortedArrays.cpp
 * @author ADITYA BHARDWAJ
 * @brief We are given vectors of vector and we want to merge those k sorted vectors into one vector and return that sorted vector
 * @version 0.1
 * @date 2022-11-20 02:48 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Triplet
{
    int value;
    int apos;
    int vpos;

    public:
    Triplet(int value, int apos, int vpos)
    {
        this->value = value;
        this->apos = apos;
        this->vpos = vpos;
    }

    void setValue(int value)
    {
        this->value = value;
    }
    void setApos(int apos)
    {
        this->apos = apos;
    }
    void setVpos(int vpos)
    {
        this->vpos = vpos;
    }

    int getValue()
    {
        return this->value;
    }
    int getApos()
    {
        return this->apos;
    }
    int getVpos()
    {
        return this->vpos;
    }

};

struct Cmp
{
    bool operator() (Triplet &t1, Triplet &t2)
    {
        return t1.getValue() > t2.getValue();
    }
};

/**
 * @brief TIME COMPLEXITY: O(nklogk)
 * where n is the max elements in any vector inside a arr vector [Since, we are finding Big O we are taking max elements of particular vector as atmost n elements which can be present in any array]
 * 
 * @param arr 
 * @return vector<int> 
 */
vector<int> mergeKSortedArray(vector<vector<int>> arr)
{

    vector<int> res;
    priority_queue<Triplet, vector<Triplet>, Cmp> pq;

    //O(klogk)
    for (int i=0; i<arr.size(); i++)
    {
        Triplet tp(arr[i][0], i, 0);
        pq.push(tp);
    }

    //O(nklogk) where n is the max elements in any vector inside a arr vector [Since, we are finding Big O we are taking max elements of particular vector as atmost n elements which can be present in any array]
    while (!pq.empty())
    {
        Triplet curr = pq.top();
        res.push_back(curr.getValue());
        int vp = curr.getVpos();
        int apos = curr.getApos();
        pq.pop();

        if (vp+1 < arr[apos].size())
        {
            Triplet tp(arr[apos][vp+1], apos, vp+1);
            pq.push(tp);
        }
    }

    return res;

}

int main()
{
    vector<vector<int>> arr{{10,20,30},
                            {5, 15}, 
                            {1, 9, 11, 18}};
    
    vector<int> res = mergeKSortedArray(arr);

    for (auto it = res.begin(); it!=res.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}