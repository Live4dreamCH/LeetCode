#include "pch.h"
#include <vector>
#include <utility>
using namespace std;

class Solution {
private:
    bool isNext(vector<int>& center, vector<int>& ano0, vector<int>& ano1) {
        pair<int, int> p1(ano0[0] - center[0], ano0[1] - center[1]), p2(ano1[0] - center[0], ano1[1] - center[1]);
        if (p2.first == p1.second && p2.second == -p1.first)
            return true;
        if (p2.first == -p1.second && p2.second == p1.first)
            return true;
        return false;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1 != p3 && isNext(p1, p2, p4) && isNext(p3, p2, p4))
            return true;
        if (p1 != p4 && isNext(p1, p2, p3) && isNext(p4, p2, p3))
            return true;
        if (p1 != p2 && isNext(p1, p3, p4) && isNext(p2, p3, p4))
            return true;
        return false;
    }
};