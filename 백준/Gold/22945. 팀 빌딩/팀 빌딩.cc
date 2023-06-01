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
    vector<int> arr(n);
    for (int& i : arr)
        cin >> i;
    
    int left = 0;
    int right = n-1;

    int ans = 0;

    while (left < right)
    {
        int l = arr[left];
        int r = arr[right];

        int v = std::min(l, r) * (right - left - 1);
        ans = std::max(ans, v);

        if (r >= l)
        {
            int idx = left;
            while (l >= arr[idx])
            {
                idx++;
                if (idx >= n)
                    break;
            }
            
            left = idx;
        }
        else
        {
            int idx = right;
            while (r >= arr[idx])
            {
                idx--;
                if (idx < 0)
                    break;
            }
            right = idx;
        }
    }
    
    cout << ans << endl;

    return 0;
}