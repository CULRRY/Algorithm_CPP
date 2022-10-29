#include <bits/stdc++.h>
using namespace std;

void check(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            count++;
        }
        else
            count--;
        
        if (count < 0)
        {
            cout << "NO" << "\n";
            return;
        }
    }
    if (count == 0)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; 
    string s;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        check(s);
    }


    return 0;
}