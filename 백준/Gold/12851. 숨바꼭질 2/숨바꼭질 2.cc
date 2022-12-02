#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 100001;
int size = MAX;
int num = 0;

void bfs(int n, int k)
{
    queue<int> q;
    vector<bool> visited(100001, 0);
    q.push(n);
    visited[n] = true;
    int cnt = 0;
    bool end = false;
    while(!q.empty())
    {
        int sz = q.size();

        for (int s = 0; s < sz; s++)
        {
            int now = q.front();
            q.pop();
            visited[now] = true;
            
            if (::size < cnt)
                return;

            if (now == k)
            {
                :: size = cnt;
                num++;
                continue;
            }

            for (int next : {now + 1, now - 1, now * 2})
            {
                if (next < 0 || next > MAX)
                    continue;

                if (!visited[next])
                    q.push(next);
            }
        }

        cnt++;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    bfs(n, k);
    cout << ::size << "\n" << num;

    return 0;
}