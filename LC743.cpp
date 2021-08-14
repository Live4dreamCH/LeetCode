#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <list>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> dis(n + 5, -1);
        queue<int> edge;
        vector<list<pair<int, int>>> nei(n + 5);
        vector<bool> visited(n + 5, false);
        edge.push(k);
        dis[k] = 0;
        for (auto &t : times)
        {
            auto &link = nei[t[0]];
            if (link.empty())
            {
                link.push_back({t[1], t[2]});
                continue;
            }
            for (auto it = link.begin();; ++it)
            {
                if (it->first > t[1] || it == link.end())
                {
                    link.insert(it, {t[1], t[2]});
                    break;
                }
            }
        }
        while (!edge.empty())
        {
            int &curr = edge.front();
            visited[curr] = true;
            auto &link = nei[curr];
            for (auto it = link.begin(); it != link.end(); ++it)
            {
                int &target = it->first, &wei = it->second;
                int temp = wei + dis[curr];
                if (dis[target] == -1)
                {
                    dis[target] = temp;
                }
                else
                {
                    dis[target] = temp < dis[target] ? temp : dis[target];
                }
                if (!visited[target])
                    edge.push(target);
            }
            edge.pop();
        }
        int max_len = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (dis[i] == -1)
            {
                return -1;
            }
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
    s.networkDelayTime(temp, 4, 2);
    return 0;
}