#include "pch.h"
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size())
            return 0;
        vector<unsigned int> dp(s.size() - t.size() + 1, 1);
        for (int j = 0; j < t.size(); ++j) {
            for (int i = 0; i < dp.size(); ++i) {
                if (s[i + j] == t[j]) {
                    if (i != 0)
                        dp[i] += dp[i - 1];
                }
                else {
                    if (i == 0)
                        dp[i] = 0;
                    else
                        dp[i] = dp[i - 1];
                }
            }
        }
        return dp.back();
    }
};