#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

void CountingSort(vector<int>& v, int n, int m)
{
    vector<int> tmp(n+1, 0);
    for (int i = 0; i < m; i++)
    {
        tmp[v[i]] = 1;
    }

    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tmp[i] == 1)
        {
            v[idx] = i;
            idx++;
        }
    }
}

vector<int> parent;

int Find(int p)
{
    if (p == parent[p])
        return p;
    
    return parent[p] = Find(parent[p]);
}

void Union(int p, int q)
{
    parent[Find(p)] = Find(q);
}


int main()
{
    FASTIO;

    int n, m ,k;
    cin >> n >> m >> k;
    vector<int> minsu;
    parent = vector<int>();
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        minsu.push_back(a);
        parent.push_back(i);
    }

    CountingSort(minsu, n, m);

    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;

        int idx = upper_bound(minsu.begin(), minsu.end(), c) - minsu.begin();

        if (idx >= m)
            idx = 0;

        int f = Find(idx);
        cout << minsu[f] << "\n";

        if (f == m - 1)
        {
            Union(f, 0);
            continue;
        }
        Union(f, f + 1);
    }

    return 0;
}