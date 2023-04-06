#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
struct Node
{
    int parent;
    vector<int> children;
};

vector<Node> tree;
vector<vector<int>> adj;
void MakeTree(int cur, int parent)
{
    for (int node : adj[cur])
    {
        if (node != parent)
        {
            tree[cur].children.push_back(node);
            tree[node].parent = cur;
            MakeTree(node, cur);
        }
    }
}

int LCA(int v1, int v2)
{
    int now = v1;
    int v1ToRoot = 0;
    while (tree[now].parent != 0)
    {
        v1ToRoot++;
        now = tree[now].parent;
    }

    now = v2;
    int v2ToRoot = 0;
    while (tree[now].parent != 0)
    {
        v2ToRoot++;
        now = tree[now].parent;
    }

    if (v1ToRoot > v2ToRoot)
    {
        int diff = v1ToRoot - v2ToRoot;
        while (diff--)
        {
            v1 = tree[v1].parent;
        }
    }
    else if (v1ToRoot < v2ToRoot)
    {
        int diff = v2ToRoot - v1ToRoot;
        while (diff--)
        {
            v2 = tree[v2].parent;
        }
    }

    while (v1 != v2)
    {
        v1 = tree[v1].parent;
        v2 = tree[v2].parent;
    }
    
    return v1;
}

int main()
{
    FASTIO;

    int n;
    cin >> n;

    tree = vector<Node>(n+1);
    adj = vector<vector<int>>(n+1, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    MakeTree(1, -1);

    int m;
    cin >> m;
    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2;

        cout << LCA(v1, v2) << endl;
    }
    

    return 0;
}