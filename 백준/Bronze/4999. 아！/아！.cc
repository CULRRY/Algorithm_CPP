#include <iostream>
#include<cmath>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    char c;
    int me = 0;
    int doc = 0;
    while (c != 'h')
    {
        cin >> c;
        me++;
    }
    c = 0;
    while (c != 'h')
    {
        cin >> c;
        doc++;
    }

    cout << (me >= doc ? "go" : "no") << "\n";
    return 0;
}