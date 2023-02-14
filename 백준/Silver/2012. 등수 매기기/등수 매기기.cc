#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<long long> expectation(n, 0);
    for (long long& i : expectation)
    {
        cin >> i;
    }

    sort(expectation.begin(), expectation.end());
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += abs(expectation[i-1] - i);
    }

    cout << ans << endl;

    return 0;
}