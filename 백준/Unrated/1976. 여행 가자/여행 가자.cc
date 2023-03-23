#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
vector<int> parent;

int Find(int p)
{
    if (parent[p] == p)
        return p;
    
    return parent[p] = Find(parent[p]);
}

void Union(int p, int q)
{
    p = Find(p);
    q = Find(q);

    parent[p] = q;
}

bool IsEqual(int p, int q)
{
    return Find(p) == Find(q);
}

int main()
{
    FASTIO;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    parent = vector<int>(n+1, 0);
    std::iota(parent.begin(), parent.end(), 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int d;
            cin >> d;
            if (d == 1)
            {
                Union(i, j);
            }
        }
    }

    vector<int> route(m);
    for (int& i : route)
        cin >> i;
    
    for (int i : route)
    {
        if (IsEqual(route[0], i) == false)
            {
                cout << "NO";
                return 0 ;
            }
    }

    cout << "YES";

    

    return 0;
}