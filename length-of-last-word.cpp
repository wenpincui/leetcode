class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int cur = 0, len = 0;

        while (s[cur] != '\0') {
            if (s[cur] != ' ') {
                len = 0;
                while (s[cur] != '\0' && s[cur] != ' ') {
                    len++;
                    cur++;
                }
            } else
                cur++;
        }

        return len;
    }
};
