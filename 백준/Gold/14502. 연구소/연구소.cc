#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int y, x;
};
vector<Point> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int h, w;
void bfs(vector<vector<int>> &lab, const vector<Point> &virus)
{
    queue<Point> q;
    for (int i = 0; i < virus.size(); i++)
        q.push(virus[i]);

    while (!q.empty())
    {
        Point now = q.front();
        q.pop();

        for (int i = 0; i < dir.size(); i++)
        {
            Point next = {now.y + dir[i].y, now.x + dir[i].x};
            if (next.x >= 0 && next.x < w && next.y >= 0 && next.y < h && lab[next.y][next.x] == 0)
            {
                lab[next.y][next.x] = 2;
                q.push(next);
            }
        }
    }
}

int CountZero(const vector<vector<int>> &lab)
{
    int cnt = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (lab[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;
    vector<vector<int>> lab(h, vector<int>(w, 0));
    vector<Point> canWall;
    vector<Point> virus;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 0)
            {
                canWall.push_back({i, j});
            }
            else if(lab[i][j] == 2)
            {
                virus.push_back({i, j});
            }
        }
    }

    int max = 0;
    for (int i = 0; i < canWall.size(); i++)
    {
        for (int j = i + 1; j < canWall.size(); j++)
        {
            for (int k = j + 1; k < canWall.size(); k++)
            {
                vector<vector<int>> trial(lab);
                trial[canWall[i].y][canWall[i].x] = 
                trial[canWall[j].y][canWall[j].x] =
                trial[canWall[k].y][canWall[k].x] = 1;

                bfs(trial, virus);
                int tmp = CountZero(trial);
                max = std::max(max, tmp);
            }
        }
    }

    cout << max << "\n";

    return 0;
}