#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input, pattern;
    cin >> input >> pattern;

    deque<pair<char, int>> dq;
    int idx = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == pattern[idx])
        {
            idx++;
            dq.push_back(make_pair(input[i], idx));
            if (idx == pattern.length())
            {
                for (int j = 0; j < pattern.length(); j++)
                {
                    dq.pop_back();
                }

                if (dq.empty())
                {
                    idx = 0;
                }
                else
                {
                    idx = dq.back().second;
                }
            }
        }
        else
        {
            if (dq.empty())
            {
                idx = 0;
            }
            else
            {
                idx = dq.back().second;
                if (idx != 0)
                {
                    int tmp = 0;
                    for (int k = 0; k <= tmp; k++)
                    {
                        if (input[i] == pattern[k])
                            tmp = k + 1;
                    }
                    idx = tmp;
                }
            }
            dq.push_back(make_pair(input[i], idx));
        }
    }

    if (dq.empty())
    {
        cout << "FRULA";
    }
    else
    {
        while (!dq.empty())
        {
            cout << dq.front().first;
            dq.pop_front();
        }
    }

    return 0;
}