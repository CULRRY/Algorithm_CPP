#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    string a, b;
    cin >> a >> b;
    if (a.size() > b.size())
    {
        ::swap(a, b);
    }
    int n = a.size();
    int m = b.size();
    vector<int> dp(n, 0);
    int ans = 0;
    int start = 0; 
    int end = 0;

    while (end < a.size())
    {
        string tmp = a.substr(start, end - start + 1);
        if (b.find(tmp) != -1)
        {
            ans = std::max(ans, end - start + 1);
            end++;
        }
        else
        {
            start++;
        }
    }

    cout << ans;
    return 0;
}