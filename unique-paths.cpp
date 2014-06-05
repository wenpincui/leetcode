#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int M[m][n];
        for (int i = 0; i < n; i++)
            M[0][i] = 1;

        for (int i = 0; i < m; i++)
            M[i][0] = 1;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                M[i][j] = M[i-1][j] + M[i][j-1];

        return M[m-1][n-1];
    }
};

int main(void)
{
    Solution sol;

    cout<<"ans:"<<sol.uniquePaths(3, 7)<<endl;
}
