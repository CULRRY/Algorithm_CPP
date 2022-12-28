#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

using ll = long long;

int main()
{
    FASTIO;

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewels;
    for (int i = 0; i < n; i++)
    {
        int m, v;
        cin >> m >> v;
        jewels.push_back({m, v});
    }

    vector<int> bag(k);
    for (int &i : bag)
        cin >> i;
    sort(jewels.begin(), jewels.end());
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;

    int j = 0;
    ll sum = 0;
    for (int i = 0; i < k; i++)
    {
        for (; j < n; j++)
        {
            if (jewels[j].first > bag[i])
                break;
            
            pq.push(jewels[j].second);
        }

        if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }

    }

    cout << sum;

    return 0;
}