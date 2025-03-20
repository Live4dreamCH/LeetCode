#include "MyLib.h"

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        std::sort(horizontalCut.begin(), horizontalCut.end());
        std::sort(verticalCut.begin(), verticalCut.end());
        long long res = 0;
        for (int i = 0, j = 0; i < horizontalCut.size() || j < verticalCut.size(); ) {
            if (j == verticalCut.size()) {
                res += horizontalCut[i] * (n - j);
                ++i;
            }
            else if(i == horizontalCut.size()) {
                res += verticalCut[j] * (m - i);
                ++j;
            }
            else if (horizontalCut[i] < verticalCut[j]) {
                res += horizontalCut[i] * (n - j);
                ++i;
            }
            else if (horizontalCut[i] >= verticalCut[j]) {
                res += verticalCut[j] * (m - i);
                ++j;
            }
        }
        return res;
    }
};

//int main() {
//    Solution s;
//    int m = 3, n = 2;
//    vector<int> horizontalCut{ 1,3 }, verticalCut{ 5 };
//    s.minimumCost(m, n, horizontalCut, verticalCut);
//    return 0;
//}