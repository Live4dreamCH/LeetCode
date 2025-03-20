#include "MyLib.h"
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> count(105, 0);
        for (const auto& n : nums) {
            ++count[n];
            if (count[n] >= 3) {
                return false;
            }
        }
        return true;
    }
};