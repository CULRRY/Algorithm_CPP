#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
struct Functor
{
	bool operator()(string a, string b)
	{
		if (a.size() == b.size())
		{
			return a < b;
		}
		
		return a.size() < b.size();
	}
};
int main()
{
	int n;
	cin >> n;
	set<string, Functor> word;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		word.insert(tmp);
	}
	for (set<string>::iterator it = word.begin(); it != word.end(); ++it)
	{
		cout << *it << "\n";
	}
	
}