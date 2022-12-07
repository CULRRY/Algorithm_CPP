#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int w;
    int v1, v2;
};
int n, m;
int disjoint[1001] = {0, };

int Find(int i)
{
    while (disjoint[i] != i)
        i = disjoint[i];
    
    return i;
}
void Union(int p, int q)
{  
    disjoint[Find(p)] = Find(q);
}

bool Equal(int p, int q)
{
    return Find(p) == Find(q);
}

int Kruskal(int n, int m, Edge* edges)
{
    int size = 0;
    int cost = 0;
    sort(edges, edges + m, [](const Edge& e1, const Edge& e2){return e1.w < e2.w;});
    for (int i = 1; i <= n; i++)
    {
        disjoint[i] = i;
    }

    int i = 0;
    while (size < n  - 1)
    {
        Edge e = edges[i];
        int p = e.v1;
        int q = e.v2;
        if (!Equal(p, q))
        {
            Union(p, q);
            cost += e.w;
            size++;
        }
        i++;
    }

    return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    Edge edges[100001];

    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        edges[i] = {w, v1, v2}; 
    }

    cout << Kruskal(n, m, edges);

    return 0;
}