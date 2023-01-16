#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

struct Lecture
{
    int p, d;
};

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<Lecture> lecs;
    for (int i = 0; i < n; i++)
    {
        int p, d;
        cin >> p >> d;
        lecs.push_back({p, d});
    }

    sort(lecs.begin(), lecs.end(), [](Lecture& r1, Lecture& r2) { return r1.p > r2.p;});

    vector<int> hash(10001, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int day = lecs[i].d;
        int price = lecs[i].p;

        while (hash[day] != 0 && day != 0)
        {
            day--;
        }
        if (day == 0)
            continue;
        hash[day] = price; 
        ans += price;    
    }

    cout << ans;
    

    return 0;
}