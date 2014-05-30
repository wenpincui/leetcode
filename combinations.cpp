// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void find_ans(vector<vector<int> > &ans, int n, int k, int s) {
        if (s > k)
            return;

        if (s == 1) {
            vector<int> tmp;
            for (int i = 1; i <= n-k+1; i++) {
                tmp.push_back(i);
                ans.push_back(tmp);
                tmp.pop_back();
            }
        } else {
            vector<vector<int> > ans2;
            for (vector<vector<int> >::iterator iter = ans.begin();
                 iter != ans.end(); iter++) {
                vector<int> num = *iter;
                int last = num[num.size() - 1];
                for (int i = last + 1; i <= n; i++) {
//                    printf("pushing %d, last %d\n", i, last);
                    num.push_back(i);
                    ans2.push_back(num);
                    num.pop_back();
                }
            }
            swap(ans2, ans);
        }

        find_ans(ans, n, k, s+1);
    }

    vector<vector<int> > combine(int n, int k) {
      vector<vector<int> > ans;

      if (n < k || k == 0)
          return ans;

      find_ans(ans, n, k, 1);

      return ans;
    }
};

void print_ans(vector<vector<int> > &ans)
{
    cout<<"-------------"<<endl;
    for (vector<vector<int> >::iterator iter = ans.begin();
         iter != ans.end(); iter++) {
        vector<int> ans1 = *iter;
        for (vector<int>::iterator iter1 = ans1.begin();
             iter1 != ans1.end(); iter1++)
            cout<<*iter1<<",";
        cout<<endl;
    }
}

int main(int argc, char **argv)
{
    vector<vector<int> > ans;
    Solution sol;

    ans = sol.combine(4, 2);
    print_ans(ans);

    ans = sol.combine(4, 4);
    print_ans(ans);

    ans = sol.combine(3, 4);
    print_ans(ans);

    ans = sol.combine(3, 0);
    print_ans(ans);

    return 0;
}
