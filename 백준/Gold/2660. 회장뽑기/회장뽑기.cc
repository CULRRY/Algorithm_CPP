#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int n;
vector<int> cand;
int bfs(int s,vector<vector<int>>& people)
{
    queue<int> q;
    vector<bool> discoverd(n+1, false);
    discoverd[s] = true;
    q.push(s);
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        cnt++;
        for (int s = 0; s < sz; s++)
        {
            int now = q.front();
            q.pop();

            for (int next : people[now])
            {
                if (discoverd[next] == true)
                    continue;

                q.push(next);
                discoverd[next] = true;
            }
        }
        
    }

    return cnt - 1;
    
}

int main()
{
    FASTIO;
    cin >> n;
    vector<vector<int>> people(n+1, vector<int>());
    int v1 = 0, v2 = 0;
    cin >> v1 >> v2;
    while (v1 != -1 || v2 != -1)
    {
        people[v1].push_back(v2);
        people[v2].push_back(v1);
        cin >> v1 >> v2;
    }


    for (int i = 1; i <= n; i++)
    {
        cand.push_back(bfs(i, people));
    }

    int siz = *min_element(cand.begin(), cand.end());
    vector<int> ans;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cand[i-1] == siz)
        {
            ans.push_back(i);
            cnt++;
        }
    }

    cout << siz << " " << cnt << endl;
    sort(ans.begin(), ans.end());
    for (int i : ans)
    {
        cout << i << " ";
    }


    return 0;
}