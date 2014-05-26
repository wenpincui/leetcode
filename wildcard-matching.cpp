#include <stdio.h>
#include <string.h>

class Solution {
public:
    char map[100000];

    int hash(const char *s, int len1, const char *p, int len2) {
        int ret = 0;
        for (int i = 0; i < len1; i++) {
            ret += 1<<s[i];
        }
        for (int i = 0; i < len2; i++) {
            ret += p[i]<<1;
        }
        return ret%100000;
    }

    bool match(const char *s, int len1, const char *p, int len2) {
        int key = hash(s, len1, p, len2);
        if (map[key] != -1)
            return map[key]==0?false:true;

        if (len2 == 0 && len1 == 0)
            goto out1;
        if (len2 == 0 && len1 != 0)
            goto out2;
        if (len2 == 1) {
            if (p[0] == '*')
                goto out1;
            if (len1 == 1 && (p[0] == '?' || p[0] == s[0]))
                goto out1;
            goto out2;
        }

        if (p[len2-1] == '*') {
            int ret = false;;
            while (len1-1 >= 0) {
                ret = ret || match(s, len1-1, p, len2);
                if (ret)
                    break;
                ret = ret || match(s, len1, p, len2-1);
                len1--;
            }
            return ret;
        } else if (p[len2-1] == '?') {
            if (len1 >= 1)
                return match(s, len1-1, p, len2-1);
            else
                goto out2;
        } else {
            if (len1 >= 1) {
                if (p[len1-1] == s[len2-1])
                    return match(s, len1-1, p, len2-1);
                else
                    goto out2;
            } else
                goto out2;
        }
    out1:
        map[key] = 1;
        return true;
    out2:
        map[key] = 0;
        return false;
    }

    bool isMatch(const char *s, const char *p) {
        for (int i = 0; i < 100000; i++)
            map[i] = -1;
        return match(s, strlen(s), p, strlen(p));
    }
};

//isMatch("aa","a") → false
//isMatch("aa","aa") → true
//isMatch("aaa","aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false

int main(int argc, char **argv)
{
    Solution sol;

    printf("%d\n", sol.isMatch("aa","a"));
    printf("%d\n", sol.isMatch("aa","aa"));
    printf("%d\n", sol.isMatch("aaa","aa"));
    printf("%d\n", sol.isMatch("aa", "*"));
    printf("%d\n", sol.isMatch("aa", "a*"));
    printf("%d\n", sol.isMatch("ab", "?*"));
    printf("%d\n", sol.isMatch("aab", "c*a*b"));
//    printf("%d\n", sol.isMatch("aaabaaabaabababbabababaababbabbbbaaaaababbaabbbaab",
//                               "*babbbb*aab**b*bb*aa*"));
}
