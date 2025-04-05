#include "MyLib.h"

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    std::unordered_map<string, int> str_index_map{};
    vector<vector<string>> res{};
    string temp{}; // sorted
    for (auto &str : strs) {
      temp = str;
      std::sort(temp.begin(), temp.end());
      if (str_index_map.end() == str_index_map.find(temp)) {
        str_index_map[temp] = res.size();
        res.push_back({});
      }
      res[str_index_map[temp]].emplace_back(str);
    }
    return res;
  }
};