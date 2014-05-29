#include <vector>
#include <unordered_set>
#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
    int min;
    int max;
    void find_ans(vector<string> &ans, string &s, unordered_set<string> &dict,
                  string &tmp, int size) {
        string foo = s.substr(size);
        int tmp_size = tmp.size();
        if (dict.count(foo) > 0) {
//            printf("found ans, last %s\n", foo.c_str());
            tmp += foo;
            ans.push_back(tmp);
            tmp = tmp.substr(0, tmp_size);
            dict.erase(foo);
            find_ans(ans, s, dict, tmp, size);
            dict.insert(foo);
        } else {
            for (int i = min; i <= max && (size + i) <= s.size(); i++) {
                string bar = foo.substr(0, i);
                if (dict.count(bar) > 0) {
//                    printf("found %s\n", bar.c_str());
                    tmp = tmp + bar + " ";
                    find_ans(ans, s, dict, tmp, size + i);
                    tmp = tmp.substr(0, tmp_size);
                }
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ans;
        int bitmap = 0;

        min = INT_MAX;
        max = -1;

        if (s.size() == 0 || dict.size() == 0)
            return ans;

        for (unordered_set<string>::iterator iter = dict.begin();
             iter != dict.end(); iter++) {
            string d = *iter;
            int size = d.size();
            if (min > size)
                min = size;
            if (max < size)
                max = size;
            for (int i = 0; i < d.size(); i++)
                bitmap |= 1<<(d[i]-'a');
        }

        bitmap = ~bitmap;

        for (int i = 0; i < s.size(); i++) {
            if ((1<<(s[i]-'a')) & bitmap)
                return ans;
        }
        string tmp;
        find_ans(ans, s, dict, tmp, 0);

        return ans;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    string s = "aaaaaaa";
    unordered_set<string> dict;
    dict.insert("aaaa");
    dict.insert("aa");
    dict.insert("a");

    vector<string> ans;
    ans = sol.wordBreak(s, dict);

    for (vector<string>::iterator iter = ans.begin();
         iter != ans.end(); iter++)
        cout<<"ans: "<<*iter<<endl;

    return 0;
}
