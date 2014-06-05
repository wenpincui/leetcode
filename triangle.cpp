#include <iostream>
#include <vector>

using namespace std;

#define DP
#ifndef DP
class Solution {
public:
    int min_num(vector<vector<int> > &triangle, int pos, int level, int total) {
        if (level == total - 1) {
            return triangle[level-1][pos] +
                min(triangle[level][pos], triangle[level][pos+1]);
        }

        return triangle[level-1][pos] +
            min(min_num(triangle, pos, level+1, total),
                min_num(triangle, pos+1, level+1, total));
    }

    int minimumTotal(vector<vector<int> > &triangle) {
        int level = triangle.size();

        if (level == 1)
            return triangle[0][0];

        return min_num(triangle, 0, 1, level);
    }
};
#else
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<vector<int> > dp(triangle);
        int level = triangle.size();
        int ans;
        if (level == 1)
            return triangle[0][0];

        for (int i = 1; i < level; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0)
                    dp[i][j] = dp[i-1][j];
                else if (j == triangle[i].size()-1)
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]);

                dp[i][j] += triangle[i][j];
            }

            if (i == level-1) {
                ans = dp[i][0];
                for (int k = 1; k < triangle[i].size(); k++)
                    if (dp[i][k] < ans)
                        ans = dp[i][k];
            }
        }

        return ans;
    }
};
#endif

int main() {
    Solution sol;
    vector<vector<int> > triangle;
    vector<int> tmp;

    tmp.push_back(2);
    triangle.push_back(tmp);
    tmp.clear();

    tmp.push_back(3);
    tmp.push_back(4);
    triangle.push_back(tmp);
    tmp.clear();

    tmp.push_back(6);
    tmp.push_back(5);
    tmp.push_back(7);
    triangle.push_back(tmp);
    tmp.clear();

    tmp.push_back(4);
    tmp.push_back(1);
    tmp.push_back(8);
    tmp.push_back(3);
    triangle.push_back(tmp);
    tmp.clear();

    cout<<"ans:" << sol.minimumTotal(triangle) <<endl;

    return 0;
}
