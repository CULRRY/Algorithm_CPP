#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int answer = 0;
vector<bool> isUsed;
void bt(int depth, vector<vector<int>>& dungeons, int remain, int cnt)
{
    if (remain < 0)
        return;
    else
        answer = std::max(answer, cnt);
    
    if (depth == n)
        return;
    
    for (int i = 0; i < n; i++)
    {
        if (isUsed[i] == true)
            continue;
        if (remain - dungeons[i][0] < 0)
            continue;
        
        isUsed[i] = true;
        bt(depth + 1, dungeons, remain - dungeons[i][1], cnt + 1);
        isUsed[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {

    n = dungeons.size();
    isUsed.assign(n, false);
    
    bt(0, dungeons, k, 0);
    
    return answer;
}