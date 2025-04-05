#include "MyLib.h"

/*class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            unordered_map<int, vector<std::pair<int, int> > > sum_indice_map;
            for(int i=0;i<nums.size();++i){
                for(int j=i+1; j<nums.size(); ++j){
                    sum_indice_map[nums[i]+nums[j]].push_back(std::pair<int,int>{i,j});
                }
            }
            set<std::tuple<int,int,int> > dedup_set{};
            for(int i = 0; i < nums.size(); ++i){
                const auto &n = nums[i];
                auto it = sum_indice_map.find(-n);
                if(sum_indice_map.end() == it){
                    continue;
                }
                auto &indice_vec = it->second;
                for(const auto &indice : indice_vec){
                    if(indice.first == i || indice.second == i){
                        continue;
                    }
                    const auto &j = indice.first;
                    const auto &k = indice.second;
                    int s,m,l;
                    if(n < nums[j]){
                        s = n;
                        m = nums[j];
                        l = nums[k];
                    }else if(indice.second < n){
                        s = nums[j];
                        m = nums[k];
                        l = n;
                    }else{
                        s = nums[j];
                        m = n;
                        l = nums[k];
                    }
                    std::tuple<int,int,int> t{s,m,l};
                    dedup_set.emplace(t);
                }
            }
            vector<vector<int> > ans;
            for(const auto &tup : dedup_set){
                ans.push_back({std::get<0>(tup),std::get<1>(tup),std::get<2>(tup)});
            }
            return ans;
        }
    };*/

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i - 1] == nums[i]) {
        continue;
      }
      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        if (j > i + 1 && nums[j - 1] == nums[j]) {
          ++j;
          continue;
        }
        if (k < nums.size() - 1 && nums[k + 1] == nums[k]) {
          --k;
          continue;
        }
        const int &&sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          ans.push_back({nums[i], nums[j], nums[k]});
          ++j;
        } else if (sum < 0) {
          ++j;
        } else {
          --k;
        }
      }
    }
    return ans;
  }
};