#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, string> m;
    for (int i = 0; i < N; i++)
    {
        string address, password;
        cin >> address >> password;

        m[address] = password;
    }

    for (int i = 0; i < M; i++)
    {
        string address;
        cin >> address;

        auto it = m.find(address);
        cout << it->second << "\n";
    }

    return 0;
}