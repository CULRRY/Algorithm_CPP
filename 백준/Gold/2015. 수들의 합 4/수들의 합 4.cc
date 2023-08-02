#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

using ll = long long;
int main()
{
    FASTIO;

    ll n, k;
    cin >> n >> k;
    vector<ll> pre(n + 1, 0);
    unordered_map<ll, ll> m;
    m[0] = 1;
    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ll v;
        cin >> v;

        pre[i] = v + pre[i-1];

        auto operand = m.find(pre[i] - k);

        if (operand != m.end())
        {
            ans += operand->second;
        }

        m[pre[i]]++;
    }


    cout << ans << endl;

    


    return 0;
}