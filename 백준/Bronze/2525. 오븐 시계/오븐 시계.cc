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
	int nowHour, nowMinute, estimatedTime;
	cin >> nowHour >> nowMinute >> estimatedTime;
	int plusHour = estimatedTime / 60, plusMinute = estimatedTime % 60;

	int resultHour = nowHour + plusHour, resultMinute = nowMinute + plusMinute;

	if(resultMinute >= 60)
	{
		resultMinute -= 60;
		resultHour++;
	}

	if(resultHour >= 24)
	{
		resultHour -= 24;
	}

	cout << resultHour << " " << resultMinute << '\n';
	
}
