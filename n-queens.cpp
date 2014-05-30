#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void find_ans(vector<vector<string> > &ans, vector<string> &tmp,
                  int n, int row) {
        if (row == n) {
            ans.push_back(tmp);
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
                find_ans(ans, tmp, n, row+1);

            tmp[row][k] = '.';
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> tmp;

        if (n == 0)
            return ans;

        for (int i = 0; i < n; i++) {
            tmp.push_back(string(n, '.'));
        }

        find_ans(ans, tmp, n, 0);

        return ans;
    }
};

void print_ans(vector<vector<string> > &ans)
{
    for (vector<vector<string> >::iterator iter = ans.begin();
         iter != ans.end(); iter++) {
        vector<string> ans1 = *iter;
        cout<<"----------------"<<endl;
        for (vector<string>::iterator iter1 = ans1.begin();
             iter1 != ans1.end(); iter1++)
            cout<<*iter1<<endl;
    }
}

int main(int argc, char **argv)
{
    vector<vector<string> > ans;
    Solution sol;

    ans = sol.solveNQueens(4);
    print_ans(ans);
//    ans = sol.solveNQueens(8);
//    print_ans(ans);
}
