#include<iostream>
#include<cmath>
using namespace std;

int N, r, c;
int count = 0;
int solution;

void solve(int r, int c, int N)
{
    if (N == 1)
    {
        return;
    }
    //1사분면
    if (r < N/2 && c < N/2)
    {
        solve(r, c, N / 2);
    }
    //2사분면
    else if (r < N/2 && c >= N/2)
    {
        ::count += pow(N/2, 2);
        solve(r, c - N/2, N / 2);
    }
    //3사분면
    else if (r >= N/2 && c < N/2)
    {
        ::count += pow(N / 2, 2) * 2;
        solve(r - N/2, c, N / 2);
    }
    //4사분면
    else
    {
        ::count += pow(N / 2, 2) * 3;
        solve(r - N/2, c - N/2, N/2);;
    }
}

int main()
{
    cin >> N >> r >> c;
    N = pow(2, N);
    solve(r, c, N);
    cout << ::count;
    return 0;
}