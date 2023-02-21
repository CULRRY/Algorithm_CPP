#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

enum {U, R, D, L};
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int maxX = 0;
        int minX = 0;
        int maxY = 0;
        int minY = 0;

        string cmd;
        cin >> cmd;
        int d = U;

        int cy = 0;
        int cx = 0;
        for (char c : cmd)
        {
            if (c == 'F')
            {
                cy += dy[d];
                cx += dx[d];
            }
            else if (c == 'B')
            {
                cy -= dy[d];
                cx -= dx[d];
            }
            else if (c == 'L')
            {
                if (d == U)
                    d = L;
                else
                    d -= 1;
            }
            else
            {
                d = (d + 1) % 4;
            }

            if (d == U || d == D)
            {
                if (cy > maxY)
                {
                    maxY = cy;
                }
                else if (cy < minY)
                {
                    minY = cy;
                }
            }
            else
            {
                if (cx > maxX)
                    maxX = cx;
                else if (cx < minX)
                    minX = cx;
            }
        }

        cout << (maxX - minX) * (maxY - minY) << endl;

    }
    

    return 0;
}