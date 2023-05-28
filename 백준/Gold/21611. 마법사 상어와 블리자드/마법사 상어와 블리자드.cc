#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> board;

int score = 0;

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, -1, 1, 0, 0};

void flat(vector<int> &arr)
{
    const vector<int> r = {3, 2, 4, 1};
    int idx = 0;
    int y = n / 2;
    int x = n / 2;
    int di = 0;
    int d = r[di];

    for (int dist = 1; dist <= n; dist++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < dist; i++)
            {
                y = y + dy[d];
                x = x + dx[d];
                arr[idx++] = board[y][x];
                if (y == 0 && x == 0)
                    return;
            }
            di = (di + 1) % 4;
            d = r[di];
        }
    }
}

void snail(vector<int> &arr)
{
    const vector<int> r = {3, 2, 4, 1};
    int idx = 0;
    int y = n / 2;
    int x = n / 2;
    int di = 0;
    int d = r[di];
    board = vector<vector<int>>(n, vector<int>(n, 0));
    for (int dist = 1; dist <= n; dist++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < dist; i++)
            {
                y = y + dy[d];
                x = x + dx[d];
                board[y][x] = arr[idx++];
                if (y == 0 && x == 0)
                    return;
            }
            di = (di + 1) % 4;
            d = r[di];
        }
    }
}

void move(vector<int> &arr)
{
    vector<int> tmp(n * n - 1, 0);
    int idx = 0;
    for (int i : arr)
    {
        if (i != 0)
            tmp[idx++] = i;
    }

    arr = tmp;
}

bool boom(vector<int> &arr)
{
    bool ret = false;
    int color = arr[0];
    if (color == 0)
        return ret;

    int start = 0;
    int end = 0;
    int cnt = 0;
    for (int i = 0; i <= arr.size(); i++)
    {
        if (i == arr.size())
        {
            if (cnt >= 4)
            {
                score += color * cnt;
                ret = true;
                for (int j = start; j <= end; j++)
                {
                    arr[j] = 0;
                }
            }
            continue;
        }
        if (arr[i] == color)
        {
            end = i;
            cnt++;
        }
        else
        {
            if (cnt >= 4)
            {
                score += color * cnt;
                ret = true;
                for (int j = start; j <= end; j++)
                {
                    arr[j] = 0;
                }
            }
            cnt = 1;
            start = i;
            end = i;
            color = arr[i];
            if (color == 0)
                break;
        }
    }

    return ret;
}

void group(vector<int> &arr)
{
    int cnt = 0;
    int color = arr[0];
    if (color == 0)
        return;
    vector<int> groups;
    for (int i = 0; i <= arr.size(); i++)
    {
        if (i == arr.size())
        {
            groups.push_back(cnt);
            groups.push_back(color);
            continue;
        }
        if (arr[i] == color)
        {
            cnt++;
        }
        else
        {
            groups.push_back(cnt);
            groups.push_back(color);
            color = arr[i];
            cnt = 1;
            if (color == 0)
                break;
        }

    }

    vector<int> tmp(n * n - 1, 0);

    for (int i = 0; i < tmp.size(); i++)
    {
        if (i >= groups.size())
            break;

        tmp[i] = groups[i];
    }

    arr = tmp;
}

void skill(int d, int s)
{

    int y = n / 2;
    int x = n / 2;
    for (int i = 0; i < s; i++)
    {
        y = y + dy[d];
        x = x + dx[d];
        if (y < 0 || y >= n || x < 0 || x >= n)
            break;
        board[y][x] = 0;
    }

    vector<int> arr(n * n - 1, 0);
    flat(arr);
    move(arr);
    while (boom(arr))
    {
        move(arr);
    };
    group(arr);
    snail(arr);
}

int main()
{
    FASTIO;

    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    while (m--)
    {
        int d, s;
        cin >> d >> s;

        skill(d, s);
    }

    cout << score << endl;
    return 0;
}