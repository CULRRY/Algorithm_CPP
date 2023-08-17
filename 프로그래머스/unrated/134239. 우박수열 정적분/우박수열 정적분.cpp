#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<double> points;
    points.push_back(k);
    int n = 0;
    while (k != 1)
    {
        n++;
        if (k % 2 == 0)
            k = k / 2;
        else
            k = k * 3 + 1;
        
        points.push_back(k);
    }
    
    vector<double> integral;
    for (int i = 0; i < points.size() - 1; i++)
    {
        double sum = std::max(points[i + 1], points[i]) - abs((points[i + 1] - points[i]) / 2);
        integral.push_back(sum);
    }
    
    for (vector<int>& range : ranges)
    {
        int s = range[0];
        int c = range[1];
        double ret = 0;
        cout << s << " " << c << endl;
        if (n+c < s)
            ret = -1;
        else
        {
            for (int i = s; i < n + c ; i++)
            {
                ret += integral[i];
            }
        }

        answer.push_back(ret);
    }
    
    return answer;
}