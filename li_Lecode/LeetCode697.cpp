#include "pch.h"
#include <vector>
#include <map>
#include <array>
using namespace std; 

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<unsigned short, array<unsigned short, 3> > range;  //{num:[count, begin, end]}
        for (unsigned short i = 0; i < nums.size(); ++i) {
            auto pos = range.find(nums[i]);
            if (pos == range.end()) {
                range.emplace(nums[i], array<unsigned short, 3>({ 1, i, i }));
            }
            else {
                range[nums[i]][0] += 1;
                range[nums[i]][2] = i;
            }
        }

        unsigned short max_freq = 0, min_len = 50005;
        unsigned short curr_freq, curr_len;
        for (auto i = range.begin(); i != range.end(); ++i) {
            curr_freq = i->second[0];
            if (curr_freq > max_freq) {
                max_freq = curr_freq;
                min_len = i->second[2] - i->second[1];
            }

            else if (curr_freq == max_freq) {
                curr_len = i->second[2] - i->second[1];
                if (curr_len < min_len) {
                    min_len = curr_len;
                }
            }
        }
        return min_len + 1;
    }
};