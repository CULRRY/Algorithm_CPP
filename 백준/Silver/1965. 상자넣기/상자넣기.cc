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
    vector<int> boxes(n);
    for (int& i : boxes)
        cin >> i;

    vector<int> result;
    result.push_back(boxes[0]);

    for (int i = 1; i < n; i++)
    {
        int now = boxes[i];
        auto lw = lower_bound(result.begin(), result.end(), now);

        if (lw == result.end())
        {
            result.push_back(now);
        }
        else
        {
            *lw = now;
        }
    }

    cout << result.size() << endl;

    return 0;
}