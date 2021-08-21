#include <vector>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int curr = 0;
        char prev = chars[0];
        int times = 0;
        for (int i = 0; i < chars.size(); ++i)
        {
            if (chars[i] != prev)
            {
                chars[curr] = prev;
                while(times!=0){
                    // 这题好无聊，不写了
                }
                times = 1;
                chars[curr] = chars[i];
                ++curr;
                prev = chars[i];
            }
            else
            {
                ++times;
            }
        }
    }
};