#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    map<string, string> bookByName;
    map<string, string> bookByNum;

    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        bookByName[s] = to_string(i);
        bookByNum[to_string(i)] = s;
    }

    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        auto it = bookByName.find(s);
        if (it != bookByName.end())
        {
            cout << it->second << "\n";
        }
        else
        {
            it = bookByNum.find(s);
            cout << it->second << "\n";
        }
    }

    return 0;
}