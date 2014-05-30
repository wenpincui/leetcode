#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void find_ans(vector<vector<string> > &ans, vector<string> &tmp,
                  int n, int row, int *sol) {
        if (row == n) {
            (*sol)++;
            return;
        }

        for (int k = 0; k < n; k++) {
            bool can = true;
            tmp[row][k] = 'Q';
            for (int i = 0; i < row; i++) {
                if (can == false)
                    break;
                for (int j = 0; j < n; j++) {
                    if ((j == k) && tmp[i][j] == 'Q')
                        can = false;
                    if (((row-i) == abs(k-j)) && tmp[i][j] == 'Q')
                        can = false;
                }
            }

            if (can)
                find_ans(ans, tmp, n, row+1, sol);

            tmp[row][k] = '.';
        }
    }

    int totalNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> tmp;
        int sol = 0;

        if (n == 0)
            return sol;

        for (int i = 0; i < n; i++) {
            tmp.push_back(string(n, '.'));
        }

        find_ans(ans, tmp, n, 0, &sol);

        return sol;
    }
};


int main(int argc, char **argv)
{
    Solution sol;

    cout<<sol.totalNQueens(4)<<endl;
}
