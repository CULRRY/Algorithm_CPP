#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

struct Egg
{
    int s, w;
};

int n;
vector<Egg> eggs;
int ans = 0;

void bt(int depth)
{
    if (depth == n)
    {
        int destroy = 0;
        for (Egg egg : eggs)
        {
            if (egg.s <= 0)
                destroy++;
        }

        ans = std::max(ans, destroy);
        return;
    }

    if (eggs[depth].s <= 0)
    {
        bt(depth + 1);
    } 
    else
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (i == depth)
                continue;

            if (eggs[i].s <= 0)
                continue;

            flag = false;
            eggs[depth].s -= eggs[i].w;
            eggs[i].s -= eggs[depth].w;

            bt(depth + 1);

            eggs[depth].s += eggs[i].w;
            eggs[i].s += eggs[depth].w;
        }
        if (flag)
            bt(depth + 1);
    }
}

int main()
{
    FASTIO;

    cin >> n; 
    eggs = vector<Egg>(n);

    for (int i = 0; i < n; i++)
    {
        cin >> eggs[i].s >> eggs[i].w;
    }

    bt(0);
    cout << ans << endl;

    return 0;
}