class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int *ret = A;

        if (n == 0)
            return 0;

        for (int i = 1; i < n; i++) {
            if (A[i] != *ret)
                *(++ret) = A[i];
        }

        return ret - A + 1;
    }
};
