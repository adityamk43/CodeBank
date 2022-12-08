/**
 * @file HuffmanDecoding.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * 
 * Huffman Decoding
EasyAccuracy: 69.25%Submissions: 7K+Points: 2
Given a encoded binary string and a Huffman MinHeap tree, your task is to complete the function decodeHuffmanData(), which decodes the binary encoded string and return the original string. 

Note: Each node of the min heap contains 2 data members, a character and an integer to denote its frequency. The character '$' is the special character used for internal nodes whose min heap node only need a integer field.


Example 1:

Input :
binaryString = 
0000000000001100101010101011111111010101010
Min Heap Tree =  
                $(20)
              /      \
            /          \
         $(8)            \
       /     \             \
    $(3)      \            $(12)
    /  \       \           /    \
B(1)    D(2)    E(5)    C(6)    A(6)

Output: AAAAAABCCCCCCDDEEEEE

Explanation:
The following chart can be made from the 
given min heap tree.
character    frequency    code
    A             6        00                 
    B             1        110
    C             6        01
    D             2        111    
    E             5        10

Example 2:

Input :
binaryString =
01110100011111000101101011101000111
Min Heap Tree =  
                         $(13)
                      /        \
                    /            \
                  /                \
               $(5)                  \
             /      \                  \
            /        \                   \
         $(3)         \                  $(8)
        /    \         \                /    \
     $(2)     \         \            $(4)     \
    /   \      \         \          /   \      \
f(1)    o(1)    r(1)    g(2)    k(2)    s(2)    e(4)

Output: geeksforgeeks

Explanation:
The following chart can be made from the 
given min heap tree.
character    frequency    code
    f             1        0000                 
    o             1        0001
    r             1        001
    g             2        01    
    k             2        100
    s             2        101
    e             4        11

Your Task:  
You dont need to read input or print anything. Complete the function decodeHuffmanData() which takes the root of the Huffman min heap tree and the encoded Binary String as input parameters and returns the decoded string.


Expected Time Complexity: O(N log N)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 10^3
 * 
 * @version 0.1
 * @date 2022-12-08 11:45 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
#define MAX_TREE_HT 256
using namespace std;

map<char, string> codes;
map<char, int> freq;
// MinHeap structure
struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode *root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void storeCodes(struct MinHeapNode *root, string str)
{
    if (root == NULL)
        return;
    if (root->data != '$')
        codes[root->data] = str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

// huffman Code function
void HuffmanCodes(int size)
{
    struct MinHeapNode *left, *right, *top;
    for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}

void calcFreq(string str, int n)
{
    for (int i = 0; i < str.size(); i++)
        freq[str[i]]++;
}

// complete this function
string decodeHuffmanData(struct MinHeapNode *root, string binaryString);

int main()
{
    int T;
    // taking testcases
    cin >> T;
    while (T--)
    {
        string str;
        // taking string
        cin >> str;
        string encodedString, decodedString;
        // function calls
        calcFreq(str, str.length());
        HuffmanCodes(str.length());

        // adding encoded string
        for (auto i : str)
            encodedString += codes[i];
        // cout<<encodedString<<endl;

        // decoding encoded string
        decodedString = decodeHuffmanData(minHeap.top(), encodedString);
        cout << decodedString << endl;
    }
    return 0;
}

// } Driver Code Ends

/*
Structure of the node of Huffman tree is as
struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;
};
*/

// Function to return the decoded string.
string decodeHuffmanData(struct MinHeapNode *root, string binaryString)
{
    // Code here
    MinHeapNode *curr = root;
    string res = "";

    for (int i = 0; i < binaryString.length(); i++)
    {
        if (binaryString[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (curr->left == NULL && curr->right == NULL)
        {
            res += curr->data;
            curr = root;
        }
    }

    return res;
}