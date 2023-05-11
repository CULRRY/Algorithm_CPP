#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    string n;

    while (true)
    {
        cin >> n;
        if (n == "0")
            break;
        
        int width = 1;
        for (char c : n)
        {
            switch (c)
            {
            case '1':
                width += 3;
                break;
            case '0':
                width += 5;
                break;
            default:
                width += 4;
                break;
            }
        }

        cout << width << endl;
    }
    



    return 0;
}