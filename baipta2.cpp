// 给定某数字A（1≤A≤9）以及非负整数N（0≤N≤100000），求数列之和S=A+AA+AAA+⋯+AA⋯A（N个A）。
// 例如A=1, N=3时，S=1+11+111=123。

// 输入格式：
// 输入数字A与非负整数N。

// 输出格式：
// 输出其N项数列之和S的值。
#include <stdio.h>
int s[100010];
int main() {
    int a, n, jin, i, j;
    scanf("%d %d", &a, &n);
    jin = 0;
    if (n == 0) {
        printf("0");
    } else {
        for (i = 0; i < n; i++) {
            s[i] = (n - i) * a + jin;
            jin = s[i] / 10;
            s[i] = s[i] % 10;
        }
        while (jin > 0) {
            n = n + 1;
            s[n - 1] = jin % 10;
            jin = jin / 10;
        }
        for (j = n - 1; j >= 0; j--) {
            printf("%d", s[j]);
        }
    }
    return 0;
}