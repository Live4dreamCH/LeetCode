#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <string>

using std::cout;
using std::endl;
using std::function;
using std::sort;
using std::string;
using std::vector;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int curr = -1, res = 0;
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        for (auto &p : pairs)
        {
            if (curr < p[0])
            {
                curr = p[1];
                res++;
            }
        }
        return res;
    }
};

bool more_than(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    vector<int> list{1, 2, 3, 9, 5, 7, 4, 6, 8, 14, 11};
    int average = 0, length;
    length = list.size();
    for (const auto &i : list)
    {
        average = average + i;
    }
    average = average / length;
    cout << string(average, ' ') << average << "=average" << endl;

    function<bool(const int &, const int &)> my_lambda = [average](const int &a, const int &b) -> bool
    {
        if ((a - average) < 0 && (b - average) < 0)
            return a > b;
        else if ((a - average) < 0 && (b - average) >= 0)
            return true;
        else if ((a - average) >= 0 && (b - average) < 0)
            return false;
        else if ((a - average) >= 0 && (b - average) >= 0)
            return a < b;
        return true;
    };

    sort(list.begin(), list.end(), my_lambda);
    for (const auto &n : list)
    {
        cout << string(n, ' ') << n << endl;
    }
    return 0;
}