#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    deque<char> left;
    deque<char> right;

    string init;
    cin >> init;
    for (char c : init)
        left.push_back(c);
    
    int n;
    cin >> n;
    while (n--)
    {
        char cmd;
        cin >> cmd;
        switch (cmd)
        {
        case 'L':
            if (left.empty())
                break;
            right.push_front(left.back());
            left.pop_back();
            break;
        case 'D':
            if (right.empty())
                break;
            left.push_back(right.front());
            right.pop_front();
            break;
        case 'B':
            if (left.empty())
                break;
            left.pop_back();
            break;
        case 'P':
            char c;
            cin >> c;
            left.push_back(c);
            break;
        }
    }
    

    while (!left.empty())
    {
        cout << left.front();
        left.pop_front();
    }

    while (!right.empty())
    {
        cout << right.front();
        right.pop_front();
    }

    return 0;
}