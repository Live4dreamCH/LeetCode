#include "MyLib.h"

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int index_from = 0, index_to = 0;
    for (; index_from < nums.size(); ++index_from) {
      if (0 == nums[index_from]) {
        continue;
      }
      nums[index_to] = nums[index_from];
      ++index_to;
    }
    for (; index_to < nums.size(); ++index_to) {
      nums[index_to] = 0;
    }
  }
};