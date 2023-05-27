#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, q;
vector<vector<int>> a;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int power(int n)
{
    return std::pow(2, n);
}

void rotate(int l, int sy, int sx)
{

    vector<vector<int>> tmp(l, vector<int>(l, 0));
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            tmp[i][j] = a[sy + l - j - 1][sx + i];
        }
    }

    for (int i = sy; i < sy + l; i++)
    {
        for (int j = sx; j < sx + l; j++)
        {
            a[i][j] = tmp[i - sy][j - sx];
        }
    }
}

void FireStorm(int l)
{
    for (int i = 0; i < n; i += l)
    {
        for (int j = 0; j < n; j += l)
        {
            rotate(l, i, j);
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> tmp = a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
                continue;
            int cnt = 0;
            for (int d = 0; d < 4; d++)
            {
                int nx = j + dx[d];
                int ny = i + dy[d];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                
                if (a[ny][nx] != 0)
                    cnt++;

            }

            if (cnt < 3)
                tmp[i][j]--;
        }
    }

    a = tmp;
}

int sum = 0;
int big = 0;
int idx = 0;
vector<int> sz;
vector<vector<bool>> visited;
void dfs(int y, int x, int idx)
{
    visited[y][x] = true;
    sz[idx]++;
    sum += a[y][x];
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (a[ny][nx] == 0)
            continue;
        if (visited[ny][nx] == true)
            continue;

        dfs(ny, nx, idx);
    }
}

int main()
{
    FASTIO;

    cin >> n >> q;
    n = power(n);
    a = vector<vector<int>>(n, vector<int>(n, 0));
    visited = vector<vector<bool>>(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    while (q--)
    {
        int l;
        cin >> l;
        l = power(l);
        FireStorm(l);
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == false)
            {
                if (a[i][j] == 0)
                    continue;

                sz.push_back(0);
                dfs(i, j, idx);
                idx++;
            }
        }
    }

    cout << sum << endl;
    if (sz.empty())
        cout << 0 << endl;
    else
        cout << *max_element(sz.begin(), sz.end());

    return 0;
}