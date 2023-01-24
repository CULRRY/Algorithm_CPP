#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(prices.size(), 0);
    queue<int> q;
    q.push(0);
    for (int i = 1; i < n; i++)
    {
        int sz = q.size();
        for (int s = 0; s < sz; s++)
        {
            if (prices[i] >= prices[q.front()])
            {
                answer[q.front()]++;
                q.push(q.front());
                q.pop();
            }
            else
            {
                answer[q.front()]++;
                q.pop();
            }
        }
        q.push(i);
    }
    
    return answer;
}