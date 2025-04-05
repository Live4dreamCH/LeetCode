#include "MyLib.h"
#include <numeric>
namespace num_theory {
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    if (0 == k) {
      return;
    }
    auto f = [&](int i) {
      int temp = nums[i];
      int j = i;
      int next_j = (j - k < 0) ? j - k + nums.size() : j - k;
      while (next_j != i) {
        nums[j] = nums[next_j];
        j = next_j;
        next_j = (j - k < 0) ? j - k + nums.size() : j - k;
      }
      nums[j] = temp;
    };
    int group = std::gcd(nums.size(), k);
    for (int i = 0; i < group; ++i) {
      f(i);
    }
  }
};
} // namespace num_theory

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    if (0 == k || nums.size() == 1) {
      return;
    }
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
  }
};