#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

struct Point
{
    int y, x;
};

vector<Point> trace;
int maxCnt = 0;

void bt(vector<vector<int>>& board, int depth, vector<Point> enable, int index, int cnt)
{
    if (depth == enable.size())
        return;
    
    for (int i = 0; i < depth; i++)
    {
        if (abs(trace[i].x - enable[index].x) == abs(trace[i].y - enable[index].y))
            return;
    }

    maxCnt = std::max(cnt, maxCnt);
    for (int i = index + 1; i < enable.size(); i++)
    {
        trace[depth + 1] = enable[i];
        bt(board, depth + 1, enable, i, cnt + 1);
    }
}

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<Point> enableB;
    vector<Point> enableW;
    trace = vector<Point>(n*n);

    vector<vector<bool>> black(n, vector<bool>(n, 0));
    
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < n; j += 2)
        {
            black[i][j] = true;
        }
    }

    for (int i = 1; i < n; i += 2)
    {
        for (int j = 1; j < n; j += 2)
        {
            black[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                if (black[i][j])
                    enableB.push_back({i, j});
                else
                    enableW.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < enableB.size(); i++)
    {
        trace[0] = enableB[i];
        bt(board, 0, enableB, i, 1);
    }
    int tmp = maxCnt;
    maxCnt = 0;
    for (int i = 0; i < enableW.size(); i++)
    {
        trace[0] = enableW[i];
        bt(board, 0, enableW, i, 1);
    }


    cout << maxCnt + tmp;
    

    return 0;
}