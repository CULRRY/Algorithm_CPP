#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n;
vector<vector<int>> synergy;
vector<int> start;
vector<int> link;
int ans = INT_MAX;
vector<bool> isUsed;

int cal()
{
    int idxStart = 0;
    int idxLink = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == start[idxStart])
        {
            idxStart++;
            continue;
        }

        link[idxLink] = i;
        idxLink++;

    }

    int scoreStart = 0;
    int scoreLink = 0;
    for (int i : start)
    {
        for (int j : start)
        {
            scoreStart += synergy[i][j];
        }
    }

    for (int i : link)
    {
        for (int j : link)
        {
            scoreLink += synergy[i][j];
        }
    }

    return abs(scoreStart - scoreLink);
}

void bt(int depth, int idx)
{
    if (depth >= n/2)
    {
        ans = std::min(ans, cal());
        return;
    }

    for (int i = idx + 1; i < n; i++)
    {
        if (isUsed[i] == true)
            continue;
        
        start[depth] = i;
        isUsed[i] = true;
        bt(depth + 1, i);
        isUsed[i] = false;
    }
}

int main()
{
    FASTIO;

    cin >> n;
    synergy = vector<vector<int>>(n, vector<int>(n));
    start = vector<int>(n / 2);
    link = vector<int>(n / 2);
    isUsed = vector<bool>(n, false);
    for (auto& v : synergy)
        for (auto& i : v)
            cin >> i;
    
    bt(0, -1);

    cout << ans << endl;

    return 0;
}