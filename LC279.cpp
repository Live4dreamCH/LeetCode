#include "MyLib.h"

// rm ./LC279.out ; g++ LC279.cpp -std=c++2a -isystem benchmark/include \
//   -Lbenchmark/build/src -lbenchmark -lpthread -o LC279.out -g -O2 -fconstexpr-ops-limit=2147000000 ; ./LC279.out
// rm: cannot remove './LC279.out': No such file or directory
// 2025-05-14T22:03:25+08:00
// Running ./LC279.out
// Run on (16 X 3686.4 MHz CPU s)
// CPU Caches:
//   L1 Data 48 KiB (x8)
//   L1 Instruction 32 KiB (x8)
//   L2 Unified 1280 KiB (x8)
//   L3 Unified 20480 KiB (x1)
// Load Average: 0.29, 0.27, 0.17
// i=1, sum=0
// i=10, sum=19
// i=100, sum=261
// i=1000, sum=2802
// i=10000, sum=28815
// i=100000, sum=288150
// i=1000000, sum=2881500
// i=10000000, sum=28815000
// i=100000000, sum=288150000
// i=1000000000, sum=-1413467296
// i=1543052374, sum=151338018
// -----------------------------------------------------
// Benchmark           Time             CPU   Iterations
// -----------------------------------------------------
// BM_Package      0.443 ns        0.463 ns   1543052374
constexpr size_t N = 10000;
constexpr std::array<int, N + 1> get_res_array() {
    std::array<int, N + 1> temp{};
    for (int i = 0; i <= N; ++i) {
        temp[i] = i;
    }
    for (int i = 2; i * i <= N; ++i) {
        int sqrt_i = i * i;
        for (int n = sqrt_i; n <= N; ++n) {
            temp[n] = std::min(temp[n], temp[n - sqrt_i] + 1);
        }
    }
    return temp;
}
constexpr std::array<int, N + 1> global_arr = get_res_array();

class Solution {
   public:
    int numSquares(int n) { return global_arr[n]; }
};

int main() {
    Solution s;

    return s.numSquares(9999);
}