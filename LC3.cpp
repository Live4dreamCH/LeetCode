// 一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
// 0 <= s.length <= 5 * 10^4
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0, r = 0, len = 0;
        unordered_map<char, int> sub;
        for (; l < s.size(); ++l)
        {
            while (r <= s.size())
            {
                if (r == s.size())
                {
                    if (r - l > len)
                    {
                        len = r - l;
                    }
                    return len;
                }
                if (sub.find(s[r]) == sub.end() || sub[s[r]] < l)
                {
                    sub[s[r]] = r;
                    ++r;
                }
                else
                {
                    break;
                }
            }
            if (r - l > len)
            {
                len = r - l;
            }
            l = sub[s[r]];
        }
        return len;
    }
};

int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << s.lengthOfLongestSubstring(str);
    return 0;
}