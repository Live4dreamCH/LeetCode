#include <algorithm>
#include <functional>
#include <vector>
using std::vector;

class Solution {
public:
  int maximumSwap(int num) {
    if (num < 10) {
      return num;
    }

    std::vector<int> digit_vec;
    for (int remain = num; remain > 0; remain /= 10) {
      digit_vec.emplace_back(remain % 10);
    }
    std::reverse(digit_vec.begin(), digit_vec.end());
    vector<int> sorted_vec = digit_vec;
    std::sort(sorted_vec.begin(), sorted_vec.end(), std::greater<int>());

    for (int i = 0, swap_i = -1; i < digit_vec.size(); ++i) {
      if (swap_i == -1 && digit_vec[i] != sorted_vec[i]) {
        swap_i = i;
        continue;
      }
      if (swap_i != -1 && digit_vec[i] == sorted_vec[swap_i]) {
        digit_vec[i] = digit_vec[swap_i];
        digit_vec[swap_i] = sorted_vec[swap_i];
        break;
      }
    }

    int res = 0, times = 1;
    for (auto it = digit_vec.rbegin(); it != digit_vec.rend(); ++it) {
      res += *it * times;
      times *= 10;
    }
    return res;
  }
};