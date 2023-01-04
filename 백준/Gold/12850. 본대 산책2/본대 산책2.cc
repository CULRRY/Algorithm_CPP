#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;
using ull = unsigned long long;
constexpr int MOD = 1'000'000'007;
int d;
int cnt;
vector<vector<ull>> matrix(8, vector<ull>(8));

vector<vector<ull>> multi(vector<vector<ull>> m1, vector<vector<ull>> m2)
{
    vector<vector<ull>> tmp(8, vector<ull>(8, 0));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                tmp[i][j] += (m1[i][k] % MOD) * (m2[k][j] % MOD); 
            }
            tmp[i][j] %= MOD;
        }
    }

    return tmp;
}

vector<vector<ull>> pow(vector<vector<ull>> m, ull n)
{
    if (n == 1)
        return m;
    
    if (n % 2 == 0)
    {
        vector<vector<ull>> tmp = pow(m, n / 2);
        return multi(tmp, tmp);
    }
    else
    {
        vector<vector<ull>> tmp = pow(m, (n - 1) / 2);
        tmp = multi(tmp, tmp);
        return multi(tmp, m);
    }
}

int main()
{
    FASTIO;

    matrix = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}};

    cin >> d;
    vector<vector<ull>> result(8, vector<ull>(8, 0));

    cout << pow(matrix, d)[0][0] % MOD;

    return 0;
}