#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);

void recursive(int y, int x, int n, vector<vector<int>>& arr)
{
    int norm = arr[y][x];
    bool flag = true;
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (arr[i][j] != norm)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        answer[norm]++;
        return;
    }
    else
    {
        recursive(y, x, n / 2, arr);
        recursive(y + n / 2, x, n / 2, arr);
        recursive(y, x + n / 2, n / 2, arr);
        recursive(y + n / 2, x + n / 2, n / 2, arr);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    recursive(0, 0, arr.size(), arr);
    return answer;
}