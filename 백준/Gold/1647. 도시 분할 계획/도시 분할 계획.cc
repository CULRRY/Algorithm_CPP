#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int v1, v2, w;
};

int disjoint[100001];
int Find(int i)
{
    if (disjoint[i] == i)
        return i;
    
    return disjoint[i] = Find(disjoint[i]);
}

void Union(int p, int q)
{
    disjoint[Find(p)] = Find(q);
}

bool Equal(int p, int q)
{
    return Find(p) == Find(q);
}

int Kruskal(int n, const Edge* edges)
{
    for (int i = 1; i <= n; i++)
    {
        disjoint[i] = i;
    }

    int cnt = n-2;
    int i = 0;
    int weights = 0;
    while (cnt)
    {
        Edge e = edges[i];
        int p = e.v1;
        int q = e.v2;
        if (!Equal(p, q))
        {
            Union(p, q);
            weights += e.w;
            cnt--;
        }
        i++;
    }

    return weights;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    Edge edges[m];

    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        edges[i] = {v1, v2, w};
    }

    sort(edges, edges + m, [](const Edge& e1, const Edge& e2)->bool { return e1.w < e2.w; });
    cout << Kruskal(n, edges);


    return 0;
}