#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

enum
{
    N=0, S
};

enum
{
    L = -1,
    STOP = 0,
    R = 1
};

enum
{
    THREE = 2,
    NINE = 6,
    TWELVE = 0
};

void turn(string& chain, int d)
{

    if (d == L)
    {
        chain.push_back(chain[0]);
        chain.erase(0, 1);
    }
    else
    {
        chain.insert(0, 1, chain[7]);
        chain.pop_back();
    }
}


int main()
{
    FASTIO;

    vector<string> chains(5);

    for (int i = 1; i <= 4; i++)
        cin >> chains[i];

    int k;
    cin >> k;

    while (k--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> turns(5, STOP);
        turns[n] = d;

        int prev = d;
        
        for (int i = n-1; i >= 1; i--)
        {
            if (chains[i][THREE] != chains[i+1][NINE])
            {
                turns[i] = -prev;
                prev = -prev;
            }
            else
            {
                break;
            }
        }

        prev = d;
        for (int i = n + 1; i <= 4; i++)
        {
            if (chains[i-1][THREE] != chains[i][NINE])
            {
                turns[i] = -prev;
                prev = -prev;
            }
            else
            {
                break;
            }
        }

        for (int i = 1; i <= 4; i++)
        {
            if (turns[i] == STOP)
                continue;
            turn(chains[i], turns[i]);
        }

    }

    const vector<int> score = {0, 1, 2, 4, 8};
    int ans = 0;
    for (int i = 1; i <= 4; i++)
    {

        if (chains[i][TWELVE] - '0' == S)
            ans += score[i];
    }
    
    cout << ans << endl;

    return 0;
}