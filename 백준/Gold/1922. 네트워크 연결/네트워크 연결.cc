#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 987654321;
int adj[1001][1001] = {};

int n, m;

int prim(int n, int adj[][1001])
{
    int distance[n+1] = {INF, };
    int vnear;
    int cost;
    for (int i = 2; i <= n; i++)
    {
        distance[i] = adj[1][i];
    }

    int cnt = n-1;
    while(cnt--)
    {
        int min = INF;
        for (int i = 2; i <= n; i++)
        {
            if (distance[i] >= 0 && distance[i] < min)
            {
                min = distance[i];
                vnear = i;
            }
        }

        cost += min;
        distance[vnear] = -1;
        for (int i = 2; i <= n; i++)
        {
            if (adj[i][vnear] < distance[i])
            {
                distance[i] = adj[i][vnear];
            }
        }
    }


    return cost;
}


int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        adj[s][e] = w;
        adj[e][s] = w;
    }
    
    for (int i = 1; i <= n; i++) adj[i][i] = 0;

    cout << prim(n, adj);



    return 0;
}