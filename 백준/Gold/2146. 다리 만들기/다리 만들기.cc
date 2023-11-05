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

int n;
int island = 0;
int ans = INT_MAX;
vector<vector<int>> board;
vector<vector<bool>> visited;


int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void dfs(int y, int x, queue<Point>& q, vector<vector<bool>>& discoverd)
{
    visited[y][x] = true;
    discoverd[y][x] = true;
    q.push({y, x});

    for (int d = 0; d < 4; d++)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        
        if (visited[ny][nx])
            continue;
        
        if (board[ny][nx] == 0)
            continue;
        
        dfs(ny, nx, q, discoverd);
    }
}

void bfs(int y, int x)
{
    vector<vector<bool>> discovered(n, vector<bool>(n,  false));
    queue<Point> q;

    dfs(y, x, q, discovered);

    int cnt = 0;

    while (!q.empty())
    {
        int sz = q.size();

        while (sz--)
        {
            Point now = q.front();
            q.pop();

            if (cnt != 0 && board[now.y][now.x] == 1)
            {
                ans = std::min(ans, cnt - 1);
                return;
            }

            for (int d = 0; d < 4; d++)
            {
                int ny = now.y + dy[d];
                int nx = now.x + dx[d];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;

                if (discovered[ny][nx])
                    continue;

                q.push({ny, nx});
                discovered[ny][nx] = true;
            }
        }    
        cnt++;
    }
    

}

int main()
{
    FASTIO;

    cin >> n;

    board = vector<vector<int>>(n, vector<int>(n, 0));
    visited = vector<vector<bool>>(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
                continue;
            
            if (visited[i][j])
                continue;

            bfs(i, j);
        }
    }

    cout << ans << endl;

    return 0;
}