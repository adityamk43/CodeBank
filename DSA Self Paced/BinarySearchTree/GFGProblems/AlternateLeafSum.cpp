#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
class MyBST
{
public:
    Node *root;
    bool alternateLeaf;

    MyBST()
    {
        this->root = NULL;
        this->alternateLeaf = false;
    }

    void addNode(int data)
    {
        Node *node = new Node(data);
        if (this->root == NULL)
        {
            this->root = node;
        }
        else
        {
            Node *find = this->root;
            while (find != NULL)
            {
                if (find->data >= data)
                {
                    if (find->left == NULL)
                    {
                        find->left = node;
                        return;
                    }
                    else
                    {
                        find = find->left;
                    }
                }
                else
                {
                    if (find->right == NULL)
                    {
                        find->right = node;
                        return;
                    }
                    else
                    {
                        find = find->right;
                    }
                }
            }
        }
    }
    int leafSum(Node *node)
    {
        if (node != NULL)
        {
            if (node->left == NULL && node->right == NULL)
            {

                this->alternateLeaf = !this->alternateLeaf;

                if (this->alternateLeaf)
                {
                    return node->data;
                }
            }
            else
            {
                return this->leafSum(node->left) + this->leafSum(node->right);
            }
        }

        return 0;
    }
    int alternateLeafSum()
    {
        this->alternateLeaf = false;
        return this->leafSum(this->root);
    }
};

int main()
{
    // code
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        MyBST *bst = new MyBST();

        for (int i = 0; i < n; i++)
            bst->addNode(arr[i]);

        cout << bst->alternateLeafSum() << endl;
    }

    return 0;
}
