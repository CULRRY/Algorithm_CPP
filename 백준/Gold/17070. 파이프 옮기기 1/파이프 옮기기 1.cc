#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int y, x;
};

enum State
{
    Horizontal,
    Vertical,
    Diagonal,
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> graph(N+1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
        }
    }
    int count = 0;
    queue<pair<Point, State>> q;
    q.push(make_pair(Point{1, 2}, Horizontal));
    while (!q.empty())
    {
        Point now = q.front().first;
        State state = q.front().second;
        q.pop();

        if (now.y == N && now.x == N)
        {
            count++;
            continue;
        }

        Point next;
        next = {now.y + 1, now.x + 1};
        if (next.y > 0 && next.y <= N && next.x > 0 && next.x <= N)
        {
            if (graph[next.y][next.x] != 1 && graph[next.y - 1][next.x] != 1 && graph[next.y][next.x-1] != 1)
                q.push(make_pair(next, Diagonal));
        }

        if (state != Vertical)
        {
            next = {now.y, now.x + 1};
            if (next.y > 0 && next.y <= N && next.x > 0 && next.x <= N && graph[next.y][next.x] != 1)
            {
                q.push(make_pair(next, Horizontal));
            }
        }

        if (state != Horizontal)
        {
            next = {now.y + 1, now.x};
            if (next.y > 0 && next.y <= N && next.x > 0 && next.x <= N && graph[next.y][next.x] != 1)
            {
                q.push(make_pair(next, Vertical));
            }
        }


    }

    cout << count << "\n";
    

    return 0;
}