#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums) {
        int sum = 0, mininum = __INT_MAX__;
        for (auto &num : nums) {
            sum += num;
            mininum = num < mininum ? num : mininum;
        }
        return sum - nums.size() * mininum;
    }
};