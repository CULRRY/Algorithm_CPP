#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n;
enum
{
    TILE, SNAKE, APPLE
};

enum
{
    L, D
};

enum
{
    UP, RIGHT, DOWN, LEFT
};

struct Point
{
    int y, x;
};

struct Snake
{
    Point head;
    int length;
    int dir;
    deque<Point> body;
};
vector<Point> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool Move(Snake& snake, vector<vector<int>>& board)
{
    Point next = {snake.head.y + d[snake.dir].y, snake.head.x + d[snake.dir].x};
    if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
        return false;
    if (board[next.y][next.x] == SNAKE)
        return false;

    snake.body.push_front(next);
    snake.head = snake.body.front();
    if (board[next.y][next.x] == APPLE)
    {
        snake.length++;
    }
    else
    {
        Point tail = snake.body.back();
        board[tail.y][tail.x] = TILE;
        snake.body.pop_back();
    }
    board[next.y][next.x] = SNAKE;
    return true;
}
int main()
{
    FASTIO;


    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;
        board[y-1][x-1] = APPLE;
    }
    int l;
    cin >> l;
    Snake snake = {{0, 0}, 1, RIGHT};
    snake.body.push_front(snake.head);
    board[0][0] = SNAKE;
    int time = 0;
    queue<int> X;
    queue<int> C;
    while (l--)
    {
        int x, d;
        char c;
        cin >> x >> c;
        if (c == 'D')
            d = D;
        else
            d = L;
        X.push(x);
        C.push(d);
    }
    while(true)
    {
        if (!X.empty())
        {
            if (X.front() == time)
            {
                if (C.front() == L)
                {
                    if (snake.dir == UP)
                        snake.dir = LEFT;
                    else
                        snake.dir -= 1;
                }
                else
                {
                    snake.dir = (snake.dir + 1) % 4;
                }

                X.pop();
                C.pop();
            }
        }
        
        time++;
        if (!Move(snake, board))
        {
            break;
        }
    }
    cout << time << endl;
    return 0;
}