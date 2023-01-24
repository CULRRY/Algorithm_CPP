#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int curWeight = 0;
    int n = truck_weights.size();
    int idx = 0;
    while (true)
    {
        if (idx == n)
        {
            answer += bridge_length;
            break;
        }
        answer++;
        int now = truck_weights[idx];
        if (q.size() == bridge_length)
        {
            curWeight -= q.front();
            q.pop();
        }
        
        if (curWeight + now <= weight)
        {
            q.push(now);
            curWeight += now;
            idx++;
        }
        else
            q.push(0);
    }
    return answer;
}