#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    int find_sum(int A[], int a, int b) {
        int sum = 0;
        for (int i = a; i <= b; i++)
            sum += A[i];

        return sum;
    }

    int maxSubArray(int A[], int n) {
        if (n == 0)
            return 0;
        int max1 = A[0];
        for (int i = 0; i < n; i++) {
            if (A[i] > max1)
                max1 = A[i];
        }
        if (max1 <= 0)
            return max1;

        int ans = 0;
        int sum = -1;

        for (int i = 0; i < n; i++) {
            if (A[i] > 0) {
                if (sum < 0)
                    sum = A[i];
                else
                    sum += A[i];

                ans = max(sum, ans);
            } else
                sum += A[i];
        }

        return max(ans, sum);
    }
};

int main(int argc, char **argv)
{
    int A[] = {-1, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;

    cout<<sol.maxSubArray(A, 9)<<endl;

    return 0;
}
