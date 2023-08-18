#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> sub;
    queue<int> main;
    
    for (int i = 1; i <= order.size(); i++)
    {
        main.push(i);
    }
    
    for (int o : order)
    {

        if (!sub.empty())
        {
            if (o == sub.top())
            {
                answer++;
                sub.pop();
                continue;
            }
        }
        
        if (main.empty())
            break;

        while (!main.empty())
        {
            if (main.front() == o)
            {
                main.pop();
                answer++;
                break;
            }
            sub.push(main.front());
            main.pop();
        }
    }
    
    
    return answer;
}