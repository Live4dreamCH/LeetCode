#include <iostream>
#include <string>
#include <vector>
using std::vector;
// using std::string;

int compare_with_three(int num) {
    if (num > 3) {
        return 1;
    } else if (num < 3) {
        return -1;
    }
    return 0;
}
int main() {
    vector<int> integers = {1, 2, 3};
    // int N;
    // std::cin >> N;
    // for (int i = 0; i < N; ++i) {
    //     integers.push_back(i);
    // }
    // for (int i = 0; i < integers.size(); ++i) {
    //     std::cout << integers[i] << ' ';
    // }
    integers.insert(integers.begin(), 0);
    integers.insert(integers.end(), 4);
    integers.insert(integers.begin() + 2, 10000);
    integers.at(2);
    std::cout << integers[2];
    int a = integers[2] = 3;
    std::cout << compare_with_three(integers[2]);
    // vector<char> characters(20, 'a');
    // vector<std::string> strings{"42", "hhh", "bfx", "account", "password"};

    // vector<std::string>::iterator it = strings.begin(), ano_it = strings.end();
    // ano_it -= 1;
    // it += 2;
    // strings.erase(it);
    // strings.erase(it);
    // std::cout << (ano_it == strings.end()) << std::endl;
    // std::cout << (ano_it - strings.begin()) << std::endl;
    // for (int i = 0; i < 100; ++i) {
    //     std::cout << *(it + i) << std::endl;
    // }

    // it += 10;
    // std::cout << *it << std::endl;

    // std::string *ptr = &strings[0];
    // for (int i = 0; i < 100; ++i) {
    //     std::cout << *(ptr + i) << std::endl;
    // }

    // ptr += 10;
    // std::cout << *ptr << std::endl;

    return 0;
}