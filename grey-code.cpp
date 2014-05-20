#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>::iterator iter;
        vector<int> ret;

        if (n == 0) {
            ret.push_back(0);
        } else if (n == 1) {
            ret.push_back(0);
            ret.push_back(1);
        } else {
            vector<int> tmp = grayCode(n - 1);
            int next_zero = 1;
            for (iter = tmp.begin(); iter != tmp.end(); iter++) {
                if (next_zero) {
                    ret.push_back((*iter)<<1);
                    ret.push_back(((*iter)<<1) + 1);
                    next_zero = 0;
                } else {
                    ret.push_back(((*iter)<<1) + 1);
                    ret.push_back((*iter)<<1);
                    next_zero = 1;
                }
            }
        }
        return ret;
    }
};

void print_bin(int num, int bit) {
    while (bit-- != 0) {
        printf("%d", num & 1);
        num >>= 1;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> result;
    vector<int>::iterator iter;

    result = sol.grayCode(0);

    for (iter = result.begin(); iter != result.end(); iter++)
        print_bin(*iter, 0);

    return 0;
}
