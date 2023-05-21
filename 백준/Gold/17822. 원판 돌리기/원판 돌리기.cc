#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, m, t;
vector<vector<int>> circles;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    FASTIO;

    cin >> n >> m >> t;
    circles = vector<vector<int>>(n, vector<int>(m, 0));
    int sum = 0;
    for (auto& v : circles)
    {
        for (auto& i : v)
        {
            cin >> i; 
            sum += i;
        }
    }

    while (t--)
    {
        int x, d, k;
        cin >> x >> d >> k;
        int inc = x;
        while (x <= n)
        {
            vector<int> tmp = vector<int>(m, 0);

            for (int i = 0; i < m; i++)
            {
                if (d == 0)
                {
                    tmp[(i + k) % m] = circles[x-1][i];
                }
                else
                {
                    int gap;
                    while (m < k)
                    {
                        k -= m;
                    }
                    
                    if (i >= k)
                        gap = i - k;
                    else
                        gap = m + (i - k);
                    
                    tmp[gap] = circles[x-1][i];
                }
            }

            circles[x-1] = tmp;

            x += inc;
        }

        vector<vector<bool>> deleteList(n, vector<bool>(m, false));
        bool flag = true;
        double mean = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (circles[i][j] == 0)
                    continue;

                mean += circles[i][j];
                cnt++;
                for (int d = 0; d < 4; d++)
                {
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if (nx < 0)
                        nx = m - 1;
                    else if (nx >= m)
                        nx = 0;
                    
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;

                    if (circles[i][j] == circles[ny][nx])
                    {
                        flag = false;
                        deleteList[ny][nx] = true;
                    }
                }
            }
        }

        if (cnt == 0)
            break;

        mean = mean / (double)cnt;
        if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (circles[i][j] == 0)
                        continue;

                    if (circles[i][j] < mean)
                    {
                        circles[i][j]++;
                        sum++;
                    }
                    else if (circles[i][j] > mean)
                    {
                        circles[i][j]--;
                        sum--;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (deleteList[i][j])
                    {
                        sum -= circles[i][j];
                        circles[i][j] = 0;
                    }
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}