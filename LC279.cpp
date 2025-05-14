#include "MyLib.h"

// rm ./LC279.out ; g++ LC279.cpp -std=c++2a -isystem benchmark/include \ 
//   -Lbenchmark/build/src -lbenchmark -lpthread -o LC279.out -g -O2 ; ./LC279.out
// rm: cannot remove './LC279.out': No such file or directory
// 2025-05-14T18:53:09+08:00
// Running ./LC279.out
// Run on (16 X 3686.4 MHz CPU s)
// CPU Caches:
//   L1 Data 48 KiB (x8)
//   L1 Instruction 32 KiB (x8)
//   L2 Unified 1280 KiB (x8)
//   L3 Unified 20480 KiB (x1)
// Load Average: 0.53, 0.45, 0.27
// i=1, sum=0
// i=10, sum=19
// i=100, sum=261
// i=1000, sum=2802
// i=2568, sum=7298
// -----------------------------------------------------
// Benchmark           Time             CPU   Iterations
// -----------------------------------------------------
// BM_Package     250593 ns       255663 ns         2568
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
    while (1) {
        std::cin >> n;
        std::cout << s.numSquares(n);
    }
    return 0;
}