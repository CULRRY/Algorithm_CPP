#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <iostream>
using namespace std;
vector<vector<string>> r;
vector<bool> canUseTmp;
vector<bool> canUse;
set<set<int>> keys;
int answer = 0;
bool check(vector<int>& indices)
{
    unordered_set<string> s;
    cout << "indices : ";
    for (int i : indices)
        cout << i << " ";
    
    for (auto v : r)
    {
        string tmp = "";
        for (int i = 0; i < indices.size(); i++)
        {
            tmp += v[indices[i]] + " ";
        }
        
        if (s.find(tmp) == s.end())
        {
            s.insert(tmp);
        }
        else
        {
            cout << "false" << endl;
            return false;
        }
    }
    cout << "true" << endl;;
    return true;
}
void bt(int depth, int limit, vector<int> indices)
{
    if (depth == limit)
    {
        if (check(indices))
        {
            for (auto s : keys)
            {
                int cnt = 0;
                for (int i : indices)
                {
                    if (s.find(i) != s.end())
                    {
                        cnt++;
                    }
                }
                
                if (cnt == s.size())
                    return;
            }
            set<int> tmp;
            for (int i : indices)
            {
                tmp.insert(i);
            }
            keys.insert(tmp);
            answer++;
        }
        return;
    }
    
    for (int i = indices[depth-1] + 1; i < r[0].size(); i++)
    {
        if (canUse[i] == true)
        {
            canUse[i] = false;
            indices[depth] = i;
            bt(depth+1, limit, indices);
            canUse[i] = true;
        }
    }
}

int solution(vector<vector<string>> relation) {
    r = relation;
    canUse.assign(relation[0].size(), true);
    canUseTmp.assign(relation[0].size(), true);
    for (int i = 1; i <= relation[0].size(); i++)
    {
        vector<int> indices(i, 0);
        for (int j = 0; j < relation[0].size(); j++)
        {
            if (canUse[j] == true)
            {
                canUse[j] = false;
                indices[0] = j;
                bt(1, i, indices);
                canUse[j] = true;
            }
        }
        
    }
    
    
    return answer;
}