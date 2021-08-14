#include <vector>
using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {
        auto len = height.size();
        if (len <= 0)
            return 0;
        int left = 0, right = len - 1;
        int rain = 0;
        int left_hei = height[left], right_hei = height[right];
        while (left != right+1) {
            if (left_hei <= right_hei) {
                if (height[left] > left_hei) {
                    left_hei = height[left];
                }
                else if (height[left] < left_hei) {
                    rain += left_hei - height[left];
                }
                ++left;
            }
            else {
                if (height[right] > right_hei) {
                    right_hei = height[right];
                }
                else if (height[right] < right_hei) {
                    rain += right_hei - height[right];
                }
                --right;
            }
        }
        return rain;
    }
};