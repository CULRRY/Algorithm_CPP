#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> noSee;
    set<string> noSeeAndListen;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        noSee.insert(s);
    }
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;

        if (noSee.find(s) != noSee.end())
        {
            noSeeAndListen.insert(s);
        }
    }

    cout << noSeeAndListen.size() << "\n";
    for (string s: noSeeAndListen)
    {
        cout << s << "\n";
    }




    return 0;
}