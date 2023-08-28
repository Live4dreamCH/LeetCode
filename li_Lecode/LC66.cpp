#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        auto it = digits.rbegin();
        *it += 1;
        for (; it != digits.rend(); ++it) {
            if (*it == 10) {
                *it = 0;
                ++(*(it + 1));
            } else {
                break;
            }
        }
    }
};