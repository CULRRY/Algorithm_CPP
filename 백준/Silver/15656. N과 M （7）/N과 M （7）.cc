#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

vector<int> ans;
int n, m;
vector<int> arr;
void bt(int depth)
{
    if (depth >= m)
    {
        for (int& i : ans)
            cout << i << " ";
        
        cout << endl;
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        ans[depth] = arr[i];
        bt(depth+1);
    }
}

int main()
{
    FASTIO;

    cin >> n >> m;
    arr = vector<int>(n);
    ans = vector<int>(m, 0);
    for (int& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    bt(0);

    return 0;
}