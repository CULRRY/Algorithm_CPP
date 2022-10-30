#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> trees(N);

    for (int i = 0; i < N; i++)
    {
        cin >> trees[i];
    }

    int height;
    int left = 0, right = *max_element(trees.begin(), trees.end()), mid;
    int max = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        long long sum = 0;
        for (int h : trees)
        {
            sum += std::max(0, h - mid);
        }

        if (sum >= M)
        {
            left = mid + 1;
            if (mid > max)
            {
                max = mid;
            }
        }
        else
        {
            right = mid - 1;
        }

    }

    cout << max << "\n";

    return 0;
}