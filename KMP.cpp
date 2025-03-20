#include "KMP.h"

template<typename T>
vector<int> gen_KMP_next(const T& sub) {
	vector<int> res;
	if (0 == sub.size()) {
		return res;
	}
	res.emplace_back(0);
	for (int i = 1;i < sub.size();++i) {
		int j = i;
		for (; j > 0; j = res[j - 1]) {
			if (sub[i] == sub[res[i - 1]]) {
				res.emplace_back(res[i - 1] + 1);
				break;
			}
		}
		if (0 == j) {
			res.emplace_back(0);
		}
	}
	return res;
}