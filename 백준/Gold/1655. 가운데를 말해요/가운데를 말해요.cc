#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> maxpq;
    priority_queue<int> minpq;

    int mid;
    cin >> mid;
    n--;
    minpq.push(mid);
    cout << mid << endl;
    while (n--)
    {
        int i;
        cin >> i;

        if (i > mid)
        {
            maxpq.push(i);
        }
        else
        { 
            minpq.push(i);
        }

        if (maxpq.size() > minpq.size())
        {
            int tmp = maxpq.top();
            maxpq.pop();
            minpq.push(tmp);
        }
        else if (minpq.size() - maxpq.size() >= 2)
        {
            int tmp = minpq.top();
            minpq.pop();
            maxpq.push(tmp);
        }

        mid = minpq.top();
        cout << mid << endl;

    }
    

    return 0;
}