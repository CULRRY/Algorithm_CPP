#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
vector<bool> isUsed;
vector<int> a;
vector<int> b;
int n;
int ans = 0;

int main()
{
    FASTIO;

    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    isUsed.assign(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    do 
    {
        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            sum += abs(a[i-1] - a[i]);
        }
        ans = std::max(ans, sum);
    }
    while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;

    return 0;
}