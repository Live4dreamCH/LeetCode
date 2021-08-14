#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
using std::min;
using std::reverse;
using std::string;

class Solution {
private:
    //返回值: int值: 返回从inner_left到inner_right的打印次数
    int greedy(string &s,
               size_t inner_left, // 本次递归的开始字符的下标
               size_t outer_right // 上一层递归的右侧连续字符的左端下标, 用于判断是否重复打印, 也是本次递归的尾后结束位置
    ) {
        if (inner_left > outer_right) {
            std::cerr << "颠倒: " << inner_left << ' ' << outer_right;
            return 0;
        }
        int res = 0;
        auto inner_right = outer_right - 1;

        while (inner_left <= inner_right) {
            char c = s[inner_left];

            size_t o_r = inner_right, next_i_l = inner_left + 1;

            bool has_same = false;
            for (; o_r > inner_left; --o_r) {
                if (!has_same && s[o_r] == c) {
                    has_same = true;
                    next_i_l = o_r + 1;
                } else if (has_same && s[o_r] != c) {
                    break;
                }
            }
            ++o_r;

            if (!has_same) {
                ++res;
                inner_left = next_i_l;
                continue;
            }

            if (c != s[outer_right]) {
                ++res;
            }
            if (o_r == inner_left + 1) {
                inner_left = next_i_l;
                continue;
            }
            size_t i_l = inner_left;
            for (; i_l < o_r; ++i_l) {
                if (s[i_l] != c) {
                    break;
                }
            }
            res += greedy(s, i_l, o_r);
            inner_left = next_i_l;
        }
        return res;
    }

public:
    int strangePrinter(string s) {
        string s_re = s;
        reverse(s_re.begin(), s_re.end());
        auto len = s.size();
        s.push_back('0');
        s_re.push_back('0');
        size_t inner_left = 0;
        size_t outer_right = len;
        return min(greedy(s, inner_left, outer_right),
                   greedy(s_re, inner_left, outer_right));
    }
};

int main() {
    Solution s;
    std::cout << s.strangePrinter("cacdbaeb") << '\n';
    return 0;
}