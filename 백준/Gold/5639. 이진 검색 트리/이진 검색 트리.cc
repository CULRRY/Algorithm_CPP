#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* leftChild;
    Node* rightChild;
};


void insert(Node** root, int in)
{
    if (*root == nullptr)
    {
        *root = new Node{in, nullptr, nullptr};
        return;
    }

    if ((*root)->val > in)
    {
        insert(&(*root)->leftChild, in);
    }
    else
    {
        insert(&(*root)->rightChild, in);
    }
}

void postOrder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrder(root->leftChild);
    postOrder(root->rightChild);
    cout << root->val << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v;
    cin >> v;
    Node* root = new Node{v, nullptr, nullptr};

    while (cin >> v)
    {
        insert(&root, v);
    } 

    postOrder(root);

    return 0;
}