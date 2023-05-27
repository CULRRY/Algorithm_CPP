#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

struct Student
{
    int y, x;
    vector<int> favorite;
};

struct Point
{
    int y, x;
};

vector<Student> s;
vector<vector<int>> table;
vector<int> seq;
int n;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void Choose(int num)
{
    vector<vector<int>> con1(n+1, vector<int>(n+1, 0));
    for (int c : s[num].favorite)
    {
        if (s[c].y == 0)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int ny = s[c].y + dy[i];
            int nx = s[c].x + dx[i];
            if (ny <= 0 || ny > n || nx <= 0 || nx > n)
                continue;
            if (table[ny][nx] != 0)
                continue;
            con1[ny][nx]++;
        }
    }

    int maxValue = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            maxValue = std::max(maxValue, con1[i][j]);
        }
    }

    vector<vector<int>> con2(n + 1, vector<int>(n + 1, 0));

    int maxCount = -1;
    int cy, cx;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (table[i][j] != 0)
                continue;
            if (con1[i][j] < maxValue)
                continue;
            int cnt = 0;
            for (int d = 0; d < 4; d++)
            {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if (ny <= 0 || ny > n || nx <= 0 || nx > n)
                    continue;
                if (table[ny][nx] == 0)
                    cnt++;
            }

            if (cnt > maxCount)
            {
                cy = i, cx = j;
                maxCount = cnt;
            }
        }
    }

    table[cy][cx] = num;
    s[num].y = cy; s[num].x = cx;
}

int main()
{
    FASTIO;
    cin >> n;
    table = vector<vector<int>>(n+1, vector<int>(n+1, 0));
    s = vector<Student>(n*n + 1);
    for (int i = 1; i <= n*n; i++)
    {
        int r;
        cin >> r;
        seq.push_back(r);
        s[r] = {0, 0, vector<int>(4)};
        for (int j = 0; j < 4; j++)
            cin >> s[r].favorite[j];
    }

    for (int r : seq)
    {
        Choose(r);
    }

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num = table[i][j];
            int cnt = 0;
            for (int d = 0; d < 4; d++)
            {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if (ny <= 0 || ny > n || nx <= 0 || nx > n)
                    continue;
                for (int op : s[num].favorite)
                {
                    if (op == table[ny][nx])
                        cnt++;
                }
            }
            int plus = 0;
            switch (cnt)
            {
            case 0:
                plus = 0;
                break;
            case 1:
                plus = 1;
                break;
            case 2:
                plus = 10;
                break;
            case 3:
                plus = 100;
                break;
            case 4:
                plus = 1000;
                break;
            default:
                break;
            }

            sum += plus;
        }
    }

    cout << sum;
    return 0;
}