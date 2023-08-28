#include "pch.h"
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numStk;
        int x, y;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                y = numStk.top();
                numStk.pop();
                x = numStk.top();
                numStk.pop();
                numStk.push(x + y);
            }
            else if (tokens[i] == "-") {
                y = numStk.top();
                numStk.pop();
                x = numStk.top();
                numStk.pop();
                numStk.push(x - y);
            }
            else if (tokens[i] == "*") {
                y = numStk.top();
                numStk.pop();
                x = numStk.top();
                numStk.pop();
                numStk.push(x * y);
            }
            else if (tokens[i] == "/") {
                y = numStk.top();
                numStk.pop();
                x = numStk.top();
                numStk.pop();
                numStk.push(x / y);
            }
            else {
                numStk.push(std::stoi(tokens[i]));
            }
        }
        return numStk.top();
    }
};