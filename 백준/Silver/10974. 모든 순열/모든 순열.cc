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

    vector<int> perm(n, 0);
    std::iota(perm.begin(), perm.end(), 1);

    do
    {
        for (int i : perm)
        {
            cout << i << " ";
        }

        cout << endl;
    } while (next_permutation(perm.begin(), perm.end()));

    return 0;
}