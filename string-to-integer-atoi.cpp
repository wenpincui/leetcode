#include <string>
#include <cstdio>

using namespace std;

class Solution {
public:
#define INT_MAX 2147483647
#define INT_MIN -2147483648
    void preprocess(const char *str, int *start, int *end) {
        int i;
        int len = strlen(str);

        for (i = 0; str[i] != '\0'; i++) {
            if (str[i] != ' ') {
                *start = i;
                break;
            }
        }

        if (str[i] == '\0')
            return;
        for (i = *start; i < len; i++) {
            if ((str[i] >= '0' && str[i] <= '9') ||
                str[i] == '+' || str[i] == '-')
                *end = i;
            else
                break;
        }

        return;
    }

    bool check_char(const char *str, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (str[i] > '9' || str[i] < '0')
                return false;
        }

        return true;
    }

    void remove_zero(const char *str, int *start, int *end) {
        while (*start <= *end) {
            if (str[*start] == '0')
                (*start)++;
            else
                break;
        }
    }

    bool check_boundary(const char *str, int start, int end, int sign) {
        string INT_STR = "214748364";

        if ((end-start+1) > 10)
            return false;
        else if ((end-start+1) < 10)
            return true;
        else {
            for (int i = start; i < end; i++) {
                if (str[i] > INT_STR[i-start])
                    return false;
                else if (str[i] == INT_STR[i-start])
                    continue;
                else
                    return true;
            }

            if (sign == 1 && str[end] > '7')
                return false;
            if (sign == -1 && str[end] > '8')
                return false;
        }

        return true;
    }

    int convert(const char *str, int start, int end) {
        int ans = str[start] - '0';
        start++;

        while (start <= end) {
            ans *= 10;
            ans += str[start] - '0';
            start++;
        }

        return ans;
    }

    int atoi(const char *str) {
        if (str == NULL)
            return 0;

        int sign = 1;
        int start = -1;
        int end = -1;
        preprocess(str, &start, &end);

        if (start == -1 || end == -1)
            return 0;

        if (str[start] == '+') {
            start++;
        } else if (str[start] == '-') {
            start++;
            sign = -1;
        }

        if (!check_char(str, start, end))
            return 0;

        remove_zero(str, &start, &end);
        if (start > end)
            return 0;

        if (!check_boundary(str, start, end, sign)) {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }

        return sign * convert(str, start, end);
    }
};

int main(int argc, char **argv)
{
    Solution sol;

    printf("[00]%d\n", sol.atoi("1"));
    printf("[01]%d\n", sol.atoi(""));
    printf("[02]%d\n", sol.atoi(" "));
    printf("[03]%d\n", sol.atoi(NULL));
    printf("[04]%d\n", sol.atoi("a"));
    printf("[05]%d\n", sol.atoi("1a"));
    printf("[06]%d\n", sol.atoi("23 4"));
    printf("[07]%d\n", sol.atoi("+123"));
    printf("[08]%d\n", sol.atoi("+"));
    printf("[09]%d\n", sol.atoi("-"));
    printf("[10]%d\n", sol.atoi("-123"));
    printf("[11]%d\n", sol.atoi("12+3"));
    printf("[12]%d\n", sol.atoi("00000"));
    printf("[13]%d\n", sol.atoi("+-2"));
    printf("[14]%d\n", sol.atoi("  -0012a42"));
    printf("[15]%d\n", sol.atoi("2147483648"));
    printf("[16]%d\n", sol.atoi("1095502006p8"));

    return 0;
}
