#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

int main()
{	
	string s;
	while (true)
	{
		cin >> s;
		if (s == "0")
			break;
			
		string tmp;
		
		for (int i = s.size()-1; i >= 0; i--)
		{
			tmp += s[i];
		}
		if (s == tmp)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	
	return 0;
}