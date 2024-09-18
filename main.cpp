#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        bool allZeros = true;
        for (int num : nums) {
            if (num != 0) {
                allZeros = false;
                break;
            }
        }
        if (allZeros) return "0";
        auto compare = [](const int &a, const int &b) {
            string ab = to_string(a) + to_string(b);
            string ba = to_string(b) + to_string(a);
            return ab > ba;
        };
        sort(nums.begin(), nums.end(), compare);
        ostringstream result;
        for (int num : nums) {
            result << num;
        }
        return result.str();
    }
};