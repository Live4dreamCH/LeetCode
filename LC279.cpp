#include "MyLib.h"

class Solution {
   private:
    vector<int> count_vec = vector<int>(10005, INT_MAX);

   public:
    Solution() {
        for (int i = 1; i * i < count_vec.size(); ++i) {
            count_vec[i * i] = 1;
        }
    }

    int numSquares(int n) {
        if (count_vec[n] != INT_MAX) {
            // std::cout << "read " << n << "=" << count_vec[n] << '\n';
            return count_vec[n];
        }
        for (int i = 1; i <= n / 2; ++i) {
            int curr = numSquares(i) + numSquares(n - i);
            if (curr < count_vec[n]) {
                count_vec[n] = curr;
            }
        }
        std::cout << "calc " << n << "=" << count_vec[n] << '\n';
        return count_vec[n];
    }
};

int main() {
    int n{};
    Solution s;
    std::cin >> n;
    std::cout << s.numSquares(n);
    return 0;
}