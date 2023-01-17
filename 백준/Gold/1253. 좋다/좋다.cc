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

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[i] = a;
    }

    int cnt = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            if (left == i)
            {
                left++;
                continue;
            }

            if (right == i)
            {
                right--;
                continue;
            }

            int sum = v[left] + v[right];

            if (sum == v[i])
            {
                cnt++;
                break;
            }

            if (sum > v[i])
            {
                right--;
                continue;
            }

            if (sum < v[i])
            {
                left++;
                continue;
            }
        }
        
    }

    cout << cnt;



    return 0;
}