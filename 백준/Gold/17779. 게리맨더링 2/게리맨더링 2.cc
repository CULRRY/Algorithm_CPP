#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n;
vector<vector<int>> a;
int ans = 987654321;

//d1 < y
//d1 + d2 <= 

void Devide(int x, int y)
{
    for (int d1 = 1; d1 < n; d1++)
    {
        for (int d2 = 1; d2 < n; d2++)
        {

            if (x + d1 + d2 > n)
                continue;
            if (y - d1 < 1)
                continue;
            if (y + d2 > n)
                continue;
            
            vector<vector<int>> tmp(n+1, vector<int>(n+1, 0));


            for (int r = 1; r < x + d1; r++)
                for (int c = 1; c <= y; c++)
                    tmp[r][c] = 1;
            for (int r = 1; r <= x + d2; r++)
                for (int c = y + 1; c <= n; c++)
                    tmp[r][c] = 2;
            for (int r = x + d1; r <= n; r++)
                for (int c = 1; c < y - d1 + d2; c++)
                    tmp[r][c] = 3;
            for (int r = x + d2 + 1; r <= n; r++)
                for (int c = y - d1 + d2; c <= n; c++)
                    tmp[r][c] = 4;

            for (int d = 0; d <= d1; d++)
            {
                tmp[x + d][y - d] = 5;
                tmp[x + d2 + d][y + d2 - d] = 5;
            }

            for (int d = 0; d <= d2; d++)
            {
                tmp[x + d][y + d] = 5;
                tmp[x + d1 + d][y - d1 + d] = 5;
            }

            for (int r = x + 1; r < x + d1 + d2; r++)
            {
                bool flag = false;
                for (int c = 1; c <= n; c++)
                {
                    if (tmp[r][c] == 5)
                    {
                        if (flag == true)
                            break;

                        flag = true;
                    }
                    if (flag)
                    {
                        tmp[r][c] = 5;
                        continue;
                    }
                    

                }
            }

            int cnt[6] = {0, };

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    switch (tmp[i][j])
                    {
                    case 0:
                    case 5:
                        cnt[5] += a[i][j];
                        break;
                    case 1:
                        cnt[1] += a[i][j];
                        break;
                    case 2:
                        cnt[2] += a[i][j];
                        break;
                    case 3:
                        cnt[3] += a[i][j];
                        break;
                    case 4:
                        cnt[4] += a[i][j];
                        break;
                    default:
                        break;
                    }
                }
            }

            int Max = 0;
            int Min = 99877231;

            for (int i = 1; i <= 5; i++)
            {
                Max = std::max(Max, cnt[i]);
                Min = std::min(Min, cnt[i]);
            }

            ans = std::min(ans, Max - Min);
        }
    }
}


int main()
{
    FASTIO;

    cin >> n;
    a = vector<vector<int>>(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            Devide(i, j);
        }
    }

    cout << ans << endl;

    return 0;
}