#include <iostream>

using namespace std;

int main()
{
    int T;
    int H, W, N;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &H, &W, &N);
        int y = 0, x = 1;
        while (N - H > 0)   
        {
            N -= H;
            x++;
        }
        y = N;
        printf("%d\n", y*100 + x);
        
    }
    return 0;
}