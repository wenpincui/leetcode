#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;

        for (int i = 0; i < n; i++) {
            ret ^= A[i];
        }

        return ret;
    }
};

int main(int argc, char **argv)
{
    int nums[] = {1, 2, 3, 3, 2, 1, 4};
    Solution sol;

    printf("ret %d\n", sol.singleNumber(nums, sizeof(nums)/sizeof(int)));
}
