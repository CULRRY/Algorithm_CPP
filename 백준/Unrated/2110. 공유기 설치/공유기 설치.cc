#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int n, c;
vector<int> v;

int main()
{
    FASTIO;

    cin >> n >> c;
    v = vector<int>(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    int left = 1, right = v[n-1] - v[0];
    int ans = 0;

    while (left <= right)
    {
        int cnt = 1;

        int mid = (left + right) / 2;

        int start = v[0];

        for (int  i = 1; i < n; i++)
        {
            int d = v[i] - start;
            if (mid <= d) 
            {
                cnt++;
                start = v[i];
            }
        }

        if (cnt >= c)
        {
            ans = mid;
            left = mid+1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    cout << ans << endl;

    return 0;
}

//1 2 4 8 9