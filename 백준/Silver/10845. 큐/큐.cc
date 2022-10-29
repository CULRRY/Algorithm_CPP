#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int q[MAX];
int _size = 0;
int _front = 0;
int _back = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string cmd;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            int v;
            cin >> v;
            q[_back] = v;
            _back = (_back + 1) % MAX;
            _size++;
        }
        else if (cmd == "pop")
        {
            if (_size == 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q[_front] << "\n";
                _front = (_front + 1) % MAX;
                _size--;
            }
        }
        else if (cmd == "size")
        {
            cout << _size << "\n";
        }
        else if (cmd == "empty")
        {
            if (_size == 0)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (cmd == "front")
        {
            if (_size == 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q[_front] << "\n";
            }
        }
        else
        {
            if (_size == 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                if (_back == 0)
                    cout << q[MAX - 1] << "\n";
                else
                {
                    cout << q[(_back - 1)] << "\n";
                }
            }
        }
    }

    return 0;
}