#include "MyLib.h"

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> freq_vec(26, 0);
        for (const char& c : word2) {
            ++freq_vec[c - 'a'];
        }

        vector<int> cnt_vec(26, 0);
        int less_char_num = 0;
        for (const int& f : freq_vec) {
            if (f > 0) {
                ++less_char_num;
            }
        }

        int l = 0, r = 0; // [l, r] 
        long long res = 0;
        for (;r < word1.size();++r) {
            ++cnt_vec[word1[r] - 'a'];
            if (cnt_vec[word1[r] - 'a'] != freq_vec[word1[r] - 'a']) {
                continue;
            }
            --less_char_num;
            if (0 < less_char_num) {
                continue;
            }
            for (; 0 == less_char_num && l <= r; ++l) {
                res += word1.size() - r;
                --cnt_vec[word1[l] - 'a'];
                if (cnt_vec[word1[l] - 'a'] < freq_vec[word1[l] - 'a']) {
                    ++less_char_num;
                }
            }
        }
        return res;
    }
};

//int main() {
//    Solution s{};
//    s.validSubstringCount("bcca", "abc");
//    return 0;
//}