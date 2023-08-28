#include <vector>
using std::vector;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        for (int i = 0; i < m; ++i) { // 每行
            int min_pos = -1, min = 100005;
            for (int j = 0; j < n; ++j) { // 找最小
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                    min_pos = j;
                }
            }
            bool is_max = true;
            // 最小值所在列
            for (int i_max = 0; i_max < m; ++i_max) { // 验证是否最大
                if (matrix[i_max][min_pos] > min) {
                    is_max = false;
                    break;
                }
            }
            if (is_max) {
                res.emplace_back(min);
            }
        }
        return res;
    }
};