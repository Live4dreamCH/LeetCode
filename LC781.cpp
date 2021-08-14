#include <vector>
#include <map>
using std::vector;
using std::map;

class Solution {
    int ceiling(int n, int d) {
        int y = n % d;
        if (y == 0)
            return n;
        return n - y + d;
    }
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> times;
        int result = 0;
        for (auto it = answers.begin(); it != answers.end(); ++it) {
            if (times.find(*it) == times.end()) {
                times[*it] = 1;
            }
            else {
                ++times[*it];
            }
        }
        for (auto it = times.begin(); it != times.end(); ++it) {
            result += this->ceiling(it->second, it->first + 1);
        }
        return result;
    }
};