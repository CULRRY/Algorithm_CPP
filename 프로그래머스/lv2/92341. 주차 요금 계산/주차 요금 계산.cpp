#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

int diffMinute(string in, string out)
{
    int inHour = stoi(in.substr(0, 2));
    int inMinute = stoi(in.substr(3, 2));
    int outHour = stoi(out.substr(0, 2));
    int outMinute = stoi(out.substr(3, 2));
    
    int diffHour = outHour - inHour;
    int diffMinute = diffHour * 60 + (outMinute - inMinute);
    return diffMinute;
}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int basicTime = fees[0];
    int basicFee = fees[1];
    int perTime = fees[2];
    int perFee = fees[3];
    map<int, int> total;
    map<int, string> inMap;
    
    for (string record : records)
    {
        stringstream ss(record);
        string time;
        int number;
        string status;
        ss >> time >> number >> status;
        if (status == "IN")
        {
            inMap[number] = time;
        }
        else
        {
            int diff = diffMinute(inMap[number], time);
            
            total[number] += diff;
            
            inMap.erase(number);
        }
    }
    for (auto car : inMap)
    {
        int diff = diffMinute(car.second, "23:59");
        total[car.first] += diff;
        
    }
    
    for (auto car : total)
    {
        int diff = car.second;
        int fee = basicFee;
        diff -= basicTime;
        if (diff > 0)
        {
            fee += (diff / perTime) * perFee;
            if (diff % perTime != 0)
                fee += perFee;
        }
        
        answer.push_back(fee);
    }
    
    return answer;
}