#include "MyLib.h"

constexpr size_t N = 10000;
constexpr std::array<int, N + 1> get_res_array() {
    std::array<int, N + 1> temp{};
    for (int i = 0; i <= N; ++i) {
        temp[i] = i;
    }
    for (int i = 2; i * i <= N; ++i) {
        for (int n = i * i; n <= N; ++n) {
            temp[n] = std::min(temp[n], temp[n - i * i] + 1);
        }
    }
    return temp;
}

class Solution {
   public:
    int numSquares(int n) { return get_res_array()[n]; }
};

int main() {
    int n{};
    Solution s;
    std::cin >> n;
    std::cout << s.numSquares(n);
    return 0;
}