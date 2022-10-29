#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;

    int K;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int n;
        cin >> n;
        if (n == 0)
            s.pop();
        else
            s.push(n);
    }

    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}