#include <stdio.h>
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

class Solution {
public:
    int search(int A[], int n, int target) {
        int new_index = -1;
        int rotate = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] == target)
                new_index = i;
            if (i + 1 < n) {
                if (A[i] > A[i + 1])
                    rotate = n - i - 1;
            }
        }

        printf("new_index %d, rotate %d\n", new_index, rotate);

        return new_index;
#if 0
        if (new_index == -1)
            return new_index;
        else if (new_index < rotate || rotate == 0)
            return new_index + rotate + 1;
        else
            return new_index + rotate - n + 1;
#endif
    }
};

int main(int argc, char **argv)
{
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    int B[] = {1, 3};
    int C[] = {3, 1};
    Solution sol;

    printf("%d\n", sol.search(A, 7, 1));
    printf("%d\n", sol.search(B, 2, 3));
    printf("%d\n", sol.search(C, 2, 1));
}
