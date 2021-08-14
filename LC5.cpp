#include "pch.h"
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxArm = 1, maxPos = 0;
        for (int mid = 1; mid < s.size(); ++mid) {
            int arm = 1;
            int right = s.size() - mid;
            while (mid >= arm && arm < right && s.at(mid - arm) == s.at(mid + arm))
                ++arm;
            if (arm > maxArm) {
                maxArm = arm;
                maxPos = mid;
            }
        }
        return s.substr(maxPos - maxArm + 1, maxArm + maxArm - 1);
    }
};