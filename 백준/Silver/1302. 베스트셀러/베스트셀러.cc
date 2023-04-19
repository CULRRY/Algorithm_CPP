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

    map<string, int> dict;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        dict[s]++;
    }
    string ans = "";
    int cnt = 0;
    for (auto item : dict)
    {
        if (item.second > cnt)
        {
            ans = item.first;
            cnt = item.second;
        }
    }

    cout << ans;

    return 0;
}