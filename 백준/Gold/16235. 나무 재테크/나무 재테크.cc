#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, m ,k;
vector<vector<int>> a;
vector<vector<vector<int>>> t;
vector<vector<int>> p;
vector<vector<int>> r;

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};


int main()
{
    FASTIO;

    cin >> n >> m >> k;

    a = vector<vector<int>>(n+1, vector<int>(n + 1, 0));
    p = vector<vector<int>>(n + 1, vector<int>(n + 1, 5));
    t = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        t[x][y].push_back(z);
    }


    while (k--)
    {
        r = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (t[i][j].empty())
                    continue;

                sort(t[i][j].begin(), t[i][j].end());
            }
        }
        // SPRING & SUMMER

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (t[i][j].empty())
                    continue;
                
                vector<int> tmp;
                for (auto tree : t[i][j])
                {
                    if (tree > p[i][j])
                    {
                        r[i][j] += static_cast<int>(tree / 2);
                        continue;
                    }
                    
                    tmp.push_back(tree + 1);
                    p[i][j] -= tree;
                }
                t[i][j] = tmp;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                p[i][j] += r[i][j];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int cnt = 0;
                for (auto tree : t[i][j])
                {
                    if (tree % 5 == 0)
                        cnt++;
                }

                if (cnt == 0)
                    continue;
                
                for (int d = 0; d <= 8; d++)
                {
                    for (int l = 0; l < cnt; l++)
                    {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (nx <= 0 || nx > n || ny <= 0 || ny > n)
                            break;

                        t[nx][ny].push_back(1);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                p[i][j] += a[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans += t[i][j].size();
        }
    }

    cout << ans << endl;

    return 0;
}