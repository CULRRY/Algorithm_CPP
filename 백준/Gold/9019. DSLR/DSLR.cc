#include <bits/stdc++.h>
using namespace std;
inline int D(int n)
{
    return (2 * n) % 10000;
}

inline int S(int n)
{
    return n == 0 ? 9999 : n - 1;
}

inline int L(int n)
{
    return (n % 1000) * 10 + (n / 1000);
}

inline int R(int n)
{
    return (n / 10) + (n % 10) * 1000;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<string> memo(10000, "");
        vector<bool> discoverd;
        discoverd.assign(10000, 0);

        int start, target;
        cin >> start >> target;

        queue<pair<int, string>> q;
        q.push(make_pair(start, ""));

        while (!q.empty())
        {

                int now = q.front().first;
                string cmd = q.front().second;
                memo[now] = cmd;
                q.pop();

                if (now == target)
                    break;


                if (!discoverd[D(now)] && now != 0)
                {
                    q.push(make_pair(D(now), cmd + 'D'));
                    discoverd[D(now)] = true;
                }
                if (!discoverd[S(now)])
                {
                    q.push(make_pair(S(now), cmd + 'S'));
                    discoverd[S(now)] = true;
                }
                if (!discoverd[L(now)])
                {
                    q.push(make_pair(L(now), cmd + 'L'));
                    discoverd[L(now)] = true;
                }
                if (!discoverd[R(now)])
                {
                    q.push(make_pair(R(now), cmd + 'R'));
                    discoverd[R(now)] = true;
                }

        }

        cout << memo[target] << "\n";
    }

    return 0;
}