#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    FASTIO;

    int n;
    cin >> n;

    vector<vector<ll>> v(11);
    int cnt = -1;
    for (int i = 0; i <= 9; i++)
    {
        v[1].push_back(i);
        cnt++;
    }
    if (n >= 0 && n <= 9)
    {
        cout << n;
        return 0;
    }
    ll divisor = 1;
    for (int i = 2; i <= 10; i++)
    {
        divisor *= 10;
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 0; k < v[i-1].size(); k++)
            {
                if (v[i-1][k] / (divisor / 10) >= j)
                    break;
                v[i].push_back(divisor * j + v[i-1][k]);
                cnt++;
                if (cnt == n)
                {
                    cout << v[i].back();
                    return 0;
                }
            }
        }
    }

    cout << -1;
    return 0;
}