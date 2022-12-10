#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int v1, v2, weight;
};

int disjoint[10000];

void Init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        disjoint[i] = i;
    }
}

int Find(int p)
{
    if (disjoint[p] == p)
        return p;

    return disjoint[p] = Find(disjoint[p]);
}

void Union(int p, int q)
{
    disjoint[Find(p)] = Find(q);
}

bool Equal(int p, int q)
{
    return Find(p) == Find(q);
}

int Kruskal(const Edge* edges, int n, int e)
{
    Init(n);
    int cnt = n-1;
    int weights = 0;
    int idx = 0;
    while (cnt)
    {
        Edge e = edges[idx];
        int p = e.v1;
        int q = e.v2;
        while(!Equal(p, q))
        {
            Union(p, q);
            weights += e.weight;
            cnt--;
        }
        idx++;
    }

    return weights;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    Edge edges[100001];
    for (int i = 0; i < e; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        edges[i] = {v1, v2, w};
    }

    sort(edges, edges + e, [](const Edge& e1, const Edge& e2) -> bool {return e1.weight < e2.weight;});

    cout << Kruskal(edges, v, e) << "\n";




    return 0;
}