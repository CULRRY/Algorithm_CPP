#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

int main()
{	
	
	int N;
	cin >> N;
	list<int> list;
	for (int i = 1; i <= N; i++)
	{
		list.push_back(i);
	}
	while (list.size() > 1)
	{
		list.pop_front();
		list.push_back(list.front());
		list.pop_front();
	}
	
	cout << list.front();
	

}