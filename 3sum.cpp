#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void add(vector<vector<int> > &ans, int a, int b, int c) {
        vector<int> tmp;
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        ans.push_back(tmp);
    }

    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;

        int size = num.size();
        if (size < 3)
            return ans;

        sort(num.begin(), num.end());

        for (int i = 0; i < size -2; i++) {
            if (i > 0 && num[i] == num[i-1])
                continue;
            int left = i+1, right = size-1;
            while (left < right) {
                if (left > i+1 && num[left] == num[left-1]) {
                    left++;
                    continue;
                }
                if (right < size-1 && num[right] == num[right+1]) {
                    right--;
                    continue;
                }
                int sum = num[left] + num[right] + num[i];
                if (sum > 0)
                    right--;
                else if (sum < 0)
                    left++;
                else {
                    add(ans, num[i], num[left], num[right]);
                    left++;
                }
            }
        }

        return ans;
    }
};

void print_ans(vector<vector<int> > &ans) {
    vector<vector<int> >::iterator iter;

    for (iter = ans.begin(); iter != ans.end(); iter++) {
        vector<int> num = *iter;
        cout<<"------------------"<<endl;
        for (vector<int>::iterator iter2 = num.begin();
             iter2 != num.end(); iter2++)
            cout<<*iter2<<", ";
        cout<<endl;
    }
}

int main(int argc, char **argv)
{
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);

    Solution sol;
    vector<vector<int> > ans;
    ans = sol.threeSum(nums);

    print_ans(ans);
}
