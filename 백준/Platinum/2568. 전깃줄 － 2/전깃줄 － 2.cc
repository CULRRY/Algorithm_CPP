#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

struct Line
{
    int a, b;
};


int main()
{
    FASTIO;

    int m;
    cin >> m;
    
    vector<Line> lines(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        lines[i] = {a, b};
    }

    std::sort(lines.begin(), lines.end(), [](Line& l1, Line& l2) { return l1.b < l2.b; });

    vector<int> v;
    for (Line& line : lines)
    {
        v.push_back(line.a);
    }

    vector<int> result;
    vector<int> p(m);
    result.push_back(v[0]);
    p[0] = 0;

    for (int i = 1; i < m; i++)
    {
        auto lw = lower_bound(result.begin(), result.end(), v[i]);
        if (lw == result.end())
        {
            p[i] = result.size();
            result.push_back(v[i]);
        }
        else
        {
            p[i] = lw - result.begin();
            *lw = v[i];
        }
    }

    cout << m - result.size() << "\n";

    stack<int> s;
    int norm = result.size() - 1;
    for (int i = m - 1; i >= 0; i--)
    {
        if (norm < 0)
            break;

        if (p[i] == norm)
        {
            s.push(v[i]);
            norm--;
        }
    }

    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        if (!s.empty() && v[i] == s.top())
        {
            s.pop();
        }
        else
        {
            ans.push_back(v[i]);
        }
    }

    ::sort(ans.begin(), ans.end());
    
    for (int i : ans)
    {
        cout << i << "\n";
    }



    return 0;
}