#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, k;

vector<int> arr;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void adjust(vector<vector<int>>& board, int r, int c)
{
    vector<vector<int>> tmp = board;
    vector<vector<int>> visited(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 0)
                continue;
            
            visited[i][j] = true;
            for (int d = 0; d < 4; d++)
            {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                    continue;
                if (visited[ny][nx] == true)
                    continue;
                if (board[ny][nx] == 0)
                    continue;
                
                if (board[i][j] >= board[ny][nx])
                {
                    int gap = (board[i][j] - board[ny][nx]) / 5;
                    tmp[i][j] -= gap;
                    tmp[ny][nx] += gap;
                }
                else
                {
                    int gap = (board[ny][nx] - board[i][j]) / 5;
                    tmp[i][j] += gap;
                    tmp[ny][nx] -= gap;
                }
                

            }
        }
    }

    board = tmp;
}

bool arrange()
{
    int minValue = *min_element(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == minValue)
            arr[i]++;
    }
    int tr = 1, tc = 1;
    int ac = n-1;
    vector<vector<int>> left(tr, vector<int>(tc, arr[0]));
    vector<int> right(ac);
    for (int i = 1; i < n; i++)
        right[i-1] = arr[i];
    
    while (true)
    {
        vector<vector<int>> tmp(tc+1, vector<int>(tr));
        for (int i = 0; i < tr; i++)
        {
            for (int j = 0; j < tc; j++)
            {
                tmp[j][tr - i - 1] = left[i][j];
            }
        }


        for (int i = 0; i < tr; i++)
        {
            tmp[tc][i] = right[i];
        }
        ac -= tr;
        if (ac < 0)
        {
            ac += tr;
            break;
        }
        vector<int> tmp2(ac);
        for (int i = 0; i < ac; i++)
        {
            tmp2[i] = right[i + tr];
        }
        int t = tr;
        tr = tc + 1;
        tc = t;
        left = tmp;
        right = tmp2;
    }

    vector<vector<int>> board(tr, vector<int>(tc + ac, 0));

    for (int i = 0; i < tr; i++)
    {
        for (int j = 0; j < tc; j++)
        {
            board[i][j] = left[i][j];
        }
    }

    for (int i = 0; i < ac; i++)
    {
        board[tr-1][tc + i] = right[i];
    }

    adjust(board, tr, tc + ac);

    arr = vector<int>(n, 0);
    int idx = 0;
    for (int j = 0; j < tc + ac; j++)
    {
        for (int i = tr - 1; i >= 0; i--)
        {
            if (board[i][j] == 0)
                continue;
            arr[idx++] = board[i][j];
        }
    }

    //---------------------------------------------//
    {
        int r = 1;
        int lc = n / 2;
        int rc = n / 2;

        vector<vector<int>> left2;
        vector<vector<int>> right2;
        vector<vector<int>> board2;
        left2 = vector<vector<int>>(r, vector<int>(lc, 0));
        right2 = vector<vector<int>>(r, vector<int>(rc, 0));
        board2 = vector<vector<int>>(r, vector<int>(lc + rc, 0));

        for (int i = 0; i < n; i++)
            board2[0][i] = arr[i];

        for (int k = 0; k < 2; k++)
        {
            left2 = vector<vector<int>>(r, vector<int>(lc, 0));
            right2 = vector<vector<int>>(r, vector<int>(rc, 0));
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < lc; j++)
                {
                    left2[i][j] = board2[i][j];
                }
            }

            for (int i = 0; i < r; i++)
            {
                for (int j = lc; j < lc + rc; j++)
                {
                    right2[i][j-lc] = board2[i][j];
                }
            }

            vector<vector<int>> tmpL(r, vector<int>(lc));
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < lc; j++)
                {
                    tmpL[r - i - 1][lc - j - 1] = left2[i][j];
                }
            }
            left2 = tmpL;

            board2 = vector<vector<int>>(r + r, vector<int>(lc, 0));
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < lc; j++)
                {
                    board2[i][j] = left2[i][j];
                }
            }
            for (int i = r; i < r + r; i++)
            {
                for (int j = 0; j < rc; j++)
                {
                    board2[i][j] = right2[i-r][j];
                }
            }
            if (k == 1)
                break;

            r += r;
            lc /= 2;
            rc /= 2;
        }

        adjust(board2, r + r, lc);

        arr = vector<int>(n, 0);
        int idx = 0;
        for (int j = 0; j < lc; j++)
        {
            for (int i = r + r- 1; i >= 0; i--)
            {
                if (board2[i][j] == 0)
                    continue;
                arr[idx++] = board2[i][j];
            }
        }
    }
    
    int m = *min_element(arr.begin(), arr.end());
    int M = *max_element(arr.begin(), arr.end());
    if (M - m <= k)
        return true;
    return false;
}  

int main()
{
    FASTIO;

    cin >> n >> k;

    arr = vector<int>(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    while (true)
    {
        ans++;
        if (arrange())
            break;
    }
    
    cout << ans;

    return 0;
}