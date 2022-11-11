#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> discoverd;
int bfs(vector<vector<int>> &graph)
{
    queue<int> q;
    q.push(1);
 
    int count = 0;
    while(!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            int now = q.front();
            q.pop();
            if (now == 100)
            {
                return count;
            }
            for (int j = 1; j <= 100; j++)
            {
                if (!discoverd[now][j] && graph[now][j] == 1)
                {
                    q.push(j);
                    discoverd[now][j] = true;
                }

            }
        }
        count++;
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph;
    graph.assign(101, vector<int>(101, 0));
    discoverd.assign(101, vector<bool>(101, 0));

    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i + j <= 100)
            {
                graph[i][i + j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;

        for (int j = 1; j <= 6; j++)
        {
            if (s + j <= 100)
            {
                graph[s][s + j] = 0;
            }
        }

        for (int j = 1; j <= 6; j++)
        {
            if (s - j > 0)
            {
                graph[s-j][s] = 0;
                graph[s - j][e] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;

        for (int j = 1; j <= 6; j++)
        {
            if (s + j <= 100)
            {
                graph[s][s + j] = 0;
            }
        }

        for (int j = 1; j <= 6; j++)
        {
            if (s - j > 0)
            {
                graph[s-j][s] = 0;
                graph[s - j][e] = 1;
            }
        }
    }

    cout << bfs(graph) << "\n";

    return 0;
}