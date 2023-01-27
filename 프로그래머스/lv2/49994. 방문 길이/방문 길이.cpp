#include <string>
#include <iostream>
using namespace std;
bool visited[11][11][4];
enum { U, D, R, L };
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int dir(char d)
{
    switch (d)
    {
        case 'U':
            return U;
        case 'D':
            return D;
        case 'R':
            return R;
        case 'L':
            return L;
    }
}

int solution(string dirs) {
    int answer = 0;
    int y = 5, x = 5;
    
    for (char c : dirs)
    {
        int d = dir(c);
        int ny = y + dy[d];
        int nx = x + dx[d];
        
        if (ny < 0 || ny >= 11 || nx < 0 || nx >= 11)
            continue;
        
        if (visited[y][x][d] == false)
        {
            answer++;
            int nd;
            if (d == U || d == R)
                nd = d + 1;
            else
                nd = d - 1;
            
            visited[y][x][d] = true;
            visited[ny][nx][nd] = true;
        }
        y = ny, x = nx;
    }
    
    return answer;
}