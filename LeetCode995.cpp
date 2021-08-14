#include "pch.h"
#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int N = A.size();
        vector<int> diff(N - 1, 0);   //diff[i]=count[i+1]-count[i]
        int times = 0, curr = 0;
        for (int i = 0; i < N; i++) {
            if ((A[i] ^ (curr % 2)) == 0) {
                if (i + K <= N)
                    times++;
                else
                    return -1;
                if (i != 0)
                    diff[i - 1]++;
                if (i + K < N)
                    diff[i + K - 1]--;
                curr++;
            }
            if (i != N - 1)
                curr += diff[i];
        }
        return times;
    }
};

/*int main()
{
    vector<int> A = { 0,1,0 };
    Solution S;
    std::cout << S.minKBitFlips(A, 1);
}*/

//0 1 0 1 1 k=100
//2 0 -1-2x
//diff[i]+count[i]= count[i+1]
//count[-1]=0 diff[-1]=0
//N 2

//0, 0, 0, 1, 0, 1, 1, 0 K=3



//1 1  1  1  0  1  2  2  1
//1 0  0 -1  1  1  0 -1  diff


//0 1  1  1  0  1  2  2  1 count


//A = [1, 1, 0], K = 2
//Êä³ö£º - 1

//count: 1 4 9 16 25 36 49 64
//diff:  3 5 7 9
//r_count1 4 9