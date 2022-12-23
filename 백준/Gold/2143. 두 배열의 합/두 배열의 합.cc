#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int main()
{
    FASTIO;

    int t;
    cin >> t;

    int n;
    cin >> n;
    vector<int> a;

    int sum = 0;
    a.push_back(sum);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;

        a.push_back(sum);
    }

    int m;
    cin >> m;
    vector<int> b;
    sum = 0;
    b.push_back(sum);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        sum += x;

        b.push_back(sum);
    }

    vector<int> suma;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            suma.push_back(a[i] - a[j]);
        }
    }
    
    vector<int> sumb;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sumb.push_back(b[i] - b[j]);
        }
    }

    sort(sumb.begin(), sumb.end());
    
    long long cnt = 0;

    for (int item : suma)
    {
        int target = t - item;
        auto lw = lower_bound(sumb.begin(), sumb.end(), target);
        auto up = upper_bound(sumb.begin(), sumb.end(), target);
        cnt += up - lw;
    }

    cout << cnt;
    return 0;
}