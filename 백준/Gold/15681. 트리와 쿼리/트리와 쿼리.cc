#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl "\n"

using namespace std;


vector<vector<int>> connect;

struct Node
{
    int parent;
    vector<int> childs;
};

vector<Node> tree;
vector<int> sz;
void MakeTree(int curNode, int parent)
{
    for (int node : connect[curNode])
    {
        if (node != parent)
        {
            tree[curNode].childs.push_back(node);
            tree[node].parent = curNode;
            MakeTree(node, curNode);
        }
    }
}

void CountSubTreeNodes(int curNode)
{
    sz[curNode] = 1;
    for (int node : tree[curNode].childs)
    {
        CountSubTreeNodes(node);
        sz[curNode] += sz[node];
    }
}

int main()
{
    FASTIO;

    int n, r, q;
    cin >> n >> r >> q;

    connect = vector<vector<int>>(n+1, vector<int>());
    tree.resize(n+1);
    sz.resize(n+1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }

    MakeTree(r, -1);
    CountSubTreeNodes(r);
    for (int i = 0; i < q; i++)
    {
        int query;
        cin >> query;

        cout << sz[query] << endl;

    }

    return 0;
}