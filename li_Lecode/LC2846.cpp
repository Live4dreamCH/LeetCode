#include <bits/stdc++.h>
using std::vector;

// 一、走哪条路/每步往哪走

// 二、路上权值的组成

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        std::vector<std::vector<int>> route_table(n,vector<int>(n)); // [self, dest] -> next_hop
        std::unordered_map<std::pair<int, int>, std::map<int, int>> path_comp; // (from, to), (weight, count)
        for(const auto& edge: edges){

        }
    }

private:
    int getNextHop(const int from, const int to){
        
    }
};