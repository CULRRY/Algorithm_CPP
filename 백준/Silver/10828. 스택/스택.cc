#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int _size = 0;
    int _top = -1;
    int _s[10000];
} Stack;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string cmd;
    cin >> N;
    Stack s;
    for (int i = 0; i < N; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            int v;
            cin >> v;
            s._top++;
            s._size++;
            s._s[s._top] = v;
        }
        else if (cmd == "pop")
        {
            if (s._size == 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << s._s[s._top] << "\n";
                s._top--;
                s._size--;
            }
        }
        else if (cmd == "size")
        {
            cout << s._size << "\n";
        }
        else if (cmd == "empty")
        {
            if (s._size == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else
        {
            if (s._size == 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << s._s[s._top] << "\n";
            }
        }
    }

    return 0;
}