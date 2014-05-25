#include <stdio.h>
#include <iostream>

using namespace std;

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");
}

#define swap(a, b)                              \
    do {                                        \
        int tmp = a;                            \
        a = b;                                  \
        b = tmp;                                \
    } while (0)

void down(int A[], int n, int i)
{
    if (n == 0)
        return;

    while (1) {
        int j = 2 * i + 1;
        if (j >= n)
            break;

        if ((j + 1) < n && A[j+1] > A[j])
            j++;

        if (A[i] < A[j])
            swap(A[i], A[j]);

        i = j;
    }
}

void sort(int A[], int n)
{
    for (int i = n - 1; i >=0; i--) {
        int father = (i - 1)/2;
        if (i > 0 && A[father] < A[i]) {
            int tmp = A[i];
            A[i] = A[father];
            A[father] = tmp;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(A[0], A[i]);
        down(A, i, 0);
        printf("[%d] ", n - i);
        print(A, n);
    }
}

int main(int argc, char **argv)
{
    int A[] = {3, 1, 9, 11, 13, 4, 9, 6, 12, 53};

    sort(A, sizeof(A)/sizeof(int));

    print(A, sizeof(A)/sizeof(int));

    return 0;
}
