#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
string before, after;

int ans = 0;

void bt(string s)
{
    if (s == before)
        ans = 1;
    
    if (s.empty())
        return;

    if (s.back() == 'A')
    {
        string result = s.substr(0, s.size() - 1);
        bt(result);
    }
    
    if (s.front() == 'B')
    {
        string result = s;
        reverse(result.begin(), result.end());
        result = result.substr(0, result.size() - 1);
        bt(result);
    }
}

int main()
{
    FASTIO;


    cin >> before >> after;
    bt(after);
    cout << ans;

    return 0;
}