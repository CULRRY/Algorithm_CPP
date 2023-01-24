#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i : scoville)
    {
        pq.push(i);
    }
    
    while (pq.size() > 1 && pq.top() < K)
    {
        int f1 = pq.top();
        pq.pop();
        int f2 = pq.top();
        pq.pop();
        int f3 = f1 + f2 * 2;
        pq.push(f3);
        answer++;
    }
    
    if (pq.size() <= 1 && pq.top() < K)
    {
        answer = -1;
    }
    
    return answer;
}