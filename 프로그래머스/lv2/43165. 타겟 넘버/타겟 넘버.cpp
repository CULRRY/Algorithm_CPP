#include <string>
#include <vector>

using namespace std;
int answer = 0;
void bt(vector<int>& numbers, int target, int depth, int sum)
{
    if (depth >= numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }
    
    bt(numbers, target, depth + 1, sum + numbers[depth]);
    bt(numbers, target, depth + 1, sum - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    
    bt(numbers, target, 0, 0);
    return answer;
}