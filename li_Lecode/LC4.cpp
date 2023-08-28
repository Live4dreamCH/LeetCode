#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        auto mn = nums1.size() + nums2.size();
        vector<int> joined(mn);
        auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
        auto it = joined.begin();
        while (it1 != nums1.end() && it2 != nums2.end())
        {
            if (*it1 < *it2)
            {
                *it = *it1;
                ++it;
                it1++;
            }
            else
            {
                *it = *it2;
                ++it;
                it2++;
            }
        }
        for (; it1 != nums1.end(); ++it1)
        {
            *it = *it1;
            ++it;
        }
        for (; it2 != nums2.end(); ++it2)
        {
            *it = *it2;
            ++it;
        }
        if (mn % 2 == 0)
        {
            return double(joined[mn / 2] + joined[mn / 2 - 1]) / 2;
        }
        else
        {
            return joined[mn / 2];
        }
    }
};