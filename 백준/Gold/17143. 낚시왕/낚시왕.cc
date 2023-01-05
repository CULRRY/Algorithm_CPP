#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;

#define row first
#define col second
struct Point
{
    int y, x;
};

struct Shark
{
    int speed, dir, size;
};

enum
{
    UP = 1,
    DOWN = 2,
    RIGHT = 3,
    LEFT = 4,
};

vector<Point> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int r, c, m;
int cnt = 0;
void fishing(vector<vector<Shark>>& board, set<pair<int, int>>& sharks)
{
    int fisherMan = 0;
    for (int i = 1; i <= c; i++)
    {
        fisherMan++;
        for (int j = 1; j <= r; j++)
        {
            if (board[j][fisherMan].size != 0)
            {
                cnt += board[j][fisherMan].size;
                board[j][fisherMan] = {0, 0, 0};
                sharks.erase({j, fisherMan});
                break;
            }
        }
        vector<vector<Shark>> tmp(r + 1, vector<Shark>(c + 1, {0, 0, 0}));
        set<pair<int, int>> tmpSet;
        for (auto& shark : sharks)
        {
            Point pos = {shark.row, shark.col};
            int speed = board[shark.row][shark.col].speed;
            int dir = board[shark.row][shark.col].dir;
            int size = board[shark.row][shark.col].size;
            int left = speed;
            while (left != 0)
            {
                if (dir == UP)
                {
                    if (left > pos.y - 1)
                    {
                        left -= pos.y - 1;
                        pos.y = 1;
                        dir = DOWN;
                    }
                    else
                    {
                        pos.y -= left;
                        left = 0;
                    }
                    continue;
                }
                else if (dir == DOWN)
                {
                    if (left > r - pos.y)
                    {
                        left -= r - pos.y;
                        pos.y = r;
                        dir = UP;
                    }
                    else
                    {
                        pos.y += left;
                        left = 0;
                    }
                    continue;
                }
                else if (dir == RIGHT)
                {
                    if (left > c - pos.x)
                    {
                        left -= c - pos.x;
                        pos.x = c;
                        dir = LEFT;
                    }
                    else
                    {
                        pos.x += left;
                        left = 0;
                    }
                    continue;                    
                }
                else if (dir == LEFT)
                {
                    if (left > pos.x - 1)
                    {
                        left -= pos.x - 1;
                        pos.x = 1;
                        dir = RIGHT;
                    }
                    else
                    {
                        pos.x -= left;
                        left = 0;
                    }
                    continue; 
                }
            }
            tmpSet.insert({pos.y, pos.x});
            if (tmp[pos.y][pos.x].size == 0)
                tmp[pos.y][pos.x] = {speed, dir, size};
            else
            {
                if (tmp[pos.y][pos.x].size < size)
                {
                    tmp[pos.y][pos.x] = {speed, dir, size};
                }
            }
        }
        board = vector<vector<Shark>>(tmp);
        sharks = set<pair<int, int>>(tmpSet);
    }
}

int main()
{
    FASTIO;

    
    cin >> r >> c >> m;
    set<pair<int, int>> sharks;
    vector<vector<Shark>> board(r + 1, vector<Shark>(c + 1, {0, 0, 0}));
    for (int i = 0; i < m; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c] = {s, d, z};
        sharks.insert({r, c});
    }

    fishing(board, sharks);
    
    cout << cnt;
    

    return 0;
}