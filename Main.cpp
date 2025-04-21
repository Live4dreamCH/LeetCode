//#include "LC41.cpp"
//
//constexpr std::array<std::array<int, 2>, 4> v{
//    {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
//
//int main() {
//  Solution s{};
//  vector<int> m{3, 4, -1, 1};
//  s.firstMissingPositive(m);
//  m = {1, 2, 3};
//  return 0;
//}

#include <ctime>
#include <iostream>
#include <string>
#include <thread>
// #include <unistd.h>
// #include <vector>
using namespace std;

// n
// 1
// n
// nlogn

// long long a = 0;
// long long p[10000];

long long fib(int x, long long& a)
{
    a++;
    if (x <= 2)
        return 1;
    // if(p[x]!=-1)
    //     return p[x];
    return fib(x - 1, a) + fib(x - 2, a);
}

void cal(const int& x, const clock_t& p)
{
    clock_t start, end;
    double sec, s;
    long long r;
    long long a = 0;
    start = clock();
    r = fib(x, a);
    end = clock();
    sec = (end - start) / double(CLOCKS_PER_SEC);
    s = (end - p) / double(CLOCKS_PER_SEC);
    cout << "位：" << x << ' ' << "答：" << r << ' ' << "递归次数：" << a << ' ' << "单次时间：" << sec << ' ' << "总用时:" << s << endl;
}

int main()
{
    // cout << "中文？" << endl;
    clock_t pri = clock();
    thread* pool[20];
    for (int i = 50; i < 70; i++)
    {
        // p[i] = -1;
        thread* t;
        t = new thread(cal, i, pri);
        pool[i - 50] = t;
        // sleep(0.01);
        if (i == 69)
            t->join();
        cout << "进程号 " << pool[i - 50]->get_id() << " 已启动" << endl;
    }
    // for (int i = 40; i < 65; i++)
    // {
    //     cout << "进程号 " << pool[i - 40]->get_id() << " 已启动" << endl;
    //     pool[i - 40]->join();
    // }
    return 0;
}