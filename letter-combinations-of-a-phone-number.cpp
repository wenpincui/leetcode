#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> dict;
    Solution() {
        dict.clear();
        dict.push_back(" ");
        dict.push_back("");
        dict.push_back("abc");
        dict.push_back("def");
        dict.push_back("ghi");
        dict.push_back("jkl");
        dict.push_back("mno");
        dict.push_back("pqrs");
        dict.push_back("tuv");
        dict.push_back("wxyz");
    }

    void find(vector<string> &ans, string digits, int start, int end) {
        if (start >= end)
            return;

        bool first = (ans.size() == 0);
        string tmp = dict[digits[start] - '0'];
        vector<string> tmp2;

        for (int i = 0; i < tmp.size(); i++) {
            if (first) {
                tmp2.push_back(string(1, tmp[i]));
            } else {
                for (vector<string>::iterator iter = ans.begin();
                     iter != ans.end(); iter++) {
                    string tmp1 = *iter;
                    tmp1 += string(1, tmp[i]);
                    tmp2.push_back(tmp1);
                }
            }
        }
        if (tmp2.size() != 0)
            swap(ans, tmp2);

        find(ans, digits, start + 1, end);
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits == "") {
            ans.push_back("");
            return ans;
        }

        find(ans, digits, 0, digits.size());

        return ans;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<string> ans;

    ans = sol.letterCombinations("23");

    for (vector<string>::iterator iter = ans.begin();
         iter != ans.end(); iter++)
        cout<<*iter<<endl;
}
