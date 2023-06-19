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
    vector<int> cal(367, 0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;

        for (int j = s; j <= e; j++)
        {
            cal[j]++;
        }
    }

    int ans = 0;

    int maxH = 0;
    int L = 0;
    for (int i = 1; i <= 366; i++)
    {
        if (cal[i] == 0)
        {
            ans += maxH * L;
            maxH = 0;
            L = 0;
            continue;
        }

        L++;
        maxH = std::max(cal[i], maxH);
    }

    cout << ans << endl;
    
    return 0;
}