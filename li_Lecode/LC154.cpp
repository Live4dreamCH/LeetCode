#include <vector>
#include <cmath>
using std::vector;
using std::max; 

class Solution {
    int search_drop(vector<int>& nums, int left, int right) const {
        if (left + 1 == right) {
            if (nums[left] > nums[right]) {
                return left;
            }
            return -1;
        }

        int mid = (left + right) / 2;
        if (nums[left] > nums[mid]) {
            return search_drop(nums, left, mid);
        }
        if (nums[mid] > nums[right]) {
            return search_drop(nums, mid, right);
        }
        return max(search_drop(nums, left, mid), search_drop(nums, mid, right));
    }

public:
    int findMin(vector<int>& nums) const {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        return nums[search_drop(nums, 0, len - 1) + 1];
    }
};