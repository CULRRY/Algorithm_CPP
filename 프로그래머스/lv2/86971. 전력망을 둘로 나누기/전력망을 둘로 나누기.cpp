#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> board;
vector<bool> visited;
vector<int> weights(2, 0);

int cnt = 0;

void dfs(int n, int s)
{
    visited[s] = true;
    cnt++;
    for (int i = 1; i <= n; i++)
    {
        if (board[s][i] == 0)
            continue;
        if (visited[i] == true)
            continue;
        
        dfs(n, i);
    }
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    
    board.assign(n+1, vector<int>(n+1, 0));
    
    for (auto wire : wires)
    {
        board[wire[0]][wire[1]] = 1;
        board[wire[1]][wire[0]] = 1;
    }
    
    for (auto wire : wires)
    {
        board[wire[0]][wire[1]] = 0;
        board[wire[1]][wire[0]] = 0;
        visited.assign(n+1, false);
        int idx = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)
            {
                cnt = 0;
                dfs(n, i);
                weights[idx] = cnt;
                idx++;
            }
        }
        
        answer = min(answer, abs(weights[1] - weights[0]));
        board[wire[0]][wire[1]] = 1;
        board[wire[1]][wire[0]] = 1;
    }
    
    return answer;
}