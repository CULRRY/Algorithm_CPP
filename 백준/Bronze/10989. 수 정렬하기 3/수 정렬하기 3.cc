#include<iostream>
#include<vector>
using namespace std;

// 계수 정렬(counting sort) 이용한 문제
// 값끼리 서로 비교하는 것이아닌, 배열에 들어갈 수 있는 수의 범위가
// 한정된 상황에서 그 범위 만큼의 배열을 만들고, 그 수가 몇 번등장하는지 저장한다.

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, input;
    cin >> N;
    vector<int> count(10001, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        count[input]++;
    }

    for (int i = 0; i < count.size(); i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            cout << i << "\n";
        }
    }

    return 0;
}