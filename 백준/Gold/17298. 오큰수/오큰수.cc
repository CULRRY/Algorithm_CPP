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

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int idx = n - 1;
    vector<int> ans(n, 0);
    stack<int> s;
    ans[idx] = -1;
    s.push(arr[idx]);


    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= s.top())
        {
            s.pop();
        }

        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }

        s.push(arr[i]);
        
    }

    for (int i : ans)
        cout << i << " ";

    
    return 0;
}