#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(), tangerine.end());
    priority_queue<int> pq;
    int prev = tangerine[0];
    int cnt = 1;
    for (int i = 1; i < tangerine.size(); i++)
    {
        if (tangerine[i] == prev)
        {
            cnt++;
        }
        else
        {
            pq.push(cnt);
            cnt = 1;
        }
        prev = tangerine[i];
    }
    pq.push(cnt);

    while (k > 0)
    {
        int now = pq.top();
        pq.pop();
        answer++;
        k -= now;
    }
    
    return answer;
}