#include <string>
using std::string;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int count[30] = {0};
    for (const auto &c : magazine) {
      ++count[c - 'a'];
    }
    for (const auto &c : ransomNote) {
      --count[c - 'a'];
    }
    for (const auto &i : count) {
      if (i < 0) {
        return false;
      }
    }
    return true;
  }
};