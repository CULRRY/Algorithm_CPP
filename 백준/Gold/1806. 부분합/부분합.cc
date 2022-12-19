#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> prefix_sum;

    int sum = 0;
    prefix_sum.push_back(sum);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        prefix_sum.push_back(sum);
    }
    int minLength = INT_MAX;

    int i = 0, j = 1;
    while (i <= j)
    {
        int sol = prefix_sum[j] - prefix_sum[i];
        if (sol >= s)
        {
            if (j - i < minLength)
                minLength = j - i;
        }

        if (sol < s)
        {
            j++;
            if (j > n)
                break;
            continue;
        }
        
        if (sol >= s)
        {
            i++;
            continue;
        }


    }
    if (minLength == INT_MAX)
        cout << 0;
    else
        cout << minLength;

    return 0;
}