#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

vector<int> parent;
vector<int> rank;

int Find(int p)
{
    if (p == parent[p])
        return p;

    return parent[p] = Find(parent[p]);
}

void Union(int p, int q)
{
    p = Find(p);
    q = Find(q);

    if (p == q) return;

    if (::rank[p] < ::rank[q])
    {
        parent[p] = q; 
    }
    else
    {
        parent[q] = p;
    }

    if (::rank[p] == ::rank[q]) ::rank[p]++;


}

bool Equal(int p,  int q)
{
    return Find(p) == Find(q);
}

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    parent.assign(n, 0);
    ::rank.assign(n, 1);
    std::iota(parent.begin(), parent.end(), 0);

    for (int c = 1; c <= m; c++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        if(Equal(v1, v2))
        {
            cout << c << "\n";
            return 0;
        }

        Union(v1, v2);
    }

    cout << 0 << "\n";



    return 0;
}