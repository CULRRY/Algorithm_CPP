#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph;
    graph.assign(N + 1, vector<int>(N + 1, 5000));
    for (int i = 1; i <= N; i++)
    {
        graph[i][i] = 0;
    }

    while (M--)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int min = 999999;
    int minIdx = 0;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        int idx = i;
        for (int j = 1; j <= N; j++)
        {
            sum += graph[i][j];
        }

        if (min > sum)
        {
            min = sum;
            minIdx = idx;
        }
    }

    cout << minIdx << "\n";

    return 0;
}