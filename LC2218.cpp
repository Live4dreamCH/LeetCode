#include "MyLib.h"

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> val(k+1, 0);
        int cnt = piles[0].size();
        for (int j = 0;j < cnt && j < k;++j) {
            val[j + 1] = val[j] + piles[0][j];
        }
        for (int i = 1;i < piles.size();++i) {
            vector<int> sum(std::min<size_t>(piles[i].size(), k + 1), 0);
            sum[0] = piles[i][0];
            for (int j = 1;j < sum.size();++j) {
                sum[j] = sum[j - 1] + piles[i][j];
            }
            for (int j = std::min<int>(k, cnt + piles[i].size());j > 0;--j) {
                int max_val = val[j];
                for (int jj = (j > cnt ? j - cnt - 1 : 0);jj < sum.size() && j - jj - 1 >= 0;++jj) {
                    if (val[j - jj - 1] + sum[jj] > max_val) {
                        max_val = val[j - jj - 1] + sum[jj];
                    }
                }
                val[j] = max_val;
            }
            cnt = std::min<int>(k, cnt + piles[i].size());
        }
        return val[k];
    }
};