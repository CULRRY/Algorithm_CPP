#include <string>
#include <vector>
#include <cmath>

using namespace std;
int cnt = 0;
vector<int> trace;

void bt(int depth, int x, int n)
{

    
    for (int i = 0; i < depth; i++)
    {
        if (trace[i] == x)
            return;
        
        if (abs(trace[i] - x) == abs(i - depth))
            return;
    }
    if (depth == n-1)
    {
        cnt++;
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        trace[depth+1] = i;
        bt(depth + 1, i, n);
    }
}


int solution(int n) {
    int answer = 0;
    trace = vector<int>(n, 0);
    for (int i = 0; i < n; i++)
    {
        trace[0] = i;
        bt(0,0,n);
    }
    
    answer = cnt;
    return answer;
}