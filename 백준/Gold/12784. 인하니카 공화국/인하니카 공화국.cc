#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl "\n"

using namespace std;
struct Edge
{
    int n, w;
};

struct Node
{
    int parent;
    int toParent;
    vector<int> childs;
};

void MakeTree(int current, int parent, vector<vector<Edge>>& adj, vector<Node>& tree)
{
    for (Edge& node : adj[current])
    {
        if (node.n != parent)
        {
            tree[current].childs.push_back(node.n);
            tree[node.n].parent = current;
            tree[node.n].toParent = node.w;
            MakeTree(node.n, current, adj, tree);
        }
    }
}

int Solve(vector<Node>& tree, int root)
{
    Node current = tree[root];
    if (current.childs.empty())
    {
        return current.toParent;
    }

    int sum = 0;

    for (int& n : current.childs)
    {
        sum += Solve(tree, n);
    }

    current.toParent = std::min(current.toParent, sum);
    return current.toParent;

}

int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<Edge>> adj(n + 1, vector<Edge>());
        vector<Node> tree(n + 1);

        for (int i = 0; i < m; i++)
        {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;

            adj[v1].push_back({v2, w});
            adj[v2].push_back({v1, w});
        }

        MakeTree(1, -1, adj, tree);
        tree[1].toParent = INT_MAX;
        int ans = Solve(tree, 1);
        if (ans == INT_MAX)
            cout << 0 << endl;
        else
            cout << ans << endl;

    }

    return 0;
}