#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void dump(vector<vector<int> > &nums) {
        vector<vector<int> >::iterator iter;

        for (iter = nums.begin(); iter != nums.end(); iter++) {
            vector<int> num = *iter;
            vector<int>::iterator iter2;
            for (iter2 = num.begin(); iter2 != num.end(); iter2++)
                printf("%d, ", *iter2);
            printf("\n");
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        if (num.size() == 0) {
            vector<vector<int> > result;
            return result;
        }

        sort(num.begin(), num.end());
        return walk(num);
    }

    vector<vector<int> > walk(vector<int> &num) {
        vector<vector<int> > result;
        vector<int>::iterator iter;

//        printf("size %d\n", num.size());
        if (num.size() == 1) {
            result.push_back(num);
            return result;
        }

        for (iter = num.begin(); iter != num.end(); iter++) {
            int prev;
            if (iter == num.begin() || (*iter) != prev) {
                prev = *iter;
                int offset = iter - num.begin();
                vector<int> copy(num);
                copy.erase(copy.begin() + offset);
                vector<vector<int> > tmp;
                tmp = walk(copy);
                vector<vector<int> >::iterator iter2;
                for (iter2 = tmp.begin(); iter2 != tmp.end(); iter2++) {
                    (*iter2).push_back(*iter);
                    result.push_back(*iter2);
                }
            }
        }

//        printf("----\n");
//        dump(result);

        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    sol.permuteUnique(num);
}
