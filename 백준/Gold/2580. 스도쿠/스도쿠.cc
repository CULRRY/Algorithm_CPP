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
vector<vector<int>> sudoku;
vector<Point> zero;
int zeroCnt = 0;

void bt(int idx, int n, int cnt)
{
    if (cnt == 0)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
        return;
    }
    int y = zero[idx].y;
    int x = zero[idx].x;

    for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++)
    {
        for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++)
        {
            if (sudoku[i][j] == n)
                return;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (sudoku[y][i] == n)
            return;
        
        if (sudoku[i][x] == n)
            return;
    }

    sudoku[y][x] = n;
    for (int p = 1; p <= 9; p++)
    {
        bt(idx + 1, p, cnt - 1);
    }
    sudoku[y][x] = 0;
}


int main()
{
    FASTIO;

    sudoku = vector<vector<int>>(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
            {
                zero.push_back({i, j});
                zeroCnt++;
            }

        }
    }

    for (int p = 1; p <= 9; p++)
    {
        bt(0, p, zeroCnt);
    }

    return 0;
}