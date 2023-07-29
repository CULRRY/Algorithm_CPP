#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;
vector<int> prime(10000);
int origin, target;
int ans;
bool flag = false;

int bfs()
{
    queue<int> q;
    vector<bool> discovered(10000, false);
    q.push(origin);
    discovered[origin] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();

        while (sz--)
        {
            int now = q.front();
            q.pop();
            if (now == target)
                return cnt;

            string strnow = to_string(now);

            for (int i = 0; i < 4; i++)
            {
                string next = strnow;

                for (int j = 0; j <= 9; j++)
                {
                    if (strnow[i]-'0' == j)
                        continue;
                    
                    next[i] = j + '0';
                    int inext = stoi(next);
                    if (inext < 1000)
                        continue;
                    
                    if (prime[inext] == 0)
                        continue;
                    
                    if (discovered[inext] == true)
                        continue;

                    q.push(inext);
                    discovered[inext] = true;
                }
            }
        }

        cnt++;
    }
    
    return -1;

}


int main()
{
    FASTIO;


    std::iota(prime.begin(), prime.end(), 0);

    for (int i = 2; i < 10000; i++)
    {
        if (prime[i] == 0)
            continue;
        
        for (int j = i * 2; j < 10000; j += i)
        {
            prime[j] = 0;
        }
    }

    int tc;
    cin >> tc;

    while (tc--)
    {
        cin >> origin >> target;

        int ans = bfs();

        if (ans == -1)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;

    }
    

    return 0;
}