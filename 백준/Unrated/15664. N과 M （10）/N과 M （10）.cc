#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n, m;
vector<int> arr;
vector<int> ans;
vector<bool> isUsed;

void bt(int depth, int idx)
{

    if (depth == m)
    {
        for (int i : ans)
            cout << i << " ";
        
        cout << endl;
        return;
    }

    int tmp = -1;
    for (int i = idx; i < n; i++)
    {
        if (isUsed[i] == true)
            continue;
        
        if (arr[i] == tmp)
            continue;
        
        ans[depth] = arr[i];
        tmp = arr[i];

        isUsed[i] = true;
        bt(depth+1, i);
        isUsed[i] = false;
    }
}

int main()
{
    FASTIO;

    cin >> n >> m;
    arr = vector<int>(n);
    ans = vector<int>(m, -1);
    isUsed = vector<bool>(n, false);

    for (int& i : arr)
        cin >> i;
    
    sort(arr.begin(), arr.end());

    bt(0, 0);


    return 0;
}