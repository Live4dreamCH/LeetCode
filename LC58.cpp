#include <string>
using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool reach = false;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            if (*it != ' ') {
                reach = true;
                ++len;
            } else {
                if (reach) {
                    return len;
                }
            }
        }
        return len;
    }
};