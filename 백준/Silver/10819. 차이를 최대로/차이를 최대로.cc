#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
vector<bool> isUsed;
vector<int> a;
vector<int> b;
int n;
int ans = 0;
void bt(int depth, int sum)
{
    if (depth == n)
    {
        ans = std::max(ans, sum);
    }

    for (int i = 0; i < n; i++)
    {
        if (isUsed[i] == false)
        {
            isUsed[i] = true;
            b[depth] = a[i];
            bt(depth+1, sum + abs(b[depth-1] - b[depth]));
            isUsed[i] = false;
        }
    }
}

int main()
{
    FASTIO;

    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    isUsed.assign(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        isUsed[i] = true;
        b[0] = a[i];
        bt(1, 0);
        isUsed[i] = false;
    }

    cout << ans << endl;

    return 0;
}