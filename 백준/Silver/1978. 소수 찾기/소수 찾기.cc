#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isPrime(int n)
{
	if (n == 0) return false;
	if (n == 1) return false;
	for(int i = 2; i*i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	
	return true;
}
int main()
{	
	
	int N;
	cin >> N;
	int arr[100];
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (isPrime(arr[i]))
			count++;
	}
	
	cout << count;
	
	

}