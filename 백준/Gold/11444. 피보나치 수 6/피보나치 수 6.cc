#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
using matrix = vector<vector<ll>>;
constexpr ll MOD = 1'000'000'007;

matrix multi(matrix m1, matrix m2)
{
    matrix tmp(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                tmp[i][j] += m1[i][k] % MOD * m2[k][j] % MOD;
            }
        }
    }
    return tmp;
}

matrix pow(matrix m, ll n)
{
    if (n == 1)
        return m;

    if (n % 2 == 1)
    {
        matrix tmp = pow(m, (n - 1) / 2);
        tmp = multi(tmp, multi(tmp, m));
        return tmp;
    }
    else
    {
        matrix tmp = pow(m, n / 2);
        tmp = multi(tmp, tmp);
        return tmp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    if (n == 0)
        cout << 0;
    else
    {
        matrix m = {{1, 1}, {1, 0}};

        matrix result = pow(m, n);
        cout << result[0][1] % MOD;
    }

    return 0;
}