#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
using ll = long long;
ll n;
vector<ll> a;
ll b, c;

int main()
{
    FASTIO;

    cin >> n;
    a = vector<ll>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> b >> c;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll cnt = a[i];

        ans++;
        cnt -= b;

        if (cnt < 0)
            continue;
        
        ans += cnt / c;
        if (cnt % c > 0)
            ans++;
    }

    cout << ans << endl;

    return 0;
}