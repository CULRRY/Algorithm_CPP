#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
        cout << y*100 + x << "\n";
        
    }
    return 0;
}