#include <stdio.h>

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        int sign = 1;
        if (x < 0) {
            x = -x;
            sign = -1;
        }

        while (x > 0) {
            ret = ret * 10 + x%10;
            x /= 10;
        }

        return ret * sign;
    }
};

int main(int argc, char **argv)
{
    Solution sol;

    printf("%d\n", sol.reverse(123));
}
