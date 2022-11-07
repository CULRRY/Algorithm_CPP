#include <bits/stdc++.h>

using namespace std;
struct point
{
    int y, x;
};
int N;
multiset<int> s;
vector<point> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int c = 1;

void dfs(vector<vector<char>> &v, point p)
{
    v[p.y][p.x] = 0;
    for (int i = 0; i < direction.size(); i++)
    {
        point next = {p.y + direction[i].y, p.x + direction[i].x};
        if (next.y >= 0 && next.x >= 0 && next.y < N && next.x < N && v[next.y][next.x] == '1')
        {
            v[next.y][next.x] = '0';
            c++;
            dfs(v, next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<char>> v;
    cin >> N;
    v.assign(N, vector<char>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (v[i][j] == '1')
            {
                dfs(v, point{i, j});
                s.insert(c);
                c = 1;
            }
        }
    }

    cout << s.size() << "\n";
    for (int i : s)
    {
        cout << i << "\n";
    }

    return 0;
}