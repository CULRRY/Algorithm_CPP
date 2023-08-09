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

    parent[q] = parent[p];
}

bool IsEqual(int p, int q)
{
    return Find(p) == Find(q);
}

int main()
{
    FASTIO;

    int n;
    cin >> n;

    parent = vector<int>(n+1, 0);
    std::iota(parent.begin(), parent.end(), 0);


    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        Union(v1, v2);
    }

    for (int i = 2; i <= n; i++)
    {
        if (!IsEqual(1, i))
        {
            cout << 1 << " " << i;
            break;
        }
    }


    return 0;
}