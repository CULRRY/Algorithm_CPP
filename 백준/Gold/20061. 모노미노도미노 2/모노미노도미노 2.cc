#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;
vector<vector<int>> blue;
vector<vector<int>> green;
vector<int> dx = {0, 0, 0, 1};
vector<int> dy = {0, 0, 1, 0};

int score = 0;

void move_blue(int t, int sx, int sy)
{
    for (int y = 0; y < 6; y++)
    {

        if (blue[sx][y + 1] == 1 || blue[sx + dx[t]][y + dy[t] + 1] == 1)
        {
            blue[sx][y] = 1;
            blue[sx + dx[t]][y + dy[t]] = 1;

            

            // 완성된 열 찾기
            vector<int> complete;
            for (int ty = 0; ty < 6; ty++)
            {
                bool flag = true;
                for (int tx = 0; tx < 4; tx++)
                {
                    if (blue[tx][ty] == 0)
                        flag = false;
                }

                if (flag == true)
                {
                    complete.push_back(ty);
                    score++;
                }
            }

            complete.push_back(9);

            vector<vector<int>> tmp(4, vector<int>(7, 0));
            int gap = complete.size() - 1;
            int comIdx = 0;
            for (int ty = 0; ty < 6; ty++)
            {
                if (ty == complete[comIdx])
                {
                    gap--;
                    comIdx++;
                    continue;
                }

                for (int tx = 0; tx < 4; tx++)
                {
                    tmp[tx][ty + gap] = blue[tx][ty];
                }
            }

            int back = 0;
            if (tmp[sx][0] == 1)
                back++;
            if (tmp[sx][1] == 1)
                back++;

            vector<vector<int>> tmp2(4, vector<int>(7, 0));

            // 0, 1번열에 있는 칸 갯수만큼 뒤로밀기
            for (int ty = 5 - back; ty >= 0; ty--)
            {
                for (int tx = 0; tx < 4; tx++)
                {
                    tmp2[tx][ty + back] = tmp[tx][ty];
                }
            }
            
            blue = tmp2;
            for (int i = 0; i < 4; i++)
            {
                blue[i][6] = 1;
            }

            break;
        }
    }
}

void move_green(int t, int sx, int sy)
{
    for (int x = 0; x < 6; x++)
    {

        if (green[x + 1][sy] == 1 || green[x + dx[t] + 1][sy + dy[t]] == 1)
        {
            green[x][sy] = 1;
            green[x + dx[t]][sy + dy[t]] = 1;


           

            // 완성된 열 찾기
            vector<int> complete;
            for (int tx = 0; tx < 6; tx++)
            {
                bool flag = true;
                for (int ty = 0; ty < 4; ty++)
                {
                    if (green[tx][ty] == 0)
                        flag = false;
                }

                if (flag == true)
                {
                    complete.push_back(tx);
                    score++;
                }
            }

            complete.push_back(9);

            vector<vector<int>> tmp(7, vector<int>(4, 0));
            int gap = complete.size() - 1;
            int comIdx = 0;
            for (int tx = 0; tx < 6; tx++)
            {
                if (tx == complete[comIdx])
                {
                    gap--;
                    comIdx++;
                    continue;
                }

                for (int ty = 0; ty < 4; ty++)
                {
                    tmp[tx + gap][ty] = green[tx][ty];
                }
            }

            vector<vector<int>> tmp2(7, vector<int>(4, 0));
            int back = 0;
            if (tmp[0][sy] == 1)
                back++;
            if (tmp[1][sy] == 1)
                back++;

            // 0, 1번열에 있는 칸 갯수만큼 뒤로밀기
            for (int tx = 5 - back; tx >= 0; tx--)
            {
                for (int ty = 0; ty < 4; ty++)
                {
                    tmp2[tx + back][ty] = tmp[tx][ty];
                }
            }

            green = tmp2;
            for (int i = 0; i < 4; i++)
            {
                green[6][i] = 1;
            }

            break;
        }
    }
}

int main()
{
    FASTIO;

    int n;
    cin >> n;
    blue = vector<vector<int>>(4, vector<int>(7, 0));
    green = vector<vector<int>>(7, vector<int>(4, 0));

    for (int i = 0; i < 4; i++)
    {
        blue[i][6] = 1;
        green[6][i] = 1;
    }

    while (n--)
    {
        int t, x, y;
        cin >> t >> x >> y;

        move_blue(t, x, y);
        move_green(t, x, y);
    }

    cout << score << endl;

    int cnt = 0;

    for (int x = 0; x < 6; x++)
        for (int y = 0; y < 4; y++)
        {
            if (green[x][y] == 1)
                cnt++;
        }

    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 6; y++)
        {
            if (blue[x][y] == 1)
                cnt++;
        }

    cout << cnt << endl;
    return 0;
}