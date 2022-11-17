#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v;
    int N, M;
    cin >> N >>  M;
    v.assign(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            int x;
            cin >> x;
            sum += x;
            v[i][j] = sum;
        }
    }

    for (int i = 0; i < M; i++ )
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;

        for (int j = x1; j <= x2; j++)
        {
            sum += v[j][y2] - v[j][y1 - 1];
        }
        cout << sum << "\n";
    }  

    return 0;
}