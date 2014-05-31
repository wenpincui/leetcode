#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;

        int size = s.size();
        int dp[size];
        dp[0] = 0;
        int max1 = 0;
        int pos = 0;
        map<char, int> maps;

        for (int i = 0; i < size; i++) {
            if (maps.find(s[i]) != maps.end() && (maps[s[i]] >= pos)) {
                dp[i+1] = i - maps[s[i]];
                pos = maps[s[i]];
            } else {
                dp[i+1] = dp[i] + 1;
                if (dp[i+1] > max1) {
                    max1 = dp[i+1];
                }
            }
            maps[s[i]] = i;
        }


        return max1;
    }
};

int main(int argc, char **argv)
{
    Solution sol;

    // cout<<sol.lengthOfLongestSubstring("ddddd")<<endl;

    // cout<<sol.lengthOfLongestSubstring("ddadced")<<endl;
    // cout<<sol.lengthOfLongestSubstring("")<<endl;
    // cout<<sol.lengthOfLongestSubstring(" ")<<endl;

    // cout<<sol.lengthOfLongestSubstring("  ")<<endl;
    // cout<<sol.lengthOfLongestSubstring("b  a")<<endl;

    cout<<sol.lengthOfLongestSubstring("cmowfrxsjybld")<<endl;

//    cout<<sol.lengthOfLongestSubstring("hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac")<<endl;

    return 0;
}
