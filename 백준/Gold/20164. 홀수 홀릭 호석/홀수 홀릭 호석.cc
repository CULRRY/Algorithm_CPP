#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int maxa = INT_MIN;
int mina = INT_MAX;

void recur(string number, int cnt)
{
    for (char c : number)
    {
        if ((c - '0') % 2 == 1)
            cnt++;
    }

    if (number.size() == 1)
    {
        maxa = std::max(cnt, maxa);
        mina = std::min(cnt, mina);
        return;
    }
    else if (number.size() == 2)
    {
        string param = to_string(number[0] - '0' + number[1] - '0');
        recur(param, cnt);
    }
    else
    {
        string s1, s2, s3;
        for (int i = 1; i < number.size() - 1; i++)
        {
            for (int j = i + 1; j < number.size(); j++)
            {
                s1 = number.substr(0, i);
                s2 = number.substr(i, j-i);
                s3 = number.substr(j, number.size() - j);

                string param = to_string(stoi(s1) + stoi(s2) + stoi(s3));
                recur(param, cnt);
            }
        }
    }
}

int main()
{
    FASTIO;

    string n;
    cin >> n;

    recur(n, 0);

    cout << mina << " " << maxa << endl;
    return 0;
}