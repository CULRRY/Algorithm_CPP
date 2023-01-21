#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> sushi(d + 1, 0);
    vector<int> trail(n, 0);
    sushi[c] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> trail[i];
    }
    int ans = 1;
    for (int i = 0; i < k; i++)
    {
        sushi[trail[i]]++;
        if (sushi[trail[i]] == 1)
        {
            ans++;
        }
    }
    int sum = ans;
    for (int i = 1; i < n; i++)
    {
        sushi[trail[(i + k - 1) % n]]++;
        if (sushi[trail[(i + k - 1) % n]] == 1)
        {
            sum++;
        }
        sushi[trail[i - 1]]--;
        if (sushi[trail[i - 1]] == 0)
        {
            sum--;
        }
        ans = std::max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}