#include <bits/stdc++.h>
using namespace std;

void QuadTree(vector<vector<char>>& v, int y, int x, int n)
{
    char norm = v[y][x];
    bool isSame = true;
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (v[i][j] != norm)
            {
                isSame = false;
                i = y + n;
                break;
            }
        }
    }

    if (isSame == true)
        cout << norm;
    else
    {
        cout << '(';
        QuadTree(v, y, x, n / 2);
        QuadTree(v, y, x + n / 2, n / 2);
        QuadTree(v, y + n / 2, x, n / 2);
        QuadTree(v, y + n / 2, x + n / 2, n / 2);
        cout << ')';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<char>> v;
    v.assign(N, vector<char>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    QuadTree(v, 0, 0, N);

    

    return 0;
}