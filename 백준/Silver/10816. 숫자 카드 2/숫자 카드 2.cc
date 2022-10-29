#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    map<int, int> cards;
    for (int i = 0; i < N; i++)
    {
        int in;
        cin >> in;
        if (cards.find(in) == cards.end())
            cards[in] = 1;
        else
            cards[in]++;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int in;
        cin >> in;
        if (cards.find(in) == cards.end())
            cout << 0 << " ";
        else
            cout << cards[in] << " ";
    }
    
    
    

    return 0;
}