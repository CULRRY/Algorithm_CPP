#include <string>
#include <vector>
#include <queue>

using namespace std;
using ull = unsigned long long;
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1;
    queue<int> q2;
    ull sum1 = 0, sum2 = 0;
    
    for (int i = 0; i < queue1.size(); i++)
    {
        q1.push(queue1[i]);
        sum1 += queue1[i];
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }
    
    if ((sum1 + sum2 % 2) == 1)
    {
        answer = -1;
    }
    else
    {
        int i1 = 0, i2 = 0;
        bool flag = false;
        while (i1 <= queue1.size() || i2 <= queue2.size())
        {
            if (sum1 == sum2)
            {
                bool flag = true;
                return answer;
            }
            else if (sum1 > sum2)
            {
                sum1 -= q1.front();
                sum2 += q1.front();
                q2.push(q1.front());
                q1.pop();
                i1++;
            }
            else if (sum1 < sum2)
            {
                sum2 -= q2.front();
                sum1 += q2.front();
                q1.push(q2.front());
                q2.pop();
                i2++;
            }
            
            answer++;
        }
        
        if (flag == false)
            answer = -1;
    }
    
    return answer;
}