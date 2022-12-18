#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> inOrder;
vector<int> postOrder;
struct Node
{
    int n, left, right;
};
vector<Node> tree;

void GenerateTree(int root, int num, int startIn, int startPost)
{

    if (root == -1)
        return;
    int cnt = 0;
    for (int i = startIn; i <= startIn + num; i++)
    {
        if (inOrder[i] == root)
            break;
        cnt++;
    }

    if (cnt != num - 1)
        tree[root].right = postOrder[startPost + num - 2];
    
    if (cnt != 0)
        tree[root].left = postOrder[startPost + cnt - 1];

    GenerateTree(tree[root].right, num - cnt - 1, startIn + cnt + 1, startPost + cnt);
    GenerateTree(tree[root].left, cnt, startIn, startPost);
}

void preOrder(int root)
{
    if (root == -1)
        return;

    cout << tree[root].n << " ";
    preOrder(tree[root].left);
    preOrder(tree[root].right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    inOrder.assign(n+1, -1);
    postOrder.assign(n+1, -1);
    tree.assign(n+1, {-1, -1, -1});

    for (int i = 1; i <= n; i++)
    {
        cin >> inOrder[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> postOrder[i];
    }


    for (int i = 1; i <= n; i++)
    {
        tree[i] = {i, -1, -1};
    }

    GenerateTree(postOrder.back(), n, 1, 1);

    preOrder(postOrder.back());
    return 0;
}