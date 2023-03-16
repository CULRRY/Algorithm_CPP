#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int s;
constexpr int MAX = 1500;
struct emoji
{
    int display;
    int clipboard;
};

int bfs()
{
    queue<emoji> q;
    vector<vector<bool>> discoverd(1501, vector<bool>(1501, false));
    q.push({1, 0});
    discoverd[1][0] =true;
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            emoji now = q.front();
            q.pop();
            if (now.display == s)
                return cnt;
            
            if (now.clipboard != 0)
            {
                if (now.display + now.clipboard < MAX)
                    if (discoverd[now.display + now.clipboard][now.clipboard] == false)
                    {
                        q.push({now.display + now.clipboard, now.clipboard});
                        discoverd[now.display + now.clipboard][now.clipboard] = true;
                    }
            }
            if (discoverd[now.display][now.display] == false)
            {
                q.push({now.display, now.display});
                discoverd[now.display][now.display] = true;
            }
            if (now.display != 0)
                if (discoverd[now.display - 1][now.clipboard] == false)
                {
                    q.push({now.display - 1, now.clipboard});
                    discoverd[now.display - 1][now.clipboard] = true;
                }
        }
        cnt++;
    }

    return -1;
}


int main()
{
    FASTIO;
    cin >> s;
    cout << bfs() << endl;

    return 0;
}