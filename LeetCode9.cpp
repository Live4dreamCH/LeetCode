#include "pch.h"
#include <stack>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        int n = std::floor(log10f(x));
        int ten = 1, rten = 1;
        for (int i = 0; i < n; ++i) {
            rten *= 10;
        }
        while (ten < rten) {
            if (x / ten % 10 != x / rten % 10)
                return false;
            ten *= 10;
            rten /= 10;
        }
        return true;
    }
};