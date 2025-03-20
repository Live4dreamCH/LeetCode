#include "MyLib.h"
constexpr int M = 1000000007;
vector<int> three_vec{ 1, 1, 2, 4 }, four_vec{ 1, 1, 2, 4, 8 };

class Solution {
public:
    int countTexts(string pressedKeys) {
        long long res = 1;
        int len = 0;
        char prev = pressedKeys[0];
        for (const char& c : pressedKeys) {
            if (c == prev) {
                ++len;
                continue;
            }
            res = res * cnt(len, (prev == '7' || prev == '9') ? 4 : 3) % M;
            prev = c;
            len = 1;
        }
        return int(res * cnt(len, (prev == '7' || prev == '9') ? 4 : 3) % M);
    }
private:
    int cnt(int length, int k) {
        auto& ans_vec = (4 == k) ? four_vec : three_vec;
        if (ans_vec.size() > length) {
            return ans_vec[length];
        }
        for (int i = ans_vec.size();i <= length;++i) {
            int temp = ans_vec[i - 1] + ans_vec[i - 1] - ans_vec[i - k - 1];
            // temp %= M;
            if (temp >= M) {
                temp -= M;
            }
            else if (temp < 0) {
                temp += M;
            }
            ans_vec.emplace_back(temp);
        }
        return ans_vec[length];
    }
};