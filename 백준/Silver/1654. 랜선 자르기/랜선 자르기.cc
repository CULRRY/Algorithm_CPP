#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;
    vector<int> v(K);
    for (int i = 0; i < K; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long left = 1;
    long long right = v.back();
    int solution = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        int count = 0;
        for (int i = 0; i < K; i++)
        {
            count += v[i] / mid;
        }

        if (count >= N)
        {
            left = mid + 1;
            if (mid > solution)
                solution = mid;
            continue;
        }

        else if (count < N)
        {
            right = mid - 1;
            continue;
        }
    }
    cout << solution << "\n";

    return 0;
}