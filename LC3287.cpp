#include "MyLib.h"

class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int res = 0;
        vector<set<unsigned char> > or_val_set_vec(nums.size() - 2*k + 1), rev_or_val_set_vec(nums.size() - 2*k + 1);
        f(nums.begin(), k, or_val_set_vec);
        f(nums.rbegin(), k, rev_or_val_set_vec);
        for (int i = 0;i < or_val_set_vec.size();++i) {
            for (const auto& l : or_val_set_vec[i]) {
                for (const auto& r : *(rev_or_val_set_vec.rbegin() + i)) {
                    res = std::max(res, l ^ r);
                }
            }
        }
        return res;
    }
private:
    template<typename It>
    void f(It begin, int k, vector<set<unsigned char> >& or_val_set_vec) {
        or_val_set_vec[0].emplace(*begin);
        // when j = 1
        for (int i = 1;i < or_val_set_vec.size();++i) {
            or_val_set_vec[i] = or_val_set_vec[i - 1];
            or_val_set_vec[i].emplace(*(begin + i));
        }
        for (int j = 2;j <= k;++j) {
            auto temp_val = *or_val_set_vec[0].begin();
            or_val_set_vec[0].erase(or_val_set_vec[0].begin());
            or_val_set_vec[0].emplace(*(begin + j - 1) | temp_val);
            for (int i = 1;i < or_val_set_vec.size();++i) {
                auto temp_set = or_val_set_vec[i - 1];
                for (const auto& n : or_val_set_vec[i]) {
                    temp_set.emplace(n | *(begin + j - 1 + i));
                }
                or_val_set_vec[i].swap(temp_set);
            }
        }
    }
};