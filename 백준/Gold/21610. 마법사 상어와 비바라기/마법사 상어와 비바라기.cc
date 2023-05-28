#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> a;
vector<vector<bool>> cloud;

int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

void skill(int d, int s)
{
    vector<vector<bool>> tmp(n + 1, vector<bool>(n+1, false));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cloud[i][j] == true)
            {
                while (s >= n)
                {
                    s -= n;
                }
                

                int dsy = s * dy[d];
                int dsx = s * dx[d];
                
                int ny = i + dsy;
                int nx = j + dsx;

                if (ny > n)
                    ny = ny - n;
                else if (ny <= 0)
                    ny = n + ny;
                
                if (nx > n)
                    nx = nx - n;
                else if (nx <= 0)
                    nx = n + nx;

                tmp[ny][nx] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (tmp[i][j] == true)
                a[i][j]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (tmp[i][j] == true)
            {
                int cnt = 0;
                for (int dy = -1; dy <= 1; dy += 2)
                {
                    for (int dx = -1; dx <= 1; dx += 2)
                    {
                        int ny = i + dy;
                        int nx = j + dx;
                        if (ny <= 0 || ny > n || nx <= 0 || nx > n)
                            continue;
                        if (a[ny][nx] != 0)
                            cnt++;
                    }
                }

                a[i][j] += cnt;
            }
        }
    }


    cloud = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] < 2)
                continue;
            if (tmp[i][j] == true)
                continue;
            
            cloud[i][j] = true;
            a[i][j] -= 2;
        }
    }
}  

int main()
{
    FASTIO;

    cin >> n >> m;
    a = vector<vector<int>>(n+1, vector<int>(n+1, 0));
    cloud = vector<vector<bool>>(n+1, vector<bool>(n+1, false));

    cloud[n][1] = true;
    cloud[n][2] = true;
    cloud[n-1][1] = true;
    cloud[n-1][2] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    while (m--)
    {
        int d, s;
        cin >> d >> s;
        
        skill(d, s);
    }

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum += a[i][j];
        }
    }
    
    cout << sum << endl;

    return 0;
}