#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> board;


void triangle(int n, int center, int y)
{
    if (n == 3)
    {
        board[y][center] = '*';
        board[y+1][center-1] = board[y+1][center+1] = '*';
        for (int i = center-2; i <= center+2; i++)
        {
            board[y+2][i] = '*';
        }

        return;
    }



    int newCenter = center;
    triangle(n / 2, newCenter, y);
    newCenter = center - n / 2;
    triangle(n / 2, newCenter, y + n / 2);
    newCenter = center + n / 2;
    triangle(n / 2, newCenter, y + n / 2);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    board.assign(n, vector<char>(2*n, ' '));

    triangle(n, n-1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }


    return 0;
} 