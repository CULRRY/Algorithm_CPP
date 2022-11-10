#include <bits/stdc++.h>
using namespace std;

int M, N, H;
struct Point3D
{
    int x, y, z;
};

const vector<Point3D> direction = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
queue<Point3D> q;

int bfs(vector<vector<vector<int>>> &v)
{
    int count = 0;
    while (!q.empty())
    {
        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            Point3D now = q.front();
            q.pop();
            for (int j = 0; j < direction.size(); j++)
            {
                Point3D next = {now.x + direction[j].x, now.y + direction[j].y, now.z + direction[j].z};

                if (next.x >= 0 && next.x < M && next.y >= 0 && next.y < N && next.z >= 0 && next.z < H && v[next.z][next.y][next.x] == 0)
                {
                    q.push(next);
                    v[next.z][next.y][next.x] = 1;
                }
            }
        }
        count++;
    }

    return count - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N >> H;

    vector<vector<vector<int>>> v;
    v.assign(H, vector<vector<int>>());
    for (int i = 0; i < H; i++)
    {
        v[i].assign(N, vector<int>(M, 0));
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> v[i][j][k];
            }
        }
    }

    int max = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (v[i][j][k] == 1)
                {
                    q.push(Point3D{k, j, i});
                }
            }
        }
    }

    max = bfs(v);


    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (v[i][j][k] == 0)
                {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << max << "\n";

    return 0;
}