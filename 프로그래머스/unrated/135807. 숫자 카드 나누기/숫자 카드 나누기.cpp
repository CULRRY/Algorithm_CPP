#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int answer = 0;
    int gcdA;
    int gcdB;

    if (arrayA.size() == 1)
        gcdA = arrayA[0];
    else
    {
        gcdA = gcd(arrayA[0], arrayA[1]);
        for (int i = 2; i < arrayA.size(); i++)
        {
            gcdA = gcd(gcdA, arrayA[i]);
        }
    }

    if (arrayB.size() == 1)
    {
        gcdB = arrayB[0];
    }
    else
    {
        gcdB = gcd(arrayB[0], arrayB[1]);
        for (int i = 2; i < arrayB.size(); i++)
        {
            gcdB = gcd(gcdB, arrayB[i]);
        }
    }
    
    int maxA = 0;
    int maxB = 0;
    
    bool flagA = true;
    if (gcdA == 1)
        flagA = false;
    else
    {
        for (int i = 0; i < arrayB.size(); i++)
        {
            if (arrayB[i] % gcdA == 0)
            {
                flagA = false;
                break;
            }
        }
    }

    bool flagB = true;

    if (gcdB == 1)
        flagB = false;
    else
    {
        for (int i = 0; i < arrayA.size(); i++)
        {
            if (arrayA[i] % gcdB == 0)
            {
                flagB = false;
                break;
            }
        }
    }

    if (flagA)
        maxA = gcdA;
    if (flagB)
        maxB = gcdB;
    answer = std::max(maxA, maxB);

    return answer;
}