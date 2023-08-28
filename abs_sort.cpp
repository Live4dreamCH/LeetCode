#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using std::sort;
using std::unordered_multimap;
using std::vector;

vector<float> GetNormalizedSortedIndex(const vector<float> &origin_vec)
{
    // 分别提取正数、负数
    vector<float> negtive_vec, positive_vec;
    for (const auto &num : origin_vec)
    {
        // 0算作正数
        if (num > 0)
        {
            positive_vec.emplace_back(num);
        }
        else if (num < 0)
        {
            negtive_vec.emplace_back(num);
        }
    }

    // 原始数值 映射 原始下标，用于将答案回填至对应下标
    unordered_multimap<float, size_t> num_index_multimap;
    for (int i = 0; i < origin_vec.size(); ++i)
    {
        num_index_multimap.emplace(origin_vec[i], i);
    }

    // 答案
    vector<float> res_vec(origin_vec.size(), 0);

    // copy code, bad design
    sort(negtive_vec.begin(), negtive_vec.end());
    sort(positive_vec.begin(), positive_vec.end());

    // 计算负数数组的答案
    for (int i = 0; i < negtive_vec.size(); ++i)
    {
        auto index_it = num_index_multimap.find(negtive_vec[i]);
        if (num_index_multimap.end() == index_it)
        {
            std::cerr << negtive_vec[i] << "not found! exit.\n";
            return res_vec;
        }
        size_t origin_index = index_it->second;

        float norm_index = -1 + float(i) / negtive_vec.size();
        res_vec[origin_index] = norm_index;
        num_index_multimap.erase(index_it);
    }

    // 计算正数数组的答案
    for (int i = 0; i < positive_vec.size(); ++i)
    {
        auto index_it = num_index_multimap.find(positive_vec[i]);
        if (num_index_multimap.end() == index_it)
        {
            std::cerr << positive_vec[i] << "not found! exit.\n";
            return res_vec;
        }
        size_t origin_index = index_it->second;

        float norm_index = float(i + 1) / positive_vec.size();
        res_vec[origin_index] = norm_index;
        num_index_multimap.erase(index_it);
    }

    // 处理0
    size_t zero_count = origin_vec.size() - positive_vec.size() - negtive_vec.size();
    for (int i = 0; i < zero_count; ++i)
    {
        auto index_it = num_index_multimap.find(0);
        if (num_index_multimap.end() == index_it)
        {
            std::cerr << positive_vec[i] << "not found! exit.\n";
            return res_vec;
        }
        size_t origin_index = index_it->second;
        res_vec[origin_index] = 0;
        num_index_multimap.erase(index_it);
    }

    return res_vec;
}

int main()
{
    vector<float> res, expected_res;

    res = GetNormalizedSortedIndex({-3, -2, -0.5, -1, 8, 2});
    expected_res = {-1, -0.75, -0.25, -0.5, 1, 0.5};
    std::cout << (expected_res == res) << '\n';

    res = GetNormalizedSortedIndex({-0.5, 8, -3, 2, -1, -2});
    expected_res = {-0.25, 1, -1, 0.5, -0.5, -0.75};
    std::cout << (expected_res == res) << '\n';

    res = GetNormalizedSortedIndex({-3, -2, -0.5, -1, 8, 2, 0});
    expected_res = {-1, -0.75, -0.25, -0.5, 1, 0.5, 0};
    std::cout << (expected_res == res) << '\n';

    res = GetNormalizedSortedIndex({8, 2, 0});
    expected_res = {1, 0.5, 0};
    std::cout << (expected_res == res) << '\n';

    res = GetNormalizedSortedIndex({8, 2, 0, 0});
    expected_res = {1, 0.5, 0, 0};
    std::cout << (expected_res == res) << '\n';

    res = GetNormalizedSortedIndex({-3, -2, -0.5, -1});
    expected_res = {-1, -0.75, -0.25, -0.5};
    std::cout << (expected_res == res) << '\n';

    return 0;
}