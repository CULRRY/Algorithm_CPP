#include <bits/stdc++.h>
using namespace std;

int N, M;
void print(int start, int depth, string s)
{
    if (depth == M)
    {
        cout << s << "\n";
        return;
    }
    else if (start > N)
        return;

    for (int i = start; i <= N; i++)
    {
        print(i, depth + 1, s + to_string(i) + " ");
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    print(1, 0, "");
    return 0;
}