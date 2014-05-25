#include <stdio.h>

// class Solution {
// public:
//     bool canJump(int A[], int n) {
//         if (n == 1)
//             return true;
//         for (int i = 1; n - i > 0; i++)
//             if (canJump(A, n - i) && A[n-i] >= i)
//                 return true;
//         return false;
//     }
// };

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0)
            return false;
        int cur = 1;
        int max = A[0];

        while (cur < n && cur <= max) {
            if (A[cur] + cur >= max)
                max = A[cur] + cur;
            cur++;
        }
        return max >= (n - 1);
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    int A[] = {2, 3, 1, 1, 4};
    int B[] = {3, 2, 1, 0, 4};
    printf("%d\n", sol.canJump(A, 5));
    printf("%d\n", sol.canJump(B, 5));
}
