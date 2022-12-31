#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int n, m;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

struct Point
{
    int y, x;
};

bool isBound(int y, int x)
{
    if (y < 0 || y >= n)
        return false;

    if (x < 0 || x >= m)
        return false;

    return true;
}

vector<int> table(1);
int num = 0;
vector<vector<int>> mark;
vector<vector<bool>> discoverd;

void bfs(Point p, vector<vector<int>> &board)
{
    num++;
    
    queue<Point> q;
    queue<Point> visit;
    int cnt = 0;
    q.push(p);
    discoverd[p.y][p.x] = true;
    while (!q.empty())
    {
        Point now = q.front();
        q.pop();

        cnt++;
        mark[now.y][now.x] = num;

        for (int i = 0; i < 4; i++)
        {
            Point next = {now.y + dy[i], now.x + dx[i]};

            if (!isBound(next.y, next.x))
                continue;

            if (discoverd[next.y][next.x])
                continue;

            if (board[next.y][next.x] == 1)
                continue;

            q.push(next);
            discoverd[next.y][next.x] = true;
        }
    }

    table.push_back(cnt);
}

int main()
{
    FASTIO;

    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m, 0));
    discoverd = vector<vector<bool>>(n, vector<bool>(m, false)); 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '1')
            {
                board[i][j] = 1;
            }
            else
            {
                board[i][j] = 0;
            }
        }
    }

    mark = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0 && discoverd[i][j] == false)
                bfs({i, j}, board);
        }
    }
    vector<vector<int>> result(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1)
            {
                Point now = {i, j};
                set<int> s;
                int tmp = 1;
                for (int i = 0; i < 4; i++)
                {
                    Point next = {now.y + dy[i], now.x + dx[i]};

                    if (!isBound(next.y, next.x))
                        continue;

                    if (board[next.y][next.x] == 1)
                        continue;
                    
                    s.insert(mark[next.y][next.x]);
                }
                
                for (auto i : s)
                {
                    tmp += table[i];
                }

                result[i][j] = tmp % 10;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << result[i][j];
        }
        cout << "\n";
    }

    return 0;
}