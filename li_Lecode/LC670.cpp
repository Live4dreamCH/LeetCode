#include <bits/stdc++.h>
using std::vector;

class Solution {
public:
  int maximumSwap(int num) {
    if (num < 10) {
      return num;
    }

    std::string digit_str = std::to_string(num);
    std::string sorted_str = digit_str;
    std::sort(sorted_str.begin(), sorted_str.end(), std::greater<int>());

    int k=-1, j=-1;
    for (int i = 0; i < digit_str.size(); ++i) {
      if (k == -1 && digit_str[i] != sorted_str[i]) {
        k = i;
        continue;
      }
      if (k != -1 && digit_str[i] == sorted_str[k]) {
        j=i;
      }
    }

    if(-1==k){
      return num;
    }
    digit_str[j] = digit_str[k];
    digit_str[k] = sorted_str[k];
    return std::stoi(digit_str);
  }
};