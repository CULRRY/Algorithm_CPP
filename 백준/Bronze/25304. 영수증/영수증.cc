#include<iostream>
using namespace std;

int main()
{
    int X, N;
    cin >> X >> N;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int price;
        int quantity;
        cin >> price >> quantity;
        sum += (price * quantity);
    }
    if (X == sum)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}