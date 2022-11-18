#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> maxV(3);
    vector<int> minV(3);
    vector<int> minDP(3);
    vector<int> maxDP(3);

    for (int i = 1; i <= N; i++)
    {
        int first, second, third;
        cin >> first >> second >> third;
        if (i == 1)
        {
            minDP = maxDP = minV = maxV = {first, second, third};
            continue;
        }

        minDP[0] = std::min(minV[0], minV[1]) + first;
        minDP[1] = *min_element(minV.begin(), minV.end()) + second;
        minDP[2] = std::min(minV[1], minV[2]) + third;

        minV = vector<int>(minDP);

        maxDP[0] = std::max(maxV[0], maxV[1]) + first;
        maxDP[1] = *max_element(maxV.begin(), maxV.end()) + second;
        maxDP[2] = std::max(maxV[1], maxV[2]) + third;

        maxV = vector<int>(maxDP);
    }

    cout << *max_element(maxDP.begin(), maxDP.end()) << " " << *min_element(minDP.begin(), minDP.end());



    return 0;
}