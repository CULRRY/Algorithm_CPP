#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int back = people.size() - 1;
    int front = 0;
    
    while (front <= back)
    {
        int weight = people[back];
        back--;
        while (weight + people[front] <= limit)
        {
            weight += people[front];
            front++;
            if (front > back)
                break;
        }
        answer++;
    }
    
    
    return answer;
}