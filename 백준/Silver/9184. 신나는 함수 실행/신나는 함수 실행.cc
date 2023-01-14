#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl "\n"

using namespace std;

int memo[21][21][21];

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20)
    {
        if (memo[20][20][20] != 0)
            return memo[20][20][20];

        return w(20, 20, 20);
    }

    if (a < b && b < c)
    {
        int i, j, k;
        if (memo[a][b][c-1] == 0)
            memo[a][b][c-1] =  w(a, b, c-1);

        if (memo[a][b-1][c-1] == 0)
            memo[a][b-1][c-1] = w(a, b-1, c-1);

        if (memo[a][b-1][c] == 0)
            memo[a][b-1][c] = w(a, b-1, c);
        

        return memo[a][b][c-1] + memo[a][b-1][c-1] - memo[a][b-1][c];
    }

    int i, j, k, l;

    if (memo[a-1][b][c] == 0)
        memo[a-1][b][c] = w(a-1, b, c);

    if (memo[a-1][b - 1][c] == 0)
        memo[a-1][b - 1][c] = w(a-1, b-1, c);

    if (memo[a-1][b][c-1] == 0)
        memo[a-1][b][c-1] = w(a-1, b, c-1);

    if (memo[a-1][b-1][c-1] == 0)
        memo[a-1][b-1][c-1] = w(a-1, b-1, c-1);

    return memo[a-1][b][c] + memo[a-1][b - 1][c] + memo[a-1][b][c-1] - memo[a-1][b-1][c-1];
}

int main()
{
    FASTIO;

    
    int a, b, c;
    cin >> a >> b >> c;
    while (a != -1 || b != -1 || c != -1)
    {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
        cin >> a >> b >> c;
    }
    

    return 0;
}