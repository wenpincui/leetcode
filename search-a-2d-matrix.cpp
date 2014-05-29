#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find_row(vector<vector<int> > &matrix, int target, int start, int end) {
        if (end == -1)
            return -1;

        while (start != end) {
            if (end - start == 1) {
                if ((matrix[end])[0] <= target)
                    return end;
                if ((matrix[start])[0] <= target)
                    return start;
                return -1;
            }

            int mid = (start + end)/2;
            int mid_val = (matrix[mid])[0];

            if (mid_val > target)
                end = mid - 1;
            else
                start = mid;
        }

        if (start == 0 && (matrix[0])[0] > target)
            return -1;

        return start;
    }

    bool find_column(vector<int> &elem, int target, int start, int end) {
        while (start != end) {
            if (end - start == 1) {
                if (target == elem[start])
                    return true;
                if (target == elem[end])
                    return true;
                return false;
            }
            int mid = (start + end)/2;
            if (elem[mid] == target)
                return true;
            else if (elem[mid] > target)
                end = mid;
            else
                start = mid;
        }

        if (elem[start] == target)
            return true;

        return false;
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = find_row(matrix, target, 0, matrix.size()-1);

        if (row == -1)
            return false;

        vector<int> row_elem = matrix[row];

        return find_column(row_elem, target, 0, row_elem.size()-1);
    }
};

// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
int main(int argc, char **argv) {
    vector<vector<int> >matrix;
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(3);
    tmp.push_back(5);
    tmp.push_back(7);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(10);
    tmp.push_back(11);
    tmp.push_back(16);
    tmp.push_back(20);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(23);
    tmp.push_back(30);
    tmp.push_back(34);
    tmp.push_back(50);
    matrix.push_back(tmp);

    Solution sol;
    cout<<sol.searchMatrix(matrix, 50)<<endl;

    return 0;
}
