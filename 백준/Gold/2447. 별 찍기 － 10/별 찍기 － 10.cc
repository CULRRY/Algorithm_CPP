#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int n;
vector<vector<char>> ans;

void rec(int k, int y, int x)
{
    if (k == 1)
        ans[y][x] = '*';
    else
    {
        for (int ny = y; ny < y + k; ny += k/3)
        {
            for (int nx = x; nx < x + k; nx += k/3)
            {
                if (ny == y + k/3 && nx == x + k/3)
                    continue;
                
                rec(k/3, ny, nx);
            }
        }
    }
}

int main()
{
    FASTIO;
    cin >> n;
    ans = vector<vector<char>>(n, vector<char>(n, ' '));

    rec(n, 0, 0);
    for (auto v : ans)
    {
        for (auto i : v)
            cout << i;
        cout << endl;
    }
    return 0;
}