#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<int> cnt;
int cntPartial = 0;

void Open(int idx, vector<int>& cards)
{
    visited[idx] = true;
    cntPartial++;
    int next = cards[idx] - 1;
    if (visited[next] == true)
        return;
    
    Open(next, cards);
}

int solution(vector<int> cards) {
    int answer = 0;
    visited = vector<bool>(cards.size(), false);
    
    
    for (int i = 0; i < cards.size(); i++)
    {
        
        if (visited[i] == false)
        {
            cntPartial = 0;
            Open(i, cards);
            cnt.push_back(cntPartial);
        }
    }
    if (cnt.size() >= 2)
    {
        sort(cnt.begin(), cnt.end(), greater<int>());
        answer = cnt[0] * cnt[1];
    }
    
    
    return answer;
}