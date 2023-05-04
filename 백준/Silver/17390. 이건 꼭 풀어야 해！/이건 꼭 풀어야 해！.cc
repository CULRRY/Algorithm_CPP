#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    int n, q;
    cin >> n >> q;
    vector<int>arr(n+1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    vector<int> comul_sum(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        comul_sum[i] = comul_sum[i-1] + arr[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << comul_sum[r] - comul_sum[l - 1] << endl;
    }
    

    return 0;
}