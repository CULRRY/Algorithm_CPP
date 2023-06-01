#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

vector<int> cntArr(100001, 0);

int main()
{
    FASTIO;

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int left = 0;
    int right = 0;
    int ans = 0;

    while (right < n)
    {
        cntArr[arr[right]]++;
        if (cntArr[arr[right]] > k)
        {
            while (true)
            {
                cntArr[arr[left]]--;
                if (arr[right] == arr[left])
                {
                    left++;
                    break;
                }
                left++;
            }
        }

        ans = std::max(ans, right - left + 1);

        right++;
    }
    cout << ans << endl;

    return 0;
}