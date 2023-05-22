#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n;
vector<vector<int>> board;
int ans = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void Move(int y, int x, int v)
{
    if (y < 0 || y >= n || x < 0 || x >= n)
    {
        ans += v;
    }
    else
        board[y][x] += v;
}

void scatter(int y, int x, int d)
{
    int ny = y + dy[d];
    int nx = x + dx[d];

    int ay = y + 2 * dy[d];
    int ax = x + 2 * dx[d];

    int sum = board[ny][nx];
    int alpha = board[ny][nx];
    board[ny][nx] = 0;

    Move(y + dy[(d + 1) % 4], x + dx[(d + 1) % 4], sum * 0.01);
    alpha -= static_cast<int>(sum * 0.01);
    Move(y + dy[(d + 3) % 4], x + dx[(d + 3) % 4], sum * 0.01);
    alpha -= static_cast<int>(sum * 0.01);
    Move(ny + dy[(d + 1) % 4], nx + dx[(d + 1) % 4], sum * 0.07);
    alpha -= static_cast<int>(sum * 0.07);
    Move(ny + dy[(d + 3) % 4], nx + dx[(d + 3) % 4], sum * 0.07);
    alpha -= static_cast<int>(sum * 0.07);
    Move(ny + 2 * dy[(d + 1) % 4], nx + 2 * dx[(d + 1) % 4], sum * 0.02);
    alpha -= static_cast<int>(sum * 0.02);
    Move(ny + 2 * dy[(d + 3) % 4], nx + 2 * dx[(d + 3) % 4], sum * 0.02);
    alpha -= static_cast<int>(sum * 0.02);
    Move(ay + dy[(d + 1) % 4], ax + dx[(d + 1) % 4], sum * 0.1);
    alpha -= static_cast<int>(sum * 0.1);
    Move(ay + dy[(d + 3) % 4], ax + dx[(d + 3) % 4], sum * 0.1);
    alpha -= static_cast<int>(sum * 0.1);
    Move(ay + dy[d], ax + dx[d], sum * 0.05);
    alpha -= static_cast<int>(sum * 0.05);
    Move(ay, ax , alpha);
}


int main()
{
    FASTIO;
    
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n, 0));

    for (auto& v : board)
        for (auto& i : v)
            cin >> i;

    int y = n / 2;
    int x = n / 2;
    int d = 0;
    int dist = 1;

    int flag = false;
    while (true)
    {
        for (int t = 0; t < 2; t++)
        {
            for (int i = 0; i < dist; i++)
            {
                scatter(y, x, d);


                y = y + dy[d];
                x = x + dx[d];

                if (y == 0 && x == 0)
                {
                    flag = true;
                    t = 4;
                    break;
                }
            }
            d = (d + 1) % 4;
        }
        if (flag)
            break;
        dist++;
    }


    cout << ans << endl;
    

    return 0;
}