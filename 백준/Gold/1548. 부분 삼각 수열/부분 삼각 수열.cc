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

    sort(arr.begin(), arr.end());
    int ans = 0;
    if (arr.size() >= 3)
        ans = 1;
    else
        ans = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j >= 0; j--)
        {
            if (i+1 > j) break;
            if (arr[i] + arr[i+1] > arr[j])
            {

                ans = std::max(ans, j - i + 1); 
                break;
            }
        }
    }

    cout << ans << endl;


    return 0;
}