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
        for (int j = 1; j <= N; j++)
        {
            int x;
            cin >> x;
            v[i][j] = v[i][j-1] + v[i-1][j] + x - v[i-1][j-1];
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        

        cout << v[x2][y2] - v[x1-1][y2] - v[x2][y1-1] + v[x1-1][y1-1] << "\n";
    }  

    return 0;
}