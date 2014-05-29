#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void find_ans(vector<int> &ans, vector<vector<int> > &matrix, int m, int n, int dem) {
        int y = m - dem * 2;
        int x = n - dem * 2;
        int y0 = (m - y)/2;
        int y1 = (m + y)/2 - 1;
        int x0 = (n - x)/2;
        int x1 = (n + x)/2 - 1;

        // printf("x0 %d, x1 %d, y0 %d, y1 %d, x %d, y %d\n",
        //        x0, x1, y0, y1, x, y);

        if (x == 0 || y == 0)
            return;
        if (x0 == x1) {
            for (int i = y0; i <= y1; i++)
                ans.push_back(matrix[x0][i]);
        } else if (y0 == y1) {
            for (int i = x0; i <= x1; i++)
                ans.push_back(matrix[i][y0]);
        } else {
            int i = x0, j = y0;
            for (i = x0; i < x1; i++)
                ans.push_back(matrix[i][j]);
            for (j = y0; j < y1; j++)
                ans.push_back(matrix[i][j]);
            for (i = x1; i > x0; i--)
                ans.push_back(matrix[i][j]);
            for (j = y1; j > y0; j--)
                ans.push_back(matrix[i][j]);
            find_ans(ans, matrix, m, n, dem + 1);
        }
    }

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0)
            return ans;
        int n = matrix[0].size();
        if (n == 0)
            return ans;

        find_ans(ans, matrix, n, m, 0);

        return ans;
    }
};

int main(int argc, char **argv)
{
    vector<vector<int> > matrix;
    vector<int> tmp;
    tmp.push_back(2);
    tmp.push_back(5);
    tmp.push_back(8);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(4);
    tmp.push_back(0);
    tmp.push_back(-1);
    matrix.push_back(tmp);
    // tmp.clear();
    // tmp.push_back(7);
    // tmp.push_back(8);
    // tmp.push_back(9);
//    matrix.push_back(tmp);

    Solution sol;
    tmp = sol.spiralOrder(matrix);
    for (vector<int>::iterator iter = tmp.begin();
         iter != tmp.end(); iter++)
        cout<<*iter<<endl;
}
