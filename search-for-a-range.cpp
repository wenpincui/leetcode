#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int tar;
    int *num;
    int max;
    int min;
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        tar = target;
        num = A;

        if (n == 0) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }

        min = n;
        max = -1;

        find(0, n-1);

        if (max == -1)
            min = -1;

        ret.push_back(min);
        ret.push_back(max);

        return ret;
    }

    void find(int start, int end) {
        if (num[start] > tar || num[end] < tar)
            return;

        if (start == end && (num[start] == tar)) {
            if (start < min)
                min = start;
            if (start > max)
                max = start;
            return;
        }

        find(start, start + (end - start)/2);
        find(start + (end -start)/2 + 1, end);
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    int nums[] = {5, 7, 7, 8, 9, 10};
    vector<int> ret;

    ret = sol.searchRange(nums, sizeof(nums)/sizeof(int), 8);

    for (vector<int>::iterator iter = ret.begin();
         iter != ret.end(); iter++) {
        printf("%d\t", *iter);
    }
    printf("\n");
}
