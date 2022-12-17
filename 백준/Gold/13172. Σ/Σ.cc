#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1'000'000'007;

ll gcd(ll a, ll b)
{
    if (b == 0) 
        return a;
    else 
        return gcd(b, a%b);
}

ll power(ll x, ll n)
{
    if (n == 0)
        return 1;
    else if (n%2 == 0)
    {
        return power(x, n / 2) % MOD * power(x, n / 2) % MOD;
    }
    else
    {
        return power(x, (n-1) / 2) % MOD * power(x, (n-1) / 2) % MOD * x % MOD;
    }
}

// b^X-2 mod X = b^-1
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;
    
    ll result = 0;


    while(m--)
    {
        ll n, s;
        cin >> n >> s;
        int g = gcd(n, s);
        n /= g;
        s /= g;

        result += s * power(n, MOD-2) % MOD;
        result %= MOD;

    }

    cout << result << "\n";

    return 0;
}