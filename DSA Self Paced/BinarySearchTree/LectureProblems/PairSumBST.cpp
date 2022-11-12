/**
 * @file PairSumBST.cpp
 * @author ADITYA BHARDWAJ
 * @brief find the pair sum with the given sum in the BST
 * @version 0.1
 * @date 2022-11-12 09:17 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int key)
    {
        this->key = key;
        left=right=NULL;
    }

};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

/**
 * @brief using Converting Tree to List using inorder traversal to store the values in sorted manner
 * 
 * @param root 
 * @param arr 
 */
void treeToList(Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    
    treeToList(root->left, arr);
    arr.push_back(root->key);
    treeToList(root->right, arr);

}

/**
 * @brief TIME COMPLEXITY: O(n)
 *        AUX SPACE: O(n+h) approx O(n) h can be ignored since it is small as compared to n
 * 
 * @param root 
 * @param sum 
 * @return true 
 * @return false 
 */
bool checkPairSumWithArray(Node *root, int sum)
{
    vector<int> arr;

    treeToList(root, arr);

    for (auto i: arr)
        cout << i << " ";
    cout << endl;

    int start = 0;
    int end = arr.size()-1;

    while (start < end)
    {
        if (arr[start] + arr[end] == sum)
        {
            cout << "The Pair Sums are: " << arr[start] << " And " << arr[end] << endl; 
            return true;
        }

        else if (arr[start] + arr[end] > sum)
            end--;
        else if (arr[start] + arr[end] < sum)
            start++;
    
    }

    return false;

}


/**
 * @brief TIME COMPLEXITY: O(n)
 *        AUX SPACE: O(h)
 * 
 * USING INORDER TRAVERSAL AND SET
 * 
 * @param root 
 * @param s 
 * @param sum 
 * @return true 
 * @return false 
 */
bool checkPairSum(Node *root, set<int> &s, int sum)
{
    if (root == NULL)
        return false;
    
    if (checkPairSum(root->left, s, sum) == true)
        return true;

    if (s.find(sum - root->key) == s.end())
        s.insert(root->key);
    else
        return true;
    
    return checkPairSum(root->right, s, sum);
}

int main()
{
    //YES
    Node *root = new Node(10);
    root->left = new Node(8); 
    root->right = new Node(20);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11); 
    root->right->right = new Node(30);
    root->right->right->left = new Node(25);

    //NO
    // Node *root = new Node(20);
    // root->left = new Node(8); 
    // root->right = new Node(40);
    // root->left->left = new Node(35);

    inorder(root);

    cout << endl;
    cout << endl << "Pair Sum Nodes Using Array" << endl;
    
    int sum = 33;

    if (checkPairSumWithArray(root, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << endl << "Pair Sum Nodes" << endl;

    set<int> s;

    if (checkPairSum(root, s, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}