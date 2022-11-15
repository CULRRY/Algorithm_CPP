#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 1000000000;

int bfs(int s, int t)
{
    queue<int> q;
    q.push(s);

    int count = 1;
    while (!q.empty())
    {
        int sz = q.size();
        for (int size = 0; size < sz; size++)
        {
            int now = q.front();
            q.pop();

            if (now == t)
            {
                return count;
            }

            if (now < MAX / 2)
            {
                q.push(now * 2);
            }

            if (now < MAX / 10)
            {
                q.push(now * 10 + 1);
            }
        }
        count++;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    cout << bfs(a, b) << "\n";

    return 0;
}