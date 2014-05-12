#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int ret = 0;

        if (j < 1)
            return 0;

        while (i < j) {
            ret = max(ret, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return ret;
    }
};

int main(int argc,char **argv)
{
    vector<int> container;
    int i;
    Solution *sol = new Solution();

    container.push_back(1);
    container.push_back(3);
    container.push_back(5);
    container.push_back(4);
    container.push_back(1);
    container.push_back(3);
    container.push_back(6);
    container.push_back(2);
    for (i = 100; i > 80; i--)
        container.push_back(i);

    printf("result %d\n", sol->maxArea(container));
}
