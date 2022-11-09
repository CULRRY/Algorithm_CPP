#include <bits/stdc++.h>
using namespace std;

inline bool isDigit(const char &c)
{
    return c >= '0' && c <= '9';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        string func;
        cin >> func;
        int n;
        cin >> n;
        vector<int> l;
        string array;
        cin >> array;
        string tmp = "";
        for (int i = 0; i < array.size(); i++)
        {
            if (isDigit(array[i]))
            {
                while (isDigit(array[i]))
                {
                    tmp += array[i];
                    i++;
                }
                l.push_back(stoi(tmp));
                tmp = "";
            }
        }

        int left = 0;
        int right = l.size() - 1;
        int size = l.size();
        bool isError = false;
        bool isReverse = false;
        for (int i = 0; i < func.size(); i++)
        {
            if (func[i] == 'R')
            {
                isReverse = !isReverse;
            }
            else
            {
                if (size == 0)
                {
                    cout << "error";
                    isError = true;
                    break;
                }
                else
                {
                    if (!isReverse)
                        left++;
                    else
                        right--;
                    size--;
                }
            }
        }

        if (!isError)
        {
            cout << '[';
            if (!isReverse)
            {
                for (int i = left; i <= right; i++)
                {
                    cout << l[i];
                    if (i != right)
                        cout << ",";
                }
            }
            else
            {
                for (int i = right; i >= left; i--)
                {
                    cout << l[i];
                    if (i != left)
                        cout << ",";
                }
            }
            cout << "]";
        }
        cout << "\n";
    }

    return 0;
}