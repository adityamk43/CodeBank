/**
 * @file HuffmanCoding.cpp
 * @author ADITYA BHARDWAJ
 * @brief 
 *                          Huffman Coding
 * 
 * Huffman Coding is a lossless compression technique which means compressing anything wihtout losing its quality, and when we decode it we get the original thing back.
 * 
 * It is also a variable length encoding
 * 
 * It is a prefix free technique
 * 
 * It is a greedy approach
 * 
 * NOTE: 
 * Variable Length Encoding:
 * 1.) Greedy Approac/Idea here means that highest frequency characters has least variable length code
 * and lowest frequency character has high variable length code.
 * 2.) Prefix Requirement from Decompression: No code should be prefix of any other
 * 
 * The above all points ensures lossless compression.
 * 
 * Example:
 * "abaabaca......" -> 100 characters
 * 
 * Frequencies:
 * a -> 70
 * b -> 20
 * c -> 10
 * 
 * Prefix free code using Huffman Ideas:
 * a -> 70 -> 0 OR 1
 * b -> 20 -> 10 OR 01
 * c -> 10 -> 11 OR 00
 * 
 * So, total bits will be:
 * 70*1 + 20*2 + 10*2 = 70 + 40 + 20
 * = 130 bits
 * 
 * Huffman Coding Algorithm (High Level Idea):
 * 
 * 1.) Build a Binary Tree:
 *      a) Every input characters is a leaf
 *      b) Every left child edge is labelled as 0 and right edge as 1.
 *      c) Every root to leaf path represents Huffman Code of the leaf.
 * NOTE: The Huffman Tree that we build here is Full Binary Tree i.e., the parent node has either 2 children or 0 children, no node has 1 child in this tree!!
 * 
 * 2.) Traverse the Binary Tree and print the codes.
 * 
 * NOTE: The above Binary Tree/Huffman Tree ensures- prefix free, variable length for different characters and also the greedy approach
 * 
 * Example: 
 * I/P: 
 * ['a', 'd', 'b', 'e', 'f']
 * [10, 50, 20, 40, 80]
 * 
 * O/P:
 * f 0
 * d 10
 * a 1100
 * b 1101
 * e 111
 * 
 * @version 0.1
 * @date 2022-12-08 04:08 PM
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    char character;
    unsigned int freq;
    Node *left;
    Node * right;

    Node(char c, unsigned int f, Node *left=NULL, Node *right=NULL)
    {
        this->character = c;
        this->freq = f;
        this->left = left;
        this->right = right;
    }
};

struct compare
{
    bool operator() (Node *n1, Node *n2)
    {
        return n1->freq > n2->freq;
    }
};

void printCodes(Node *root, string str="")
{
    if (root == NULL)
        return;
    
    if (root->character != '$')
    {
        cout << root->character << ": " << str << endl;
    }

    printCodes(root->left, str+"0");
    printCodes(root->right, str+"1");
}

/**
 * @brief TIME COMPLEXITY: O(nlogn)
 *        AUXILIARY SPACE: ⊝(n)
 * 
 * For Priority queue Aux Space: ⊝(n)
 * For Building Huffman Tree Aux Space: ⊝(n)
 * For Traversing Huffman tree: O(n), it is depended upon height of the tree and here height is upperbounded by O(n)
 * 
 * @param characters 
 * @param freq 
 * @param n 
 */
void printHuffmanCodes(char characters[], int freq[], int n)
{
    //O(1)
    priority_queue<Node*, vector<Node*>, compare> h;

    //O(nlogn)
    for (int i=0; i<n; i++)
        h.push(new Node(characters[i], freq[i]));
    
    //O(nlogn) as this loop runs n-1 times and does extract min and push operations on heap which takes logn time
    while (h.size() > 1)
    {
        Node *left = h.top(); h.pop();
        Node *right = h.top(); h.pop();

        Node *node = new Node('$', left->freq+right->freq, left, right);

        h.push(node);
    }

    //⊝(n)
    //we have n leaf nodes and since, huffman trees are full binary trees and in binary trees, if there are n leafs then there are n-1 internal nodes.
    //Hence there will be total 2n-1 nodes in Huffman Tree, So overall T.C. for this function is ⊝(n)
    printCodes(h.top());
}

int main()
{
    //EXAMPLE 1
    // char characters[] = {'a', 'd', 'b', 'e', 'f'};
    // int freq[] = {10, 50, 20, 40, 80};

    //EXAMPLE 2
    char characters[] = { 'a', 'd', 'e', 'f' };
	int freq[] = { 30, 40, 80, 60 };

    int n = sizeof(characters)/sizeof(characters[0]);

    printHuffmanCodes(characters, freq, n);

    return 0;
}