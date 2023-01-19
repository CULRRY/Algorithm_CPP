#include <iostream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int n = board.size();
    int m = board[0].size();
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (board[i][j] == 1)
            {
                board[i][j] = std::min({board[i-1][j-1], board[i-1][j], board[i][j-1]}) + 1;
                answer = std::max(answer, board[i][j]);
            }
        }
    }
    
    
    return answer * answer;
}