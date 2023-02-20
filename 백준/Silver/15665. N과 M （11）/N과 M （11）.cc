#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

vector<int> v;
vector<int> ans;
int n, m;
set<string> memo;
void bt(int depth)
{
    if (depth == m)
    {
        string output = "";
        for (int i : ans)
            output += to_string(i) + " ";
        
        if (memo.find(output) != memo.end())
            return;
        
        memo.insert(output);
        cout << output << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        ans[depth] = v[i];
        bt(depth + 1);
    }
}

int main()
{
    FASTIO;

    cin >> n >> m;

    v = vector<int>(n);
    ans = vector<int>(m);
    for (int& i : v) cin >> i;
    for (int& i : ans) cin >> i;
    sort(v.begin(), v.end());
    bt(0);

    return 0;
}