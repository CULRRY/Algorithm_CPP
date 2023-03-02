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


enum {U, R, D, L};
vector<Point> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<vector<char>> board(101, vector<char>(101, '#'));
    Point now = {50, 50};
    int d = D;
    board[now.y][now.x] = '.';
    Point min = now;
    Point max = now;

    while (n--)   
    {
        char cmd;
        cin >> cmd;
        if (cmd == 'F')
        {
            now = {now.y + direction[d].y, now.x + direction[d].x};
        }
        else if (cmd == 'R')
        {
            d = (d+1) % 4;
        }
        else
        {
            if (d == U)
                d = L;
            else 
                d -= 1;
        }

        board[now.y][now.x] = '.';
        min = {std::min(min.y, now.y), std::min(min.x, now.x)};
        max = {std::max(max.y, now.y), std::max(max.x, now.x)};
    }
    

    for (int i = min.y; i <= max.y; i++)
    {
        for (int j = min.x; j <= max.x; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}