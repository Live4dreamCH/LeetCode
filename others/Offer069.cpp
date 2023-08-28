#include <vector>
using std::vector;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int mid = right / 2;
        while (left < right) {
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else if (arr[mid - 1] < arr[mid]) {
                break;
            } else {
                right = mid - 1;
            }
            mid = (left + right) / 2;
        }
        return mid;
    }
};
