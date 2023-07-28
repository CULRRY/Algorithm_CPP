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
    stack<int> s;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;

        while (!s.empty() && h >= s.top())
            s.pop();

        ans += (long long)s.size();
        s.push(h);

    }
    
    cout << ans << endl;
    

    return 0;
}