#include "pch.h"
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix[0][0] == target || matrix.back().back() == target)
            return true;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;
        int mid = right / 2, curr;
        while (left < mid && mid < right) {
            curr = matrix[mid / n][mid % n];
            if (curr == target) {
                return true;
            }
            else if (curr > target) {
                right = mid;
                mid = (left + mid) / 2;
            }
            else {
                left = mid;
                mid = (right + mid) / 2;
            }
        }
        return false;
    }
};