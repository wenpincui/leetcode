#include <iostream>
#include <stdio.h>

using namespace std;

void generate(int a, int b, int N, int *Q)
{
    int A[N];
    int B[N];

    Q[0] = a;
    A[0] = 2*a;
    B[0] = b;

    for (int i = 1; i < N; i++) {
        Q[i] = min(A[i-1], B[i -1]);

        if (Q[i] % a == 0)
            A[i] = Q[i] + a;
        else
            A[i] = (Q[i] > A[i-1])?(A[i-1] + a):A[i-1];

        if (Q[i] % b == 0)
            B[i] = Q[i] + b;
        else
            B[i] = (B[i-1] > Q[i])?B[i-1]:(B[i-1]+b);
    }
}

int main(int argc, char **argv)
{
    int Q[10];

    generate(3, 5, 10, Q);
    for (int i = 0; i < 10; i++)
        printf("%d\n", Q[i]);

    return 0;
}
