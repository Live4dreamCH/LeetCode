#include "MyLib.h"
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> res(queries.size(), -1);
        vector<int> x_index_vec{ -1 };
        int count = 0;
        for (int i = 0; i < nums.size();++i) {
            const int& n = nums[i];
            if (n != x) {
                continue;
            }
            ++count;
            x_index_vec.emplace_back(i);
        }
        for (int j = 0;j < queries.size();++j) {
            const int& q = queries[j];
            if (q >= x_index_vec.size()) {
                continue;
            }
            res[j] = x_index_vec[q];
        }
        return res;
    }
};

//class Solution {
//public:
//    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
//        vector<int> res(queries.size(), -1);
//        map<int, vector<int>> query_index_map;
//        for (int i = 0; i < queries.size(); ++i) {
//            if (queries[i] > nums.size()) {
//                continue;
//            }
//            query_index_map[queries[i]].emplace_back(i);
//        }
//        int count = 0;
//        for (int j = 0; j < nums.size();++j) {
//            const int& n = nums[j];
//            if (n != x) {
//                continue;
//            }
//            ++count;
//            auto q_i_pair = query_index_map.find(count);
//            if (query_index_map.end() == q_i_pair) {
//                continue;
//            }
//            for (const int& i : q_i_pair->second) {
//                res[i] = j;
//            }
//        }
//        return res;
//    }
//};