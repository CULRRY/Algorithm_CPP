#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

vector<vector<int>> mat;

int dq(int n, int x, int y)
{
    if (n == 1)
        return mat[y][x];
        
    vector<int> v;
    v.push_back(dq(n/2, x, y));
    v.push_back(dq(n/2, x + n/2, y));
    v.push_back(dq(n/2, x, y + n / 2));
    v.push_back(dq(n/2, x + n/2, y + n / 2));

    sort(v.begin(), v.end());

    return v[2];
}

int main()
{
    FASTIO;

    int n;
    cin >> n;
    mat = vector<vector<int>>(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << dq(n, 0, 0);

    

    return 0;
}