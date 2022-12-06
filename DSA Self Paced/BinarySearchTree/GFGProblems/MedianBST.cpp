#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        root = newNode(data);
    
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void inOrderBST(Node *root, vector<Node *> &v)
{
    if (root == NULL)
        return;

    inOrderBST(root->left, v);
    v.push_back(root);
    inOrderBST(root->right, v);
}

int median(Node *root, int k)
{
    if (root == NULL)
        return -1;

    vector<Node *> v;

    inOrderBST(root, v);

    Node *subtreeRoot = v[k - 1];

    v.clear();

    inOrderBST(subtreeRoot, v);

    int len = v.size();

    if (len % 2 != 0)
    {
        return v[len / 2]->data;
    }
    else
    {
        return (v[len / 2]->data + v[(len / 2) - 1]->data) / 2;
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        Node *root = NULL;

        int n, k;
        cin >> n >> k;

        for (int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            root=insert(root, x);
        }

        cout << median(root, k) << endl;
    }

    return 0;
}