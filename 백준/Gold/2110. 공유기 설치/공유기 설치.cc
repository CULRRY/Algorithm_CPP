#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, c;
    cin >> n >> c;

    vector<int> h(n);

    for (int& i : h)
        cin >> i;

    ::sort(h.begin(), h.end());

    int left = 0;
    int right = h[n-1];
    int ans = 0;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        int norm = h[0];
        int cnt = 1;

        for (int i = 1; i < n; i++)
        {
            if (h[i] - norm >= mid)
            {
                cnt++;
                norm = h[i];
            }
        }

        if (cnt < c)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            ans = mid;
        }
    }
    
    cout << ans << endl;

    return 0;
}