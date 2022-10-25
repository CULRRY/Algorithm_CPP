#include <iostream>
#include<cmath>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    char c;
    long long hash = 0;
    const int mod = 1234567891;
    long long r = 1;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> c;
        hash += (((c - 'a' + 1) % mod) * (r % mod)) % mod;
        r *= 31;
        r %= mod;
    }

    cout << hash % mod;
    return 0;
}