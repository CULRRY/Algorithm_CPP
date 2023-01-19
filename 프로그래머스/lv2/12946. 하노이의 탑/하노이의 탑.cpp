#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int start, int via, int end, vector<vector<int>>& answer)
{
    if (n > 0)
    {
        hanoi(n-1, start, end, via, answer);
        answer.push_back({start, end});
        hanoi(n-1, via, start, end, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(n, 1, 2, 3, answer);
    
    return answer;
}