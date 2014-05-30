#include <string>
#include <iostream>

using namespace std;

//#define RECURSION
#ifdef RECURSION
class Solution {
public:
    bool find_ans(string s1, string s2, string s3) {
//        cout<<"find ans: "<<s1<<","<<s2<<","<<s3<<endl;
        int ans = false;
        if (s3 == "")
            return true;
        if (s1 == "")
            return s2 == s3;
        if (s2 == "")
            return s1 == s3;

        if (s3[0] == s1[0])
            ans |= find_ans(s1.substr(1), s2, s3.substr(1));
        if (ans)
            return ans;
        if (s3[0] == s2[0])
            ans |= find_ans(s1, s2.substr(1), s3.substr(1));
        return ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        int c1[26], c2[26], c3[26];
        for (int i = 0; i < 26; i++) {
            c1[i] = 0;
            c2[i] = 0;
            c3[i] = 0;
        }

        for (int i = 0; i < s1.size(); i++)
            c1[s1[i]-'a']++;
        for (int i = 0; i < s2.size(); i++)
            c2[s2[i]-'a']++;
        for (int i = 0; i < s3.size(); i++)
            c3[s3[i]-'a']++;

        for (int i = 0; i < 26; i++) {
            if (c1[i] + c2[i] != c3[i])
                return false;
        }

        return find_ans(s1, s2, s3);
    }
};
#else // dynamic programing
class Solution {
public:
    bool find_ans(string s1, string s2, string s3) {
        int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        bool dp[size1+1][size2+1];

        for (int i = 0; i < size1; i++)
            for (int j = 0; j < size2; j++)
                dp[i][j] = false;

        dp[0][0] = true;

        for (int k = 1; k <= size3; k++) {
//            printf("------------\n");
            for (int i = 0; i <= min(size1, k); i++) {
                int j = k-i;
                if (j > size2)
                    continue;
                dp[i][j] = false;
                if (j > 0 && dp[i][j-1] && s3[k-1] == s2[j-1])
                    dp[i][j] = true;
                if (i > 0 && dp[i-1][j] && s3[k-1] == s1[i-1])
                    dp[i][j] = true;
//                printf("i %d, j %d, dp %d\n", i, j, dp[i][j]);
            }
        }

        return dp[size1][size2];
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        int c1[26], c2[26], c3[26];
        for (int i = 0; i < 26; i++) {
            c1[i] = 0;
            c2[i] = 0;
            c3[i] = 0;
        }

        for (int i = 0; i < s1.size(); i++)
            c1[s1[i]-'a']++;
        for (int i = 0; i < s2.size(); i++)
            c2[s2[i]-'a']++;
        for (int i = 0; i < s3.size(); i++)
            c3[s3[i]-'a']++;

        for (int i = 0; i < 26; i++) {
            if (c1[i] + c2[i] != c3[i])
                return false;
        }

        return find_ans(s1, s2, s3);
    }
};
#endif

int main(int argc, char **argv)
{
    Solution sol;
    string s1 = "aabcc";
    string s2 = "dbbca";

    cout<<sol.isInterleave(s1, s2, "aadbbcbcac")<<endl;
    cout<<sol.isInterleave(s1, s2, "aadbbbaccc")<<endl;

    s1 = "abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb";
    s2 = "ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc";
    cout<<sol.isInterleave(s1, s2, "cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc")<<endl;
}
