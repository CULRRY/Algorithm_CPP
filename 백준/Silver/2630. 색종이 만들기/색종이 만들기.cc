#include <bits/stdc++.h>
using namespace std;
int num[2] = {
    0,
};

void createPaper(vector<vector<int>> &v, int n, int y, int x)
{
    int color = v[y][x];
    if (n == 1)
    {
        num[color]++;
        return;
    }

    bool isSame = true;
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (v[i][j] != color)
            {
                isSame = false;
                i = y + n;
                break;
            }
        }
    }

    if (isSame)
        num[color]++;
    else
    {
        for (int i = 0; i < n; i += n / 2)
        {
            for (int j = 0; j < n; j += n / 2)
            {
                createPaper(v, n / 2, y + i, x + j);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> v;
    v.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    createPaper(v, N, 0, 0);
    cout << num[0] << "\n" << num[1] << "\n";

    return 0;
}