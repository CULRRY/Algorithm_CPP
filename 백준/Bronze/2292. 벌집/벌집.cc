#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int layer = 1;

    N -= 1;
    while (N > 0)
    {
        N -= (6 * layer);
        layer++;
    }

    cout << layer;

    return 0;
}