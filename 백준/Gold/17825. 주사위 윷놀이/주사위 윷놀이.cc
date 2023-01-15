#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
struct horse
{
    int now, d;
};

void move(horse& h)
{
    int& now = h.now;
    int& dir = h.d;
    if (now == 40)
    {
        now = -1;
        dir = -1;
        return;
    }
    
    if (now == 25)
        dir = UP;

    if (now == 19)
    {
        now = 25;
        return;
    }
    
    if (now == 24 && dir == UP)
    {
        now = 25;
        return;
    }
////////////////////////////////////
    if (dir == DOWN)
    {
        now += 2;
        return;
    }
    
    if (dir == UP)
    {
        if (now >= 25)
        {
            now += 5;
            return;
        }

        now += 2;
        return;
    }

    if (dir == RIGHT)
    {
        now += 3;
        return;
    }

    if (dir == LEFT)
    {
        if (now == 30)
        {
            now -= 2;
            return;
        }
        now -= 1;
        return; 
    }


}


vector<horse> horses(4, {0, DOWN});
vector<int> nums(10);
int ans = 0;
void bt(vector<horse> horses, int sum, int depth)
{
    if (depth == 10)
    {
        ans = std::max(ans, sum);
        return;
    }

    int moveCount = nums[depth];
    vector<horse> tmp(horses);
    for (int i = 0; i < 4; i++)
    {
        if (horses[i].now == -1)
            continue;
        for (int j = 0; j < moveCount; j++)
        {

               move(tmp[i]);
               if (tmp[i].now == -1)
               {
                    break;
               }
        }

        if (tmp[i].now == 10)
        {
               tmp[i].d = RIGHT;
        }

        if (tmp[i].now == 20)
        {
               tmp[i].d = UP;
        }

        if (tmp[i].now == 30 && tmp[i].d == DOWN)
        {
               tmp[i].d = LEFT;
        }

        if (tmp[i].now == 25)
            tmp[i].d = UP;

        if (tmp[i].now == 40)
        {
            tmp[i].d = -1;
        }

        bool canMove = true;
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
                continue;
            if (tmp[j].now == -1)
                continue;
            if (tmp[i].now == tmp[j].now && tmp[i].d == tmp[j].d)
                canMove = false;

        }

        if (canMove)
        {
            if (tmp[i].now == -1)
            {
                bt(tmp, sum, depth+1);
            }
            else
                bt(tmp, sum + tmp[i].now, depth+1);
        }
        tmp[i] = horses[i];

    }

    

}

int main()
{
    FASTIO;

    for (int i = 0; i < 10; i++)
    {
        cin >> nums[i];
    }

    bt(horses, 0, 0);

    cout << ans << endl;
    return 0;
}