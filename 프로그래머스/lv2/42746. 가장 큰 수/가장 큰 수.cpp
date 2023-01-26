#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    for (int i : numbers)
    {
        nums.push_back(to_string(i));
    }
    sort(nums.begin(), nums.end(), [](string s1, string s2){
        return s1 + s2 > s2 + s1;
    });
    if (nums[0] == "0")
        return "0";
    for (string s : nums)
    {
        answer += s;
    }
    
    return answer;
}