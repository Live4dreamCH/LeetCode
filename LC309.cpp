#include <vector>
#include <cmath>
using std::vector;
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int dp_hold = -prices[0], dp_frozen = 0, dp_not_frozen = 0, temp = 0;
        for (int i = 1; i < prices.size(); ++i) {
            temp = max(dp_frozen, dp_not_frozen);
            dp_frozen = dp_hold + prices[i];
            dp_hold = max(dp_hold, dp_not_frozen - prices[i]);
            dp_not_frozen = temp;
        }
        return max(dp_frozen, dp_not_frozen);
    }
};