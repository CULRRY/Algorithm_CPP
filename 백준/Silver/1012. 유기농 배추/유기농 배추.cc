#include <bits/stdc++.h>
using namespace std;

struct direction
{
    int x, y;
};

vector<direction> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void DFS(vector<vector<int>> &v, int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + d[i].x;
        int next_y = y + d[i].y;

        if (next_x >= 0 && next_x < v[0].size() && next_y >= 0 && next_y < v.size() && v[next_y][next_x] == 1)
        {
            v[next_y][next_x] = 0;
            DFS(v, next_x, next_y);
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int M, N, K;
        cin >> M >> N >> K;
        vector<vector<int>> v;
        v.assign(N, vector<int>(M, 0));
        while (K--)
        {
            int x, y;
            cin >> x >> y;
            v[y][x] = 1;
        }
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (v[i][j] == 1)
                {
                    DFS(v, j, i);
                    count++;
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}