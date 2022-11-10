#include <bits/stdc++.h>
using namespace std;

bool isPossible(const string &s, const vector<int> &notWork)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (notWork[s[i] - '0'] == 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string target;
    int M;
    cin >> target >> M;
    vector<int> notWork(10, 0);
    if (M == 10)
    {
        cout << abs(stoi(target) - 100);
        return 0;
    }

    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        notWork[x] = 1;
    }

    int targetInt = stoi(target);
    int i = 0;
    int sizei = 0;
    while (i <= targetInt)
    {
        string s = to_string(targetInt - i);
        sizei = s.size();
        if (isPossible(s, notWork))
        {
            break;
        }
        i++;
    }
    if (i > targetInt)
    {
        i = 9999999;
        sizei = 99999999;
    }

    int j = 0;
    int sizej = 0;
    while (j <= 500000)
    {
        string s = to_string(targetInt + j);
        sizej = s.size();
        if (isPossible(to_string(targetInt + j), notWork))
        {
            break;
        }
        j++;
    }
    int min = std::min(sizei + i, sizej + j);
    min = std::min(min, abs(stoi(target) - 100));

    cout << min;

    return 0;
}