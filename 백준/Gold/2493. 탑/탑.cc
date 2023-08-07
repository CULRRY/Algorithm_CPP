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
    stack<pair<int, int>> s;
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;


        while (!s.empty() && v > s.top().first)
        {
            s.pop();
        }
        

        if (s.empty())
        {
            ans[i] = 0;
            s.push({v, i});
        }
        else
        {
            ans[i] = s.top().second;
            s.push({v, i});
        }

    }


    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}