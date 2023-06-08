#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> burger(3);
    vector<int> beverage(2);
    
    for (int i = 0; i < 3; i++)
        cin >> burger[i];
    for (int i = 0; i < 2; i++)
        cin >> beverage[i];
    
    cout << *min_element(burger.begin(), burger.end()) + *min_element(beverage.begin(), beverage.end()) - 50;
        
}