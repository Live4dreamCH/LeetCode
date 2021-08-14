#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
private:
    string* t1 = nullptr, * t2 = nullptr;
    vector<vector<int> >* dpp = nullptr;

    int calculate(int i, int j) {
        if (i == 0 || j == 0) {
            return 0;
        }
        if ((*dpp)[i][j] == -1) {
            if ((*t1)[i - 1] == (*t2)[j - 1]) {
                (*dpp)[i][j] = calculate(i - 1, j - 1) + 1;
            }
            else {
                int left = calculate(i - 1, j), right = calculate(i, j - 1);
                (*dpp)[i][j] = left < right ? right : left;
            }
        }
        return (*dpp)[i][j];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        t1 = &text1;
        t2 = &text2;
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, -1));
        dpp = &dp;
        return calculate(n, m);
    }
};