#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v;
    for (int i = 0; i <= n; i++)
    {
        v.push_back(vector<int>(i + 1, 0));
    }
    int cnt = 1;
    
    int beginRow = 1;
    int beginCol = 1;
    int endRow = n;
    int endCol = n;
    while(true)
    {
        if (cnt > n * (n+1) / 2)
            break;
        
        for (int i = beginRow; i <= endRow; i++)
        {
            v[i][beginCol] = cnt++;
        }
        for (int i = beginCol + 1; i <= endCol; i++)
        {
            v[endRow][i] = cnt++;
        }
        int d = 1;
        for (int i = endRow - 1; i > beginRow; i--)
        {
            v[i][endCol - d] = cnt++;
            d++;
        }
        
        beginRow += 2;
        beginCol += 1;
        endCol -= 2;
        endRow -= 1;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < v[i].size(); j++)
        {
            answer.push_back(v[i][j]);
        }
    }
    
    return answer;
}