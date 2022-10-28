#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<string> v(N);
    const string caseTile[2] = {"BWBWBWBW", "WBWBWBWB"};
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }


    int min = N*M;
    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            int count1 = 0, count2 = 0;
            for (int y = i; y < i + 8; y++)
            {
                for (int x = j; x < j + 8; x++)
                {
                    if (v[y][x] != caseTile[y % 2][x - j])
                        count1++;

                    if (v[y][x] != caseTile[(y+1) % 2][x - j])
                        count2++;
                }
            }
            int count = count1 > count2 ? count2 : count1;
            if (count < min)
                min = count;
        }
    }
    cout << min;



    return 0;
}