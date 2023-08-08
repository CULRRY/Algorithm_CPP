#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    vector<int> gap(n-1, 0);
    for (int& i : v)
    {
        cin >> i;
    }

    for (int i = 1; i < n; i++)
    {
        gap[i-1] = v[i] - v[i-1];
    }

    std::sort(gap.begin(), gap.end());
    int ans = 0;
    for (int i = 0; i < n - k; i++)
    {
        ans += gap[i];
    }

    cout << ans;



    return 0;
}