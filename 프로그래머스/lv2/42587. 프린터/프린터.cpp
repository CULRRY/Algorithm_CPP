#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    priority_queue<int> pq;
    int cnt = 0;
    for (int i : priorities)
    {
        q.push(i);
        pq.push(i);
    }
    
    while (true)
    {
        if (q.front() == pq.top())
        {
            q.pop();
            pq.pop();
            answer++;
            if (cnt == location)
            {
                break;
            }
        }
        else
        {
            if (cnt == location)
            {
                location += pq.size();
            }
            q.push(q.front());
            q.pop();
        }
        cnt++;
    }
    
    
    return answer;
}