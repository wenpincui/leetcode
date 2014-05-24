#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;

        int max = 0;
        int min = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] - min > max)
                max = prices[i] - min;
            if (prices[i] < min)
                min = prices[i];
        }

        return max;
    }
};

int main(int argc, char **argv)
{
    vector<int> prices;
    Solution sol;

    prices.push_back(1);
    prices.push_back(2);

    printf("ret %d\n", sol.maxProfit(prices));

    return 0;
}
