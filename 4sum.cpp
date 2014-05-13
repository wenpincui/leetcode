#include <stdio.h>
#include <vector>

using namespace std;

bool CompareOperation(int a, int b)
{
    return (a < b)?true:false;
}

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        int p1, p2, p3, p4;
        int size = num.size();

        sort(num.begin(), num.end(), CompareOperation);

        for (p1 = 0; p1 < size - 2; p1++) {
            for (p4 = p1 + 2; p4 < size; p4++) {
                int two_sum = target - num[p1] - num[p4];
                p2 = p1 + 1;
                p3 = p4 - 1;
//                printf("p1:%d, p2:%d, p3:%d, p4:%d\n", num[p1], num[p2], num[p3], num[p4]);
                while (p2 <= p3 -1) {
                    if (num[p2] + num[p3] == two_sum) {
                        vector<int> tmp;
//                    printf("push -> p1:%d, p2:%d, p3:%d, p4:%d\n", p1, p2, p3, p4);
                        tmp.push_back(num[p1]);
                        tmp.push_back(num[p2]);
                        tmp.push_back(num[p3]);
                        tmp.push_back(num[p4]);
                        if (find(ret.begin(), ret.end(), tmp) == ret.end())
                            ret.push_back(tmp);
                        p2++;
                        p3--;
                    } else if (num[p2] + num[p3] < two_sum) {
                        p2++;
                    } else
                        p3--;
                }
            }
        }

        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> num;
    vector<vector<int> > ret;
    vector<vector<int> >::iterator iter;

    num.push_back(-5);
    num.push_back(-4);
    num.push_back(-3);
    num.push_back(-2);
    num.push_back(-1);
    num.push_back(0);
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);

    ret = sol.fourSum(num, 0);

    for (iter = ret.begin(); iter != ret.end(); iter++) {
        vector<int> result = *iter;
        vector<int>::iterator iter2;
        for (iter2 = result.begin(); iter2 != result.end(); iter2++)
            printf("%d, ", *iter2);
        printf("\n");
    }

}
