#include <bits/stdc++.h>
using namespace std;
int N;

struct Point
{
    int y, x;
};

vector<Point> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(vector<vector<char>>& v, vector<vector<bool>>& visited, const Point& p)
{
    char norm = v[p.y][p.x];
    if (v[p.y][p.x] == 'G')
        v[p.y][p.x] = 'R';

    visited[p.y][p.x] = true;

    for (int i = 0; i < direction.size(); i++)
    {
        Point next = {p.y + direction[i].y, p.x + direction[i].x};

        if (next.x >= 0 && next.x < N && next.y >= 0 && next.y < N && !visited[next.y][next.x] && v[next.y][next.x] == norm)
        {
            visited[next.y][next.x] = true;  
            dfs(v, visited, next);
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<vector<char>> v;
    v.assign(N, vector<char>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    int count1 = 0;
    vector<vector<bool>> visited1;
    visited1.assign(N, vector<bool>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited1[i][j])
            {
                dfs(v, visited1, Point{i, j});
                count1++;
            }
        }
    }

    int count2 = 0;
    vector<vector<bool>> visited2;
    visited2.assign(N, vector<bool>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited2[i][j])
            {
                dfs(v, visited2, Point{i, j});
                count2++;
            }
        }
    }

    cout << count1 << " " << count2 << "\n";

    return 0;
}