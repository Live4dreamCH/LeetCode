#include "MyLib.h"

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res = nums.size() + 5;
        int or_val = 0, rev_prev_or_val = 0;
        for (int r = 0;r < nums.size();++r) {
            or_val |= nums[r];
            if (or_val < k) {
                continue;
            }
            or_val = 0;
            for (int l = r;l >= 0;--l) {
                rev_prev_or_val = or_val;
                or_val |= nums[l];
                if (or_val < k) {
                    continue;
                }
                if (r == l) {
                    return 1;
                }
                res = std::min(res, r - l + 1);
                or_val = rev_prev_or_val;
                break;
            }
        }
        return res > nums.size() ? -1 : res;
    }
};