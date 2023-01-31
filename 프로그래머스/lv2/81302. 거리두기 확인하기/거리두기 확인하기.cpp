#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct Point
{
    int y, x;
};
vector<Point> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool bfs(int y, int x, vector<string>& place)
{
    cout << y << " : " << x << endl;
    queue<Point> q;
    q.push({y, x});
    vector<vector<bool>> discoverd(5, vector<bool>(5, false));
    discoverd[y][x] = true;
    int cnt = 0;
    while(!q.empty())
    {
        int sz = q.size();
        if (cnt == 2)
            return true;
            
        for (int s = 0; s < sz; s++)
        {
            Point now = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++)
            {
                Point next = {now.y + d[i].y, now.x + d[i].x};
                
                if (next.y < 0 || next.y >= 5 || next.x < 0 || next.x >=5)
                    continue;
                if (discoverd[next.y][next.x] == true)
                    continue;
                
                if (place[next.y][next.x] == 'X')
                    continue;
                
                if (place[next.y][next.x] == 'P')
                    return false;
                    
                discoverd[next.y][next.x] = true;
                q.push(next);
            }
        }
        cnt++;
        
    }
    return true;
    
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (vector<string> place : places)
    {
        bool flag = true;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (place[i][j] == 'P')
                {
                    if (!bfs(i, j, place))
                    {
                        flag = false;
                        i = 5;
                        break;
                    }
                }
            }
        }
        answer.push_back(flag);
    }
    return answer;
}