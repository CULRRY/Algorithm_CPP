#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
struct Point
{
    int y, x;  
};

vector<Point> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<bool>> discoverd;
int maxCount = 0;

void bfs(vector<vector<int>>& picture, Point start, int m, int n)
{
    queue<Point> q;
    q.push(start);
    discoverd[start.y][start.x] = true;
    int cnt = 0;
    int norm  = picture[start.y][start.x];
    cout << norm << endl;
    while (!q.empty())
    {
        Point now = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            Point next = {now.y + d[i].y, now.x + d[i].x};
            if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n)
                continue;
            if (discoverd[next.y][next.x] == true)
                continue;
            if (picture[next.y][next.x] != norm)
                continue;
            if (picture[next.y][next.x] == 0)
                continue;
            
            discoverd[next.y][next.x] = true;
            q.push(next);
        }
    }
    maxCount = std::max(maxCount, cnt);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    maxCount = 0;
    
    discoverd = vector<vector<bool>>(m, vector<bool>(n, false));
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] == 0)
                continue;
            
            if (discoverd[i][j] == false)
            {
                
                bfs(picture, {i, j}, m, n);
                number_of_area++;
            }
        }
    }
    
    max_size_of_one_area = maxCount;
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}