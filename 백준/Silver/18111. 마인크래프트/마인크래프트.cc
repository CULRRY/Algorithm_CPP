#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, B;
    cin >> N >> M >> B;
    vector<vector<int>> v;
    v.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> v[i][j];
    }

    int max = 0, min = 257;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (v[i][j] > max)
                max = v[i][j];
            if (v[i][j] < min)
                min = v[i][j];
        }
    }

    int minTime = 2000000000;
    int maxFloor = 0;
    for (int floor = min; floor <= max; floor++)
    {
        int time = 0;
        int fillCost = 0;
        int pullCost = 0;
        int requiredBlock = 0;
        int inventory = B;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                int block = v[i][j] - floor;
                if (block < 0)
                {
                    fillCost -= block;
                    requiredBlock -= block;
                }
                else if (block > 0)
                {
                    pullCost += block;
                    inventory += block;
                }
            }
        }

        if (requiredBlock > inventory)
            continue;

        time = fillCost + pullCost * 2;

        if (minTime > time)
        {
            minTime = time;
            maxFloor = floor;
        }
        else if (minTime == time)
        {
            maxFloor = maxFloor > floor ? maxFloor : floor;
        }

    }

    cout << minTime << " " << maxFloor;

    return 0;
}