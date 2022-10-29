#include <bits/stdc++.h>
using namespace std;

#define INF 5001;
int grams[2] = {3, 5};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int memo[3][N+1];
    for (int i = 0; i <= N; i++)
    {
        memo[0][i] = INF;
    }
    for (int i = 0; i <= 2; i++)
    {
        memo[i][0] = 0;
    }
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j - grams[i-1] < 0)
            {
                memo[i][j] = memo[i-1][j];
                continue;
            }
            memo[i][j] = min(memo[i-1][j], memo[i][j-grams[i-1]] + 1);
        }
    }

    if (memo[2][N] > 5000)
    {
        cout << -1;
        return 0;
    }
    cout << memo[2][N];


    return 0;
}