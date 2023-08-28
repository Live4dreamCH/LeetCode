#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

int main() {
    int A, N;
    cin >> A >> N;
    char result[100005] = {0};
    for (int i = 0; i < 100005; ++i) {
        printf("%d", result[i]);
    }
    return 0;
}