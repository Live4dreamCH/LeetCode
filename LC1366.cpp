#include "MyLib.h"
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        const int n = votes.size();
        const int len = votes[0].size();
        vector<vector<int>> char_pos_matrix(26, vector<int>(len, 0));
        for (const string& vote : votes) {
            for (int i = 0; i < len; ++i) {
                ++char_pos_matrix[vote[i] - 'A'][i];
            }
        }
        string res = votes[0];
        std::sort(res.begin(), res.end(), [&](const char& l, const char& r) {
            for (int i = 0; i < len; ++i) {
                if (char_pos_matrix[l - 'A'][i] > char_pos_matrix[r - 'A'][i]) {
                    return true;
                }
                else if (char_pos_matrix[l - 'A'][i] < char_pos_matrix[r - 'A'][i]) {
                    return false;
                }
            }
            return l < r;
         });
        return res;
    }
};