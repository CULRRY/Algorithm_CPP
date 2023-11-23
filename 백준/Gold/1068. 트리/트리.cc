#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;
int n;
vector<int> tree;
int ans = 0;
vector<bool> visited;

void dfs(int now)
{
    visited[now] = 0;
    if (tree[now] == -2)
        return;
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        if (tree[i] == now)
        {
            flag = true;
            dfs(i);
        }
    }

    if (flag == false)
    {
        ans++;
    }
}

void dfs2(int now)
{
    visited[now] = 0;
    tree[now] = -2;

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        if (tree[i] == now)
        {
            
            dfs2(i);
        }
    }

}
int main()
{
    FASTIO;

    cin >> n;
    int root = 0;
    tree = vector<int>(n,  0);
    visited = vector<bool>(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
        if (tree[i] == -1)
            root = i;
    }

    int k;
    cin >> k;
    tree[k] = -2;
    //dfs2(k);
    //visited = vector<bool>(n, 0);
    dfs(root);
    cout << ans << endl;
    return 0;
}