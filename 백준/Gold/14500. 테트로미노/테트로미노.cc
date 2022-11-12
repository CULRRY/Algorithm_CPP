#include <bits/stdc++.h>
using namespace std;
struct pos
{
    int y, x;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pos> case1 = {{0, -1}, {0, 1}, {1, -1}, {1, 1}};
    vector<pos> case2 = {{-1, 0}, {1, 0}, {-1, 1}, {1, 1}};

    vector<vector<int>> v;
    v.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
    }
    int max = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 1; j < M - 1; j++)
        {
            int sum = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = 0; l <= 1; l++)
                {
                    sum += v[i + l][j + k];
                }
            }

            for (int k = 0; k < case1.size(); k++)
            {
                for (int l = k + 1; l < case1.size(); l++)
                {
                    int tmp = sum;
                    tmp -= (v[i + case1[k].y][j + case1[k].x]) + (v[i + case1[l].y][j + case1[l].x]);
                    if (tmp > max)
                        max = tmp;
                }
            }

            for (int k = 0; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l += 2)
                {
                    int tmp = sum;
                    tmp -= v[i + k][j] + v[i + k][j + l];
                    if (tmp > max)
                        max = tmp;
                }
            }
        }
    }

    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 0; j < M - 1; j++)
        {
            int sum = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = 0; l <= 1; l++)
                {
                    sum += v[i + k][j + l];
                }
            }

            for (int k = 0; k < case1.size(); k++)
            {
                for (int l = k + 1; l < case1.size(); l++)
                {
                    int tmp = sum;
                    tmp -= (v[i + case2[k].y][j + case2[k].x]) + (v[i + case2[l].y][j + case2[l].x]);
                    if (tmp > max)
                        max = tmp;
                }
            }

            for (int k = 0; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l += 2)
                {
                    int tmp = sum;
                    tmp -= v[i + l][j + k] + v[i][j + k];
                    if (tmp > max)
                        max = tmp;
                }
            }
        }
    }

    for (int i = 0; i < N - 3; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int sum = 0;
            for (int k = 0; k < 4; k++)
            {
                sum += v[i+k][j];
            }

            if (sum > max)
                max = sum;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M - 3; j++)
        {
            int sum = 0;
            for (int k = 0; k < 4; k++)
            {
                sum += v[i][j + k];
            }

            if (sum > max)
                max = sum;
        }
    }
    cout << max << "\n";

    return 0;
}