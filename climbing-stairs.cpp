#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Solution {
public:
    int *cache;
    int line;
    int possibility(int m, int n) {
        int ret;
        int index = m + n * line;

        if (m == 0 || n == 0)
            return 1;

        if (*(cache + index) != -1)
            return *(cache + index);

        ret = possibility(m - 1, n) + possibility(m, n - 1);
        *(cache + index) = ret;

        return ret;
    }

    int climbStairs(int n) {
        int accum = 0;
        int a = n, b = 0;
        int i;
        line = n;

        cache = (int *)malloc(sizeof(int) * n * n);
        for (i = 0; i < n * n; i++)
            *(cache + i) = -1;

        do {
            accum += possibility(a, b);
            a -= 2;
            b++;
        } while (a >= 0);

        free(cache);

        return accum;
    }
};

int main(int argc, char **argv)
{
    Solution sol;

//    printf("possibility %d\n", sol.possibility(3, 5));
    printf("ret %d\n", sol.climbStairs(44));
}
