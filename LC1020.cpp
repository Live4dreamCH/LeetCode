#include <queue>
#include <utility>
#include <vector>
using std::pair;
using std::queue;
using std::vector;

class Solution {
public:
    int numEnclaves(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // 从地图的4条边缘开始
        for (int I = 0; I < m; ++I) { // 上边缘
            if (grid[I][0] == 0 || visited[I][0]) {
                continue;
            }
            // 作BFS
            queue<pair<int, int>> later_visit;
            later_visit.emplace(I, 0);
            while (!later_visit.empty()) {
                auto [i, j] = later_visit.front(); // C++17 结构化绑定
                // 记录访问过的陆地
                visited[i][j] = true;
                later_visit.pop();
                if (i - 1 >= 0 && visited[i - 1][j] == false && grid[i - 1][j] == 1) {
                    later_visit.emplace(i - 1, j);
                }
                if (i + 1 < m && visited[i + 1][j] == false && grid[i + 1][j] == 1) {
                    later_visit.emplace(i + 1, j);
                }
                if (j - 1 >= 0 && visited[i][j - 1] == false && grid[i][j - 1] == 1) {
                    later_visit.emplace(i, j - 1);
                }
                if (j + 1 < n && visited[i][j + 1] == false && grid[i][j + 1] == 1) {
                    later_visit.emplace(i, j + 1);
                }
            }
        }
        for (int I = 0; I < m; ++I) { // 下边缘
            if (grid[I][n - 1] == 0 || visited[I][n - 1]) {
                continue;
            }
            // 作BFS
            queue<pair<int, int>> later_visit;
            later_visit.emplace(I, n - 1);
            while (!later_visit.empty()) {
                auto [i, j] = later_visit.front(); // C++17 结构化绑定
                // 记录访问过的陆地
                visited[i][j] = true;
                later_visit.pop();
                if (i - 1 >= 0 && visited[i - 1][j] == false && grid[i - 1][j] == 1) {
                    later_visit.emplace(i - 1, j);
                }
                if (i + 1 < m && visited[i + 1][j] == false && grid[i + 1][j] == 1) {
                    later_visit.emplace(i + 1, j);
                }
                if (j - 1 >= 0 && visited[i][j - 1] == false && grid[i][j - 1] == 1) {
                    later_visit.emplace(i, j - 1);
                }
                if (j + 1 < n && visited[i][j + 1] == false && grid[i][j + 1] == 1) {
                    later_visit.emplace(i, j + 1);
                }
            }
        }
        for (int J = 1; J < n - 1; ++J) { // 左边缘
            if (grid[0][J] == 0 || visited[0][J]) {
                continue;
            }
            // 作BFS
            queue<pair<int, int>> later_visit;
            later_visit.emplace(0, J);
            while (!later_visit.empty()) {
                auto [i, j] = later_visit.front(); // C++17 结构化绑定
                // 记录访问过的陆地
                visited[i][j] = true;
                later_visit.pop();
                if (i - 1 >= 0 && visited[i - 1][j] == false && grid[i - 1][j] == 1) {
                    later_visit.emplace(i - 1, j);
                }
                if (i + 1 < m && visited[i + 1][j] == false && grid[i + 1][j] == 1) {
                    later_visit.emplace(i + 1, j);
                }
                if (j - 1 >= 0 && visited[i][j - 1] == false && grid[i][j - 1] == 1) {
                    later_visit.emplace(i, j - 1);
                }
                if (j + 1 < n && visited[i][j + 1] == false && grid[i][j + 1] == 1) {
                    later_visit.emplace(i, j + 1);
                }
            }
        }
        for (int J = 1; J < n - 1; ++J) { // 左边缘
            if (grid[m - 1][J] == 0 || visited[m - 1][J]) {
                continue;
            }
            // 作BFS
            queue<pair<int, int>> later_visit;
            later_visit.emplace(m - 1, J);
            while (!later_visit.empty()) {
                auto [i, j] = later_visit.front(); // C++17 结构化绑定
                // 记录访问过的陆地
                visited[i][j] = true;
                later_visit.pop();
                if (i - 1 >= 0 && visited[i - 1][j] == false && grid[i - 1][j] == 1) {
                    later_visit.emplace(i - 1, j);
                }
                if (i + 1 < m && visited[i + 1][j] == false && grid[i + 1][j] == 1) {
                    later_visit.emplace(i + 1, j);
                }
                if (j - 1 >= 0 && visited[i][j - 1] == false && grid[i][j - 1] == 1) {
                    later_visit.emplace(i, j - 1);
                }
                if (j + 1 < n && visited[i][j + 1] == false && grid[i][j + 1] == 1) {
                    later_visit.emplace(i, j + 1);
                }
            }
        }
        // 未访问过的陆地就是飞地
        int res = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    ++res;
                }
            }
        }
        return res;
    }
};