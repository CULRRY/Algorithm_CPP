#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    vector<int> v(21, 0);
    for (int i = 0; i < M; i++)
    {
        string cmd;
        int x;
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> x;
            v[x] = 1;

        }
        else if (cmd == "remove")
        {
            cin >> x;
            v[x] = 0;
        }
        else if (cmd == "check")
        {
            cin >> x;
            if (v[x] == 1)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (cmd == "toggle")
        {
            cin >> x;
            if (v[x] == 1)
                v[x] = 0;
            else
                v[x] = 1;
        }
        else if (cmd == "all")
        {
            v.assign(21, 1);
        }
        else
        {
            v.assign(21, 0);
        }
    }

    return 0;
}