#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
using ull = unsigned long long;
int main()
{
    FASTIO;

    int n;
    cin >> n;
    ull min = 0;
    vector<int> houses(100001, 0);
    for (int i = 0; i < n; i++)
    {
        ull a;
        cin >> a;
        min += a;
        houses[a]++;
    }
    int ans = 0;
    ull sum = min;
    int left = 0;
    int right = n;
    for (int i = 1; i <= 100000; i++)
    {
        left += houses[i-1];
        right -= houses[i-1];

        sum += left - right;
        if (min > sum)
        {
            min = sum;
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}