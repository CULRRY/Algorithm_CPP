#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;
int n;
vector<vector<int>> board;

struct Point
{
    int y, x;
};

bool isBound(const Point& p)
{
    if (p.y < 0 || p.y >= n)
        return false;
    
    if (p.x < 0 || p.x >= n)
        return false;
    
    return true;
}

enum DIR {UP, DOWN, LEFT, RIGHT};

const vector<Point> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>> moveUP(vector<vector<int>> board)
{
    vector<vector<bool>> isMerged(n, vector<bool>(n, false));

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            Point now = {y, x};
            if (board[now.y][now.x] == 0)
                continue;

            while (true)
            {
                Point next = {now.y + d[UP].y, now.x + d[UP].x};
                if (isBound(next) == false)
                {
                    break;
                }

                if (board[next.y][next.x] != 0)
                {
                    if (board[next.y][next.x] != board[now.y][now.x])
                    {
                        break;
                    }

                    if (isMerged[next.y][next.x] == true)
                    {
                        break;
                    }
                    else
                    {
                        board[next.y][next.x] *= 2;
                        board[now.y][now.x] = 0;
                        isMerged[next.y][next.x] = true;
                        break;
                    }
                }

                ::swap(board[now.y][now.x], board[next.y][next.x]);
                now = next;
            }
            
        }
    }

    return board;
}

vector<vector<int>> moveDOWN(vector<vector<int>> board)
{
    vector<vector<bool>> isMerged(n, vector<bool>(n, false));

    for (int x = 0; x < n; x++)
    {
        for (int y = n-1; y >= 0; y--)
        {
            Point now = {y, x};
            if (board[now.y][now.x] == 0)
                continue;

            while (true)
            {
                Point next = {now.y + d[DOWN].y, now.x + d[DOWN].x};
                if (isBound(next) == false)
                {
                    break;
                }

                if (board[next.y][next.x] != 0)
                {
                    if (board[next.y][next.x] != board[now.y][now.x])
                    {
                        break;
                    }

                    if (isMerged[next.y][next.x] == true)
                    {
                        break;
                    }
                    else
                    {
                        board[next.y][next.x] *= 2;
                        board[now.y][now.x] = 0;
                        isMerged[next.y][next.x] = true;
                        break;
                    }
                }

                ::swap(board[now.y][now.x], board[next.y][next.x]);
                now = next;
            }
            
        }
    }

    return board;
}

vector<vector<int>> moveRIGHT(vector<vector<int>> board)
{
    vector<vector<bool>> isMerged(n, vector<bool>(n, false));

    for (int y = 0; y < n; y++)
    {
        for (int x = n-1; x >= 0; x--)
        {
            Point now = {y, x};
            if (board[now.y][now.x] == 0)
                continue;

            while (true)
            {
                Point next = {now.y + d[RIGHT].y, now.x + d[RIGHT].x};
                if (isBound(next) == false)
                {
                    break;
                }

                if (board[next.y][next.x] != 0)
                {
                    if (board[next.y][next.x] != board[now.y][now.x])
                    {
                        break;
                    }

                    if (isMerged[next.y][next.x] == true)
                    {
                        break;
                    }
                    else
                    {
                        board[next.y][next.x] *= 2;
                        board[now.y][now.x] = 0;
                        isMerged[next.y][next.x] = true;
                        break;
                    }
                }

                ::swap(board[now.y][now.x], board[next.y][next.x]);
                now = next;
            }
            
        }
    }

    return board;
}

vector<vector<int>> moveLEFT(vector<vector<int>> board)
{
    vector<vector<bool>> isMerged(n, vector<bool>(n, false));

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            Point now = {y, x};
            if (board[now.y][now.x] == 0)
                continue;

            while (true)
            {
                Point next = {now.y + d[LEFT].y, now.x + d[LEFT].x};
                if (isBound(next) == false)
                {
                    break;
                }

                if (board[next.y][next.x] != 0)
                {
                    if (board[next.y][next.x] != board[now.y][now.x])
                    {
                        break;
                    }

                    if (isMerged[next.y][next.x] == true)
                    {
                        break;
                    }
                    else
                    {
                        board[next.y][next.x] *= 2;
                        board[now.y][now.x] = 0;
                        isMerged[next.y][next.x] = true;
                        break;
                    }
                }

                ::swap(board[now.y][now.x], board[next.y][next.x]);
                now = next;
            }
            
        }
    }

    return board;
}

int maxv = 0;
void go(vector<vector<int>> board, int depth)
{
    if (depth > 5)
        return;

    int m = 0;
    for (vector<int>& v : board)
        for (int& i : v)
            m = std::max(m, i);
        
    maxv = std::max(m, maxv);

    go(moveUP(board), depth+1);
    go(moveDOWN(board), depth+1);
    go(moveLEFT(board), depth+1);
    go(moveRIGHT(board), depth+1);
}

int main()
{
    FASTIO;

    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));

    for (vector<int>& v : board)
        for (int& i : v)
            cin >> i;



    
    go(board, 0);
    cout << maxv;


    return 0;
}