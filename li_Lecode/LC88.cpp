#include <vector>
using std::vector;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (m == 0) {
            nums1.swap(nums2);
            return;
        }
        if (n == 0) {
            return;
        }
        vector<int> temp(m + n);

        int i = 0, j = 0;
        for (int k = 0; k < m + n; ++k) {
            if (i >= m) {
                temp[k] = nums2[j];
                ++j;
            } else if (j >= n) {
                temp[k] = nums1[i];
                ++i;
            } else if (nums1[i] <= nums2[j]) {
                temp[k] = nums1[i];
                ++i;
            } else {
                temp[k] = nums2[j];
                ++j;
            }
        }

        temp.swap(nums1);
    }
};