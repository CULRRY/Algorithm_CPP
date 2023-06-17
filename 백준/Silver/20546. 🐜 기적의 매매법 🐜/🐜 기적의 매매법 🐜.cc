#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int a;
    int b;
    cin >> a;
    b = a;

    vector<int> history(14, 0);

    for (int& i : history)
        cin >> i;

    int cnt = 0;
    for (int i = 0; i < 14; i++)
    {
        if (history[i] <= a)
        {
            cnt = a / history[i];
            a = a % history[i];
            break;
        }
    }

    a = history[13] * cnt + a;

    cnt = 0;
    int stku = 0;
    int stkd = 0;
    for (int i = 1; i < 14; i++)
    {

        if (history[i - 1] > history[i])
        {
            stku++;
            stkd = 0;
        }

        if (history[i - 1] == history[i])
        {
            stku = 0;
            stkd = 0;
        }

        if (history[i - 1] < history[i])
        {
            stkd++;
            stku = 0;
        }
        
        if (stku >= 3)
        {
            if (history[i] <= b)
            {
                cnt += b / history[i];
                b = b % history[i];
                continue;
            }
        }

        if (stkd >= 3)
        {
            b = history[i] * cnt + b;
            cnt = 0;
            continue;
        }
    }

    b = history[13] * cnt + b;

    if (a == b)
        cout << "SAMESAME";
    else if (a > b)
        cout << "BNP";
    else
        cout << "TIMING";

    return 0;
}