#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int y, x;
};
int N, M;
vector<Point> chicken;
vector<Point> house;
vector<Point> selected;
int minChicDis = INT_MAX;
void ChickenDistance(int depth, int cs)
{
    if (depth > M)
        return;

    if (depth == 0)
    {
    }
    else
    {
        int total = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int min = INT_MAX;
            for (int j = 0; j < depth; j++)
            {
                min = std::min(abs(house[i].y - selected[j].y) + abs(house[i].x - selected[j].x), min);
            }
            total += min;
        }

        if (total < minChicDis)
            minChicDis = total;
    }

    for (int i = cs + 1; i < chicken.size(); i++)
    {
        selected[depth] = chicken[i];
        ChickenDistance(depth + 1, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    selected.assign(M + 1, {0, 0});
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;
            if (x == 2)
            {
                chicken.push_back({i, j});
            }

            if (x == 1)
            {
                house.push_back({i, j});
            }
        }
    }

    ChickenDistance(0, -1);

    cout << minChicDis << "\n";

    return 0;
}