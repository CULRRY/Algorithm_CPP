#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int n, k;
int points[200001] = {0, };
bool discoverd[200001] = {false, };
int parents[200001] = {-1, };
bool Check(int next)
{
    if (next > 200000)
        return false;
    
    if (next < 0)
        return false;

    if (discoverd[next] == true)
        return false;
    
    return true;
}

void print(int now)
{
    
    if (now == -1)
        return;

    print(parents[now]);

    cout << now << " ";
    
}

void bfs()
{
    queue<int> q;
    discoverd[n] = true;

    q.push(n);
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int now = q.front();
            q.pop();

            if (now == k)
            {
                cout << cnt << endl;
                
                print(k);
                
                return;
            }

            int next;
            next = now + 1;
            if (Check(next))
            {
                parents[next] = now;
                q.push(next);
                discoverd[next] = true;
            }

            next = now - 1;
            if (Check(next))
            {
                parents[next] = now;
                q.push(next);
                discoverd[next] = true;
            }

            next = now * 2;
            if (Check(next))
            {
                parents[next] = now;
                q.push(next);
                discoverd[next] = true;
            }
        }

        cnt++;
        
    }
    

}


int main()
{
    FASTIO;

    cin >> n >> k;
    memset(parents, -1, sizeof(parents));
    bfs();

    return 0;
}