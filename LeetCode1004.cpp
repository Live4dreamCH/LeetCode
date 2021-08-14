#include "pch.h"
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        short start = 0, end = 0, max_len = 0, zeros = 0;   //[start, end]
        while (end < A.size()) {
            if (A[end] == 0) {
                ++zeros;

                if (zeros > K) {
                    short curr = end - start;   //[start, end)
                    if (curr > max_len)
                        max_len = curr;

                    while (A[start++] != 0);
                    --zeros;
                }
            }
            ++end;
        }
        short curr = end - start;   //[start, end)
        if (curr > max_len)
            max_len = curr;
        return max_len;
    }
};