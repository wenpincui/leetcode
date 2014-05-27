#include <stdio.h>

class Solution {
public:
    int find_dir(int Q[], int size) {
        int head = Q[0];
        return 1;
        for (int i = 1; i < size; i++) {
            if (Q[i] > head)
                return 1;
            else if (Q[i] < head)
                return 0;
        }
        return -1;
    }

    void merge(int A[], int m, int B[], int n) {
        if (n == 0)
            return;
        if (m == 0) {
            for (int i = 0; i < n; i++)
                A[i] = B[i];
            return;
        }

        if (m == 1 && n == 1) {
            A[1] = B[0];
            return;
        } else {
            int dir1 = 1, dir2 = -1;
            if (m > 1)
                dir1 = find_dir(A, m);
            if (n > 1 && dir1 == -1)
                dir2 = find_dir(B, m);
            if (dir1 == -1 && dir2 == -1)
                return append(A, m, B, n);
            else {
                int dir = (dir1 == -1)?dir2:dir1;
                return merge_with_dir(A, m, B, n, dir);
            }
        }
    }

    void merge_with_dir(int A[], int m, int B[], int n, int dir) {
        int p0 = m-1;
        int p1 = n-1;

        if (dir) {
            for (int pos = m+n-1; pos >= 0; pos--) {
                if (p0 != -1) {
                    if (A[p0] >= B[p1] || p1 == -1)
                        A[pos] = A[p0--];
                    else
                        A[pos] = B[p1--];
                } else
                    A[pos] = B[p1--];
            }
        } else {
            for (int pos = m+n-1; pos >= 0; pos--) {
                if (p0 != -1) {
                    if (A[p0] <= B[p1] || p1 == -1)
                        A[pos] = A[p0--];
                    else
                        A[pos] = B[p1--];
                } else
                    A[pos] = B[p1--];
            }
        }
    }

    void append(int A[], int m, int B[], int n) {
        for (int i = m; i < m+n; i++)
            A[i] = B[i-m];
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    int A[24] = {2};
    int B[12] = {1};

    sol.merge(A, 1, B, 1);

    for (int i = 0; i < 3; i++)
        printf("%d\n", A[i]);
}
