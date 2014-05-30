#include <iostream>

using namespace std;

class Solution {
public:
    double calc_pow(double x, int n) {
        if (n == 1)
            return x;

        double ret = calc_pow(x, n/2);
        if (n & 1)
            return x * ret * ret;
        else
            return ret * ret;
    }

    double pow(double x, int n) {
        if (n == 0)
            return 1;
        if (x == 1)
            return 1;
        if (x == -1 && n & 1)
            return -1;
        if (x == -1 && (n&1) == 0)
            return 1;

        if (n < 0)
            return 1/(calc_pow(x, -n));
        else
            return calc_pow(x, n);
    }
};

int main(int argc, char **argv)
{
    Solution sol;

    cout<<sol.pow(0.00001, 2147483647)<<endl;
}
