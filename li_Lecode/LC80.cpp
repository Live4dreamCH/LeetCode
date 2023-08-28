#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        decltype(nums.size()) pos = 0, curr = 0;
        int times = 0, value = nums[0];
        for (; curr < nums.size(); ++curr) {
            if (nums[curr] == value) {
                ++times;
                if (times > 2) {
                    continue;
                }
            }
            else {
                times = 1;
                value = nums[curr];
            }
            nums[pos] = nums[curr];
            ++pos;
        }
        return pos;
    }
};