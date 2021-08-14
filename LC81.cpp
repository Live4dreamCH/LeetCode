#include <vector>
#include <cmath>
using std::vector;
using std::max;

class Solution {

    int search_drop(vector<int>& nums, int left, int right) const{
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

    bool search_v(vector<int>& nums, int left, int right, int &target) const {
        if (left > right)
            return false;
        if (left == right) {
            return target == nums[left];
        }

        int mid = (left + right) / 2;
        if (target == nums[mid])
            return true;
        if (target < nums[mid])
            return search_v(nums, left, mid - 1, target);
        return search_v(nums, mid + 1, right, target);
    }

public:
    bool search(vector<int>& nums, int target) const {
        int len = nums.size();
        if (len == 1) {
            return target == nums[0];
        }
        int drop = search_drop(nums, 0, len - 1);
        if (drop == -1) {
            return search_v(nums, 0, len - 1, target);
        }
        if (target == nums[0]) {
            return true;
        }
        if (target > nums[0]) {
            return search_v(nums, 0, drop, target);
        }
        return search_v(nums, drop + 1, len - 1, target);
    }
};