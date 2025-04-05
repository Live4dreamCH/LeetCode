#include "MyLib.h"

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) { // 保证没有漏网之鱼
      int j = i,
          will_write = (0 < nums[i] && nums[i] <= nums.size()) ? nums[i] : -1;
      while (true) {
        if (nums[j] == j + 1) {
          break;
        }
        if (nums[j] <= 0 || nums[j] > nums.size()) {
          nums[j] = will_write;
          break;
        }
        int temp = nums[nums[j] - 1];
        nums[nums[j] - 1] = will_write;
        will_write = temp;
        j = will_write - 1;
        if (j < 0 || j >= nums.size()) {
          break;
        }
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return nums.size();
  }
};