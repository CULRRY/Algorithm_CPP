#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n, m;
vector<int> arr;
vector<bool> isUsed;
vector<int> ans;
void bt(int depth)
{
    if (depth == m)
    {
        for (int i : ans)
            cout << i << " ";
        
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isUsed[i] == true)
            continue;
        
        isUsed[i] = true;
        ans[depth] = arr[i];
        bt(depth + 1);
        isUsed[i] = false;
    }
}

int main()
{
    FASTIO;


    cin >> n >> m;
    arr = vector<int>(n);
    std::iota(arr.begin(), arr.end(), 1);
    isUsed = vector<bool>(n, false);
    ans = vector<int>(m, 0);

    bt(0);

    return 0;
}