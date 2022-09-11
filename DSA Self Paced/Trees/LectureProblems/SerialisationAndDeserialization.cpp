/**
 * @file SerialisationAndDeserialization.cpp
 * @author ADITYA BHARDWAJ
 * @brief serialisation means converting the tree to array or string
 *        deserialisation means converting the array/string to tree
 * @version 0.1
 * @date 2022-09-11 10:44 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    
    int key;
    Node* left;
    Node* right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};


/**
 * @brief There is many important applications of serialisation and deserialisation.
 * 
 * Consider a Situation where you have a tree data structure and this tree might represent anything or we can say any hierarchical information in RAM. Now, if you wish to send the tree data structure that you have in RAM accross the network to some other device. See, if you are working within a same process or program, you can pass root of this tree, pointer or reference to this and the other function can take the pointer and work on it. But if you wish to send this accross the network, then you need to serialise this in the form of a string, so that the string can be send accross the network.
 * 
 * Another application of serialisation and deserialisation is if you are setting a binary tree practice problems like in practice.geeksforgeeks.com, you need to write test cases and for writing those test cases, you need to generate strings, so that the people whose programs you are going to test against a problem or predefined test cases, those programs are going to read these strings and then construct the tree. So, generation of test cases is called serialisation and when a user program reads those test cases to construct a tree that is called deserialisation.
 * 
 * How To Define:
 *      (For simplicity, here we are using array and not a string to avoid string operations)
 *      In C++:
 *          void serialise(Node *root, vector<int> &arr){...}
 *          Node *deSerialise(vector<int> &arr){...}
 *      In Java:
 *          void serialise(Node root, ArrayList<Integer> arr){...}
 *          Node deSerialise(ArrayList<Integer> arr){...}
 * 
 */

/*
    TIME COMPLEXITY: ⊝(n)
    AUXILIARY SPACE: ⊖(n)
        ex:   10
            /   \
*         20     N
*        /  \
        N    N

        For 2 Nodes in a binary tree, there will be 2 + 3 nulls value in an array

        so, for n nodes there will be n+1 nulls in an array

        Therefore, total size of the array will be n+(n+1) = 2n + 1 = ⊝(n) extra space
*/

//serialization using preorder traversal
const int EMPTY = -1;
void serialize(Node *root, vector<int> &arr)
{
    if (root==NULL)
    {
        arr.push_back(EMPTY);
        return;
    }
    
    arr.push_back(root->key);

    serialize(root->left, arr);
    serialize(root->right, arr);
}

/*
    TIME COMPLEXITY: ⊝(n)
    AUXILIARY SPACE: ⊖(h)
*/

//preoder serialization to deserialization
int index = 0;
Node *deserialize(vector<int> &arr)
{
    if (index == arr.size())
        return NULL;
    
    int val = arr[index];
    index++;

    if (val == EMPTY)
        return NULL;

    Node* root = new Node(val);

    root->left = deserialize(arr);
    root->right = deserialize(arr);

    return root;
}

int main(){
    
    /**
     * @brief 
     *               10
     *            /     \
     *          20      30
     *         /  \     / \
     *       40   50   60  N
     *      /  \ /  \ / \
     *     N   N N  N N  N
     * 
     *      N(NULL) is stored as -1 in array
     */
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    vector<int> arr;

    serialize(root, arr);

    cout << "After Serialisation" << endl;
    for (int v: arr)
        cout << v << " ";

    cout << endl;

    // vector<int> ds{10, 20, 40, -1, -1, 50, -1, -1, 30, 60};
    // Node *cTree = deserialize(ds);
    Node *cTree = deserialize(arr);
    cout << "After Deserialisation" << endl;

    vector<int> newArr;
    serialize(cTree, newArr);

    for (int v: newArr)
        cout << v << " ";

    return 0;
}
