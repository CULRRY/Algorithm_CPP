#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;
int l, c;
vector<bool> isUsed;
vector<bool> isMoum;
vector<char> alpha;
bool checkMoum(char c)
{
    string moum = "aeiou";

    if (moum.find(c) != EOF)
        return true;
    else
        return false;

}

void bt(int depth, int idx, string pass, int moum, int zaum)
{
    if (depth == l)
    {
        if (moum >= 1 && zaum >= 2)
            cout << pass << endl;
        return;
    }

    for (int i = idx + 1; i < c; i++)
    {
        if (isMoum[i])
        {
            bt(depth + 1, i, pass + alpha[i], moum + 1, zaum);
        }
        else
        {
            bt(depth + 1, i, pass + alpha[i], moum, zaum + 1);
        }
    }
}

int main()
{
    FASTIO;


    cin >> l >> c;

    alpha = vector<char>(c);
    isUsed = vector<bool>(c, false);
    isMoum = vector<bool>(c, false);

    for (int i = 0; i < c; i++)
    {
        cin >> alpha[i];
    }

    sort(alpha.begin(), alpha.end());

    for (int i = 0; i < c; i++)
    {
        if (checkMoum(alpha[i]))
            isMoum[i] = true;
    }

    bt(0, -1, "", 0, 0);

    return 0;
}