#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

enum
{
    W, R, B
};

struct Horse
{
    int y, x, d;
};

int n, k;
vector<vector<int>> board;
vector<Horse> h;
vector<vector<vector<int>>> horses;

int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

void turn_over(int& d)
{
    if (d == 0 || d == 2)
        d++;
    else
        d--;
}

int game()
{
    int turn = 1;

    while (turn <= 1000)    
    {
        for (int i = 1; i <= k; i++)
        {

            vector<int> team;

            bool flag = false;

            for (int item : horses[h[i].y][h[i].x])
            {
                if (item == i)
                    flag = true;

                if (flag)
                    team.push_back(item);
            }

            int ny = h[i].y + dy[h[i].d];
            int nx = h[i].x + dx[h[i].d];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            {
                turn_over(h[i].d);
                ny = h[i].y + dy[h[i].d];
                nx = h[i].x + dx[h[i].d];

                if (board[ny][nx] == B)
                    continue;
                if (board[ny][nx] == R)
                {
                    for (int j = 0; j < team.size(); j++)
                    {
                        horses[h[i].y][h[i].x].pop_back();
                    }

                    for (int j = team.size() - 1; j >= 0; j--)
                    {
                        h[team[j]].y = ny;
                        h[team[j]].x = nx;

                        horses[ny][nx].push_back(team[j]);
                    }
                }
                else
                {
                    for (int j = 0; j < team.size(); j++)
                    {
                        horses[h[i].y][h[i].x].pop_back();
                    }

                    for (int num : team)
                    {
                        h[num].y = ny;
                        h[num].x = nx;

                        horses[ny][nx].push_back(num);
                    }
                }
            }
            else if (board[ny][nx] == B)
            {
                turn_over(h[i].d);
                ny = h[i].y + dy[h[i].d];
                nx = h[i].x + dx[h[i].d];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;

                if (board[ny][nx] == B)
                    continue;

                if (board[ny][nx] == R)
                {
                    for (int j = 0; j < team.size(); j++)
                    {
                        horses[h[i].y][h[i].x].pop_back();
                    }

                    for (int j = team.size() - 1; j >= 0; j--)
                    {
                        h[team[j]].y = ny;
                        h[team[j]].x = nx;

                        horses[ny][nx].push_back(team[j]);
                    }
                }
                else
                {
                    for (int j = 0; j < team.size(); j++)
                    {
                        horses[h[i].y][h[i].x].pop_back();
                    }

                    for (int num : team)
                    {
                        h[num].y = ny;
                        h[num].x = nx;

                        horses[ny][nx].push_back(num);
                    }
                }
            }
            else if (board[ny][nx] == W)
            {
                for (int j = 0; j < team.size(); j++)
                {
                    horses[h[i].y][h[i].x].pop_back();
                }

                for (int num : team)
                {
                    h[num].y = ny;
                    h[num].x = nx;

                    horses[ny][nx].push_back(num);
                }
            }
            else
            {
                for (int j = 0; j < team.size(); j++)
                {
                    horses[h[i].y][h[i].x].pop_back();
                }

                for (int j = team.size() - 1; j >= 0; j--)
                {
                    h[team[j]].y = ny;
                    h[team[j]].x = nx;

                    horses[ny][nx].push_back(team[j]);
                }
            }



            if (horses[ny][nx].size() >= 4)
                return turn;

        }
        turn++;
    }
    

    return -1;

}

int main()
{
    FASTIO;

    cin >> n >> k;
    horses = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>()));
    board = vector<vector<int>>(n, vector<int>(n, W));
    h = vector<Horse>(k+1);
      
    for (auto& v : board)
        for (auto& i : v)
            cin >> i;

    for (int i = 1; i <= k; i++)
    {
        int y, x, d;
        cin >> y >> x >> d;
        y--;
        x--;

        h[i] = {y, x, d - 1};
        horses[y][x].push_back(i);
    }
    cout << game() << endl;

    return 0;
}