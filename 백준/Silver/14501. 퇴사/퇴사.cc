#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

struct Consult
{
    int t, p;
};

int n;
int ans = 0;
vector<Consult> consults;

void bt(int days, int sum, int price)
{

    if (days <= n)
        sum += price;

    if (days >= n)
    {
        ans = std::max(ans, sum);
        return;
    }

    

    bt(days + consults[days].t, sum, consults[days].p);
    bt(days + 1, sum, 0);
}

int main()
{
    FASTIO;

    cin >> n;
    consults = vector<Consult>(n);

    for (Consult& c : consults)
        cin >> c.t >> c.p;
    
    bt(0, 0, 0);

    cout << ans << endl;
    return 0;
}