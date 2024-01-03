#include <vector>

constexpr int P = 1000000000 + 7;

template <typename T>
class DP
{
public:
    DP(size_t size) { array.resize(size, T{}); }

    T get(int i)
    {
        if (i < 0)
        {
            return 0;
        }
        if (i >= array.size())
        {
            return 0;
        }
        return array[i];
    }

    void set(int i, const T &value)
    {
        if (i < 0)
        {
            return;
        }
        if (i >= array.size())
        {
            return;
        }
        array.emplace(array.begin() + i, value);
    }

private:
    std::vector<T> array;
};

class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        DP<long long int> dp(target - n + 5);
        dp.set(0, 1);
        for (int i = 0; i < target + n; ++i)
        {
            auto right = dp.get(i) * (i + n) % P + dp.get(i - k + 1) * (i - k * (n + 1) + 1) % P + dp.get(i - k) * (n * (k - 1) - i + k) % P;
            right %= P;
            if (right % (i + 1) != 0)
            {
                return -1;
            }
            dp.set(i + 1, right / (i + 1));
        }
        return dp.get(target - n);
    }
};