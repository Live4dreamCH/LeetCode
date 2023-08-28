#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        unordered_map<string, bool> cities;
        for (auto &path : paths) {
            cities.insert_or_assign(path.front(), true);
            cities[path.back()];
        }
        for (auto &it : cities) {
            if (it.second == false) {
                return it.first;
            }
        }
        return string{};
    }
};

int main() {
    Solution s;
    vector<vector<string>> paths{{"a", "b"}};
    cout << s.destCity(paths);
    return 0;
}