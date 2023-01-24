#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = speeds.size();
    queue<int> q;
    
    for (int i = 0; i < n; i++)
    {
        int left = 100 - progresses[i];
        left = left % speeds[i] == 0 ? left / speeds[i] : left / speeds[i] + 1;
        q.push(left);
    }
    

    
    while (!q.empty())
    {
        int cnt = 1;
        int front = q.front();
        q.pop();
        while (!q.empty() && q.front() <= front)
        {
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }
    
    return answer;
}