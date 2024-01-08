#include <unordered_map>
#include <vector>
using std::vector;

long long int disSquare(const vector<int> &p1, const vector<int> &p2) {
  return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}

class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    std::unordered_map<long long int, std::unordered_map<int, int>>
        dis_point_degree_map;
    for (int i = 0; i < points.size(); ++i) {
      for (int j = i + 1; j < points.size(); ++j) {
        long long int dis_square = disSquare(points[i], points[j]);
        ++dis_point_degree_map[dis_square][i];
        ++dis_point_degree_map[dis_square][j];
      }
    }
    int sum = 0;
    for (const auto &dis_pair : dis_point_degree_map) {
      for (const auto &point_pair : dis_pair.second) {
        const auto &degree = point_pair.second;
        if (degree > 1) {
          sum += degree * (degree - 1);
        }
      }
    }
    return sum;
  }
};