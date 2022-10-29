#include <iostream>
#include <vector>
using namespace std;

bool isHan(int num)
{
	if (num < 100)
		return true;

	int a = num / 100;
	int b = (num / 10) % 10;
	int c = (num % 10);
	if ((a - b) == (b - c))
		return true;

	return false;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int input;
	cin >> input;
	int count = 0;
	for (int i = 1; i <= input; i++)
	{
		if (isHan(i))
			count++;
	}

	cout << count << "\n";


}



