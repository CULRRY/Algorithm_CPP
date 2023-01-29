#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n, s;
vector<int> arr;
vector<bool> isUsed;
int answer = 0;
void bt(int depth, int sum, int prev)
{
    if (sum == s)
    {
        answer++;
    }

    if (depth == n)
    {
        return;
    }

    for (int i = prev + 1; i < n; i++)
    {
        if (isUsed[i] == false)
        {
            isUsed[i] = true;
            bt(depth+1, sum + arr[i], i);
            isUsed[i] = false;
        }
    }
}

int main()
{
    FASTIO;

    cin >> n >> s;
    arr.assign(n, 0);
    isUsed.assign(n, false);
    for (int& i : arr)
        cin >> i;

    bt(0, 0, -1);
    if (s == 0)
        answer--;
    cout << answer << endl;

    return 0;
}