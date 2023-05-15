#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, m, h;
vector<vector<int>> radder;
vector<vector<int>> tmp;
int ans = 4;

bool move_down(int i)
{
    int stair = 0;
    int vert = i;

    while (stair <= h)
    {
        if (radder[stair][vert] == 0)
            stair++;
        else
        {
            vert = radder[stair][vert];
            stair++;
        }
    }

    if (i == vert)
        return true;
    else
        return false;
}

bool test()
{
    for (int i = 1; i <= n; i++)
    {
        if (move_down(i) == false)
            return false;
    }

    return true;
}

void bt(int depth, int y)
{
    if (depth >= ans)
        return;

    if (test())
    {
        ans = std::min(ans, depth);
    }

    if (depth == 3)
        return;

    for (int j = y; j <= h; j++)
    {
        for (int i = 1; i < n; i++)
        {
            if (radder[j][i] != 0)
                continue;
            if (radder[j][i + 1] != 0)
                continue;

            radder[j][i] = i + 1;
            radder[j][i + 1] = i;

            bt(depth + 1, j);
            radder[j][i] = 0;
            radder[j][i + 1] = 0;
        }
    }
}

int main()
{
    FASTIO;

    cin >> n >> m >> h;

    radder = vector<vector<int>>(h + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        radder[a][b] = b + 1;
        radder[a][b + 1] = b;
    }

    bt(0, 1);

    if (ans >= 4)
        ans = -1;

    cout << ans << endl;

    return 0;
}