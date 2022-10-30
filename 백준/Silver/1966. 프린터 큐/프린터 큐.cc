#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        queue<pair<int, int>> q;
        priority_queue<int> heap;
        int N, M;
        cin >> N >> M;

        for (int i = 0; i < N; i++)
        {
            int weight;
            cin >> weight;
            q.push(pair<int, int>(i, weight));
            heap.push(weight);
        }

        int count = 0;
        int max = heap.top();
        while(true)
        {
            if (q.front().second == max)
            {
                count++;
                if (q.front().first == M)
                    break;
                q.pop();
                heap.pop();
                max = heap.top();
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
        cout << count << "\n";
    }

    return 0;
}