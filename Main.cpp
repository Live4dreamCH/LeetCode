#include "LC41.cpp"

constexpr std::array<std::array<int, 2>, 4> v{
    {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

int main() {
  Solution s{};
  vector<int> m{3, 4, -1, 1};
  s.firstMissingPositive(m);
  m = {1, 2, 3};
  return 0;
}