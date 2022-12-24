#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

using ll = long long;

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll& i : v) cin >> i;

    sort(v.begin(), v.end());

    
    ll min = INT64_MAX;
    vector<ll> solve(3);
    for (int i = 0; i < n; i++)
    {
        int left = 0, right = n-1;
        while (left < right)
        {

            if (right == i)
            {
                right--;
                continue;
            }

            if (left == i)
            {
                left++;
                continue;
            }
            ll sum = v[left] + v[right] + v[i];
            ll absum = std::abs(v[left] + v[right] + v[i]);

            if (absum < min)
            {
                min = absum;
                solve[0] = v[left];
                solve[1] = v[right];
                solve[2] = v[i];
            }

            if (sum == 0)
            {
                i = n + 1;
                break;
            }

            if (sum < 0)
            {
                left++;
                continue;
            }

            if (sum > 0)
            {
                right--;
                continue;
            }


        }
    }

    sort(solve.begin(), solve.end());

    for (int i : solve)
    {
        cout << i << " ";
    }
    return 0;
}