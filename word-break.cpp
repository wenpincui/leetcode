#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool do_find(string s, unordered_set<string> &dict) {
        if (find(dict.begin(), dict.end(), s) != dict.end())
            return true;
        int size = s.size() - 1;
        if (size == -1)
            return false;
        while (size != 0) {
            string sub = s.substr(0, size);
            if (find(dict.begin(), dict.end(), sub) != dict.end()) {
                if (wordBreak(s.substr(size), dict))
                    return true;
            }
            size--;
        }
        return false;
    }

    int find_bit(string s) {
        int map = 0;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            map |= 1<<(s[i]-'a');
        }

        return map;
    }

    bool wordBreak(string s, unordered_set<string> &dict) {
        int s_bitmap = 0;
        int d_bitmap = 0;

        s_bitmap = find_bit(s);
        for (unordered_set<string>::iterator iter = dict.begin();
             iter != dict.end(); iter++)
            d_bitmap |= find_bit(*iter);

        if (s_bitmap & (~d_bitmap))
            return false;
        return do_find(s, dict);
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    unordered_set<string> dict;
    dict.insert("aaaa");
    dict.insert("aa");
    string s("aaaaaaa");

    cout<<sol.wordBreak(s, dict)<<endl;
}
