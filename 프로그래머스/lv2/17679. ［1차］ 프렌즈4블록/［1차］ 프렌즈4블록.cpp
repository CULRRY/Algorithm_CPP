#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    
    bool flag = true;
    while (flag)
    {
        vector<string> tmp(board);
        flag = false;
        for (int i = 0; i < m-1; i++)
        {
            for (int j = 0; j < n-1; j++)
            {
                char norm  = board[i][j];
                if (norm == '-')
                    continue;
                if (norm != board[i+1][j])
                    continue;
                if (norm != board[i][j+1])
                    continue;
                if (norm != board[i+1][j+1])
                    continue;
            
                flag = true;
                for (int r = 0; r < 2; r++)
                {
                    for (int c = 0; c < 2; c++)
                    {
                        tmp[i + r][j + c] = ' ';
                    }
                }
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tmp[i][j] == ' ')
                {
                    answer++;
                    tmp[i][j] = '-';
                }
            }
        }
        
        for (int i = m-2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int y = i;
                while (y < m - 1 && tmp[y+1][j] == '-')
                {
                    ::swap(tmp[y][j], tmp[y+1][j]);
                    y++;
                }
            }
        }
        
        board = tmp;
    
    }
    

    
    return answer;
}