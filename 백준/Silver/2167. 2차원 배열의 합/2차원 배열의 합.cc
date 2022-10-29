#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> array(N);
	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int num;
			cin >> num;
			array[i].push_back(num);
		}
	}
	
	int input;
	cin >> input;
	
	for (int i = 0; i<input; i++)
	{
		int result = 0;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = a - 1; i < c; i++)
		{
			for (int j = b - 1; j < d; j++)
			{
				result += array[i][j];
			}
			
		}
		cout << result << '\n';
	}
}



