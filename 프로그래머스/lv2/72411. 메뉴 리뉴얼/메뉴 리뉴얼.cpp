#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> answer;
map<string, int> m;
string order;
vector<bool> isUsed;
int maxv = 0;
int limit;
void bt(string menu, int idx, int depth)
{
    if (depth == limit)
    {
        m[menu]++;
        maxv = std::max(m[menu], maxv);
        return;
    }
    
    for (int i = idx + 1; i < order.size(); i++)
    {
        if (isUsed[i] == false)
        {
            isUsed[i] = true;
            menu[depth] = order[i];
            bt(menu, i, depth+1);
            isUsed[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for (int i = 0; i < course.size(); i++)
    {
        m = map<string, int>();
        maxv = 0;
        for (string s : orders)
        {

                isUsed.assign(10, false);
                string menu;
                order = s;
                sort(order.begin(), order.end());
                menu.resize(course[i]);
                limit = course[i];
                bt(menu, -1, 0);

        }
        if (maxv < 2)
            continue;
        for (auto item : m)
        {
            if (item.second == maxv)
                answer.push_back(item.first);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}