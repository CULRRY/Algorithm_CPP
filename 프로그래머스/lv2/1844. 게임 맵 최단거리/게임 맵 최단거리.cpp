#include<vector>
#include<queue>
using namespace std;

struct Point
{
    int y, x;
};

const vector<Point> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(vector<vector<int>>& maps)
{
    queue<Point> q;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> discoverd(n, vector<bool>(m, false));
    discoverd[0][0] = true;
    q.push({0, 0});
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        cnt++;
        for (int s = 0; s < sz; s++)
        {
            Point now = q.front();
            q.pop();
            if (now.x == m - 1 && now.y == n - 1)
            {
                return cnt;
            }
            
            for (int i = 0; i < 4; i++)
            {
                Point next = {now.y + d[i].y, now.x + d[i].x};
                if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n)
                    continue;
                
                if (discoverd[next.y][next.x] == true)
                    continue;
                
                if (maps[next.y][next.x] == 0)
                    continue;
                
                q.push(next);
                discoverd[next.y][next.x] = true;
            }
        }
        
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    
    answer = bfs(maps);
    
    
    return answer;
}