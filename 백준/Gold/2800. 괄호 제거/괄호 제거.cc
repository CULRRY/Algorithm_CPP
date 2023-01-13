#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl "\n"

using namespace std;

vector<string> ans;
int cntPairs = 0;

void bt(int depth, string s, vector<pair<int, int>>& v)
{
    if (depth >= cntPairs)
        return;
    
    int left = v[depth].first;
    int right = v[depth].second;

    string tmp(s);
    tmp.replace(left, 1, " ");
    tmp.replace(right, 1, " ");
    string ret(tmp);
    ret.erase(remove(ret.begin(), ret.end(), ' '), ret.end());
    ans.push_back(ret);
    bt(depth+1, s, v);
    bt(depth+1, tmp, v);
}

int main()
{
    FASTIO;

    string exp;
    cin >> exp;

    vector<pair<int, int>> v;

    stack<int> s;
    
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '(')
        {
            s.push(i);
        }
        else if (exp[i] == ')')
        {
            int j = s.top();
            s.pop();
            v.push_back({j, i});
            cntPairs++;
        }
    }

    bt(0, exp, v);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()) , ans.end());
    for (string& s : ans)
    {
        cout << s << endl;
    }
    

    return 0;
}