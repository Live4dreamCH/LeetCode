#include "pch.h"
#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = grumpy.size();
        int satisfied = 0, saved = 0, max_saved = 0;
        for (int i = 0; i < X; ++i) {
            if (grumpy[i] == 0)
                satisfied += customers[i];
            else
                saved += customers[i];
        }
        for (int i = X; i < n; ++i) {
            if (grumpy[i] == 0)
                satisfied += customers[i];
            else
                saved += customers[i];
            if (grumpy[i - X] == 1)
                saved -= customers[i - X];
            if (saved > max_saved)
                max_saved = saved;
        }
        if (saved > max_saved)
            max_saved = saved;
        return satisfied + max_saved;
    }
};