#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;
int n;
int cnt = 0;

int main()
{
    FASTIO;


    cin >> n;

    vector<int> v(n+1);

    for (int i = 2; i <= n; i++)
    {
        v[i] = i;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (v[i] == 0)
            continue;
        for (int j = i*i; j <= n; j += i)
        {
            v[j] = 0;
        }
    }

    vector<int> nums;
    nums.push_back(0);
    int sum = 0;
    for (int i : v)
    {
        if (i != 0)
        {
            sum += i;
            nums.push_back(sum);
        }
    }

    int i = 0, j = 1;

    while (i <= j)
    {
        if (j >= nums.size())
            break;
        
        int result = nums[j] - nums[i];

        if (result == n)
        {
            cnt++;
            j++;
            continue;
        }

        if (result > n)
        {
            i++;
            continue;
        }

        if (result < n)
        {
            j++;
            continue;
        }


    }

    cout << cnt;


    return 0;
}