#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> minDP(3);
    vector<int> maxDP(3);

    for (int i = 1; i <= N; i++)
    {
        int first, second, third;
        cin >> first >> second >> third;
        if (i == 1)
        {
            minDP = maxDP = {first, second, third};
            continue;
        }

        minDP = {std::min(minDP[0], minDP[1]) + first, *min_element(minDP.begin(), minDP.end()) + second, std::min(minDP[1], minDP[2]) + third};
        maxDP = {std::max(maxDP[0], maxDP[1]) + first, *max_element(maxDP.begin(), maxDP.end()) + second, std::max(maxDP[1], maxDP[2]) + third};
    }

    cout << *max_element(maxDP.begin(), maxDP.end()) << " " << *min_element(minDP.begin(), minDP.end());

    return 0;
}