#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, m, l;
    cin >> n >> m >> l;

    vector<int> s(n);
    bool flag = true;
    for (int& i : s)
    {
        cin >> i;
    }

    s.push_back(0);
    s.push_back(l);



    int ans = INT_MAX;
    sort(s.begin(), s.end());
    
    int left = 1;
    int right = l;

    while (left <= right)
    {
        int mid = (right + left) / 2;
        int cnt = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            int gap = s[i+1] - s[i];
            cnt += (gap / mid);

            if (gap % mid == 0)
                cnt--;
        }

        if (cnt > m)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            ans = std::min(ans, mid);
        }
    }

    cout << ans << endl;

    return 0;
}