#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    // Dijkstra
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // 到k的距离
        vector<unsigned int> dis(n + 5, -1);
        dis[k] = 0;

        // 邻接表
        vector<vector<pair<int, int>>> nei(n + 5);
        for (const auto &t : times)
        {
            nei[t[0]].emplace_back(t[1], t[2]);
        }

        // 已找到最短距离的点集
        unordered_set<int> shortest;

        // 是否进入下一循环
        bool con = true;
        // 当前节点, 用出边更新dis
        int curr = k;
        while (con)
        {
            shortest.emplace(curr);
            con = false;
            // 更新最短距离
            for (const auto &edge : nei[curr])
            {
                auto new_dis = dis[curr] + edge.second;
                if (new_dis < dis[edge.first])
                {
                    dis[edge.first] = new_dis;
                }
            }

            // 找到下一个最短距离的点
            unsigned int min_dis = -1;
            for (int i = 1; i <= n; ++i)
            {
                if (shortest.find(i) == shortest.end() && dis[i] < min_dis)
                {
                    min_dis = dis[i];
                    curr = i;
                    con = true;
                }
            }
        }

        // 在所有最短距离里找最长距离
        if (shortest.size() != n)
        {
            return -1;
        }
        unsigned int max_len = 0;
        for (int i = 1; i <= n; ++i)
        {
            // 坑: dis[i]是无符号数, 执行无符号数的>, 若max_len初值为-1, 就是无符号数下的ffffffff, 没有比它大的
            if (dis[i] > max_len)
            {
                max_len = dis[i];
            }
        }
        return max_len;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> temp{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << s.networkDelayTime(temp, 4, 2);
    return 0;
}