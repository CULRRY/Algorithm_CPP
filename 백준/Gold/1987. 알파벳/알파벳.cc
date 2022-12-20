#include <bits/stdc++.h>
using namespace std;
int r, c;
using vvc = vector<vector<char>>;

const vector<int> dx = {1, -1, 0, 0};
const vector<int> dy = {0, 0, 1, -1};
vector<char> memo(26);

bool isBound(int x, int y)
{
    if (x <= 0 || x > c)
        return false;
    if (y <= 0 || y > r)
        return false;
    
    return true;
}

int maxLen = 0;
vector<vector<bool>> visited;
void Alphabet(const vvc& board, int x, int y, int n)
{

    if (memo[board[y][x] - 'A'] == 1)
        return;

    if (n + 1> maxLen)
    {
        maxLen = n + 1;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isBound(nx, ny) && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            memo[board[y][x] - 'A'] = 1;
            Alphabet(board, nx, ny, n+1);
            visited[ny][nx] = false;
            memo[board[y][x] - 'A'] = 0;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> r >> c;

    vvc board(r+1, vector<char>(c+1));
    visited.assign(r+1, vector<bool>(c+1, false));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> board[i][j];
        }
    }

    Alphabet(board, 1, 1, 0);

    cout << maxLen;


    return 0;
}