#include <bits/stdc++.h>
using namespace std;


vector<int> count(3, 0);

void sumOfPaper(vector<vector<int>>& v, int n, int start_x, int start_y)
{
    int norm = v[start_y][start_x];
    bool isSame = true;
    for (int i = start_y; i < start_y + n; i++)
    {
        for (int j = start_x; j < start_x + n; j++)
        {
            if (v[i][j] != norm)
            {
                isSame = false;
                i = start_y + n;
                break;
            }

        }
    }
    if (isSame)
        ::count[norm+1]++;
    else
    {
        for (int i = 0; i < n; i += n/3)
        {
            for (int j = 0; j < n; j += n/3)
            {
                sumOfPaper(v, n / 3, start_x + j, start_y + i);
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
    v.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    sumOfPaper(v, N, 0, 0);

    for (int i = 0; i < ::count.size(); i++)
    {
        cout << ::count[i] << "\n";
    }

    return 0;
}