#include <string>
using std::string;
/*给你一个以二进制形式表示的数字 s 。请你返回按下述规则将其减少到 1 所需要的步骤数：
如果当前数字为偶数，则将其除以 2 。
如果当前数字为奇数，则将其加上 1 。
题目保证你总是可以按上述规则将测试用例变为 1 。
示例 1：
输入：s = "1101"
输出：6
解释："1101" 表示十进制数 13 。
Step 1) 13 是奇数，加 1 得到 14 1110
Step 2) 14 是偶数，除 2 得到 7 0111
Step 3) 7  是奇数，加 1 得到 8 1000
Step 4) 8  是偶数，除 2 得到 4 0100
Step 5) 4  是偶数，除 2 得到 2 0010
Step 6) 2  是偶数，除 2 得到 1 0001*/

int step_count(string& bin_str) {
	bin_str = '0' + bin_str;
	int ans = 0;
	for (int i = bin_str.size() - 1; i >= 0; --i) {
		if ('0' == bin_str[i]) {
			++ans;
			continue;
		}
		while ('1' == bin_str[--i])
		{

		}

	}
}