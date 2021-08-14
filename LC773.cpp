#include <array>
#include <vector>
#include <map>
using std::array;
using std::vector;
using std::map;

class Solution {
    array<array<int, 6>, 6> dis{
        0, 1, 2, 1, 2, 3,
        1, 0, 1, 2, 1, 2,
        2, 1, 0, 3, 2, 1,
        1, 2, 3, 0, 1, 2,
        2, 1, 2, 1, 0, 1,
        3, 2, 1, 2, 1, 0};

    short unsigned int hash(vector<vector<int>> &board) {
        return board[0][0] +
               (board[0][1] << 3) +
               (board[0][2] << 6) +
               (board[1][0] << 9) +
               (board[1][1] << 12);
    }

public:
    int slidingPuzzle(vector<vector<int>> &board) {
    }
};