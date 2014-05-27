#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int valid_addr(string s, int start, int end) {
        if (start > end)
            return 0;
        if (end-start < 2)
            return 1;
        else if (end - start == 2) {
            char first = s[start];
            if (first == '0' || first == '1' || first == '2')
                return 1;
            else
                return 0;
        } else
            return 0;
    }

    void find_ip(vector<string> &ans, string &tmp, string s, int start, int end, int depth) {
        if (depth == 3) {
            if (valid_addr(s, start, end)) {
                tmp += s.substr(start, end-start+1);
                ans.push_back(tmp);
                tmp.erase(start+depth);
            }
            return;
        } else {
            for (int p0 = start; p0 <= start + 2; p0++) {
                if (valid_addr(s, start, p0) && p0 <= end) {
                      tmp += s.substr(start, p0-start+1);
                      tmp += ".";
                      find_ip(ans, tmp, s, p0+1, end, depth + 1);
                      tmp.erase(start+depth);
                } else
                    return;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string tmp;

        find_ip(ans, tmp, s, 0, s.size()-1, 0);

        return ans;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    string s("2525511135");
//    string s("0000");

    vector<string> out;

    out = sol.restoreIpAddresses(s);
    vector<string>::iterator iter;
    for (iter = out.begin(); iter != out.end(); iter++)
        cout<<*iter<<endl;
}
