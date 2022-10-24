#include <iostream>

using namespace std;

int main()
{
    int T;
    int H, W, N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> H >> W >> N;
        int y = 0, x = 1;
        while (N - H > 0)   
        {
            N -= H;
            x++;
        }
        y = N;
        cout << y;
        if (x < 10)
            cout << '0' << x << "\n";
        else
            cout << x << "\n";
        
    }
    return 0;
}