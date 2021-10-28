#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int result = 0, remain = 0;
        string res;
        do {
            result = numerator / denominator;
            remain = numerator % denominator;
            cout << result;
            if (result)
        } while (remain != 0);
    }
};

int main() {
    return 0;
}