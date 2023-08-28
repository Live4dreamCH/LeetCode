#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        if (k == 1) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int diff_min = 100005;
        for (int i = 0; i + k - 1 < nums.size(); ++i) {
            int diff = nums[i + k - 1] - nums[i];
            if (diff < diff_min) {
                diff_min = diff;
            }
        }
        return diff_min;
    }
};

int main() {
    vector<int> a{9, 4, 1, 7};
    Solution s;
    s.minimumDifference(a, 2);

    return 0;
}
