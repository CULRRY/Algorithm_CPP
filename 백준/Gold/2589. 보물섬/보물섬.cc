#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

struct Point
{
    int y, x;
};

int ans = 0;
int n, m;
vector<vector<char>> board;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void bfs(int y, int x)
{
    queue<Point> q;
    int cnt = -1;
    vector<vector<bool>> discoverd(n, vector<bool>(m, false));

    q.push({y, x});
    discoverd[y][x] = true;

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            Point now = q.front();
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = now.y + dy[d];
                int nx = now.x + dx[d];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                    continue;
                if (discoverd[ny][nx])
                    continue;
                if (board[ny][nx] == 'W')
                    continue;
                
                discoverd[ny][nx] = true;
                q.push({ny, nx});
            }
        }
        cnt++;
        
    }

    ans = std::max(cnt, ans);
    
}

int main()
{
    FASTIO;


    cin >> n >> m;

    board = vector<vector<char>>(n, vector<char>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'L')
            {
                bfs(i, j);
            }
        }
    }

    cout << ans << endl;


    return 0;
}