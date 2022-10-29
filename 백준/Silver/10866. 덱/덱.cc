#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int q[MAX];
int _size = 0;
int _front = 0;
int _back = 1;

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
        if (cmd == "push_front")
        {
            int v;
            cin >> v;
            q[_front] = v;
            if (_front == 0)
                _front = MAX - 1;
            else
                 _front = _front - 1;
            _size++;
        }
        else if (cmd == "push_back")
        {
            int v;
            cin >> v;
            q[_back] = v;
            _back = (_back + 1) % MAX;
            _size++;
        }
        else if (cmd == "pop_front")
        {
            if (_size == 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                _front = (_front + 1) % MAX;
                cout << q[_front] << "\n";
                _size--;
            }
        }
        else if (cmd == "pop_back")
        {
            if (_size == 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                if (_back == 0)
                    _back = MAX - 1;
                else
                    _back = _back - 1;
                cout << q[_back] << "\n";
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
                cout << q[(_front + 1) % MAX] << "\n";
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
                    cout << q[_back - 1] << "\n";
                }
            }
        }
    }

    return 0;
}