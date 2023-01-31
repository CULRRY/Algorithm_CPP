#include <string>
#include <vector>
#include <iostream>
#include <algorithm>;

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> matrix(rows+1, vector<int>(columns+1, 0));
    int cnt = 1;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            matrix[i][j] = cnt++;
        }
    }
    
    for (auto query : queries)
    {
        int sy = query[0];
        int sx = query[1];
        int ey = query[2];
        int ex = query[3];
        int ans = 100000;
        for (int i = sx; i <= ex; i++)
        {
            ans = min(ans, matrix[sy][sx]);
            swap(matrix[sy][sx], matrix[sy][i]);
        }
        for (int i = sy + 1; i <= ey; i++)
        {
            ans = min(ans, matrix[sy][sx]);
            swap(matrix[sy][sx], matrix[i][ex]);
        }
        for (int i = ex - 1; i >= sx; i--)
        {
            ans = min(ans, matrix[sy][sx]);
            swap(matrix[sy][sx], matrix[ey][i]);
        }
        for (int i = ey - 1; i >= sy; i--)
        {
            ans = min(ans, matrix[sy][sx]);
            swap(matrix[sy][sx], matrix[i][sx]);
        }
        
        answer.push_back(ans);
    }
    
    return answer;
}