#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();

        if (size == 0)
            return 0;

        int dp[size+1];

        dp[0] = 1;

        for (int i = 1; i <= size; i++) {
            dp[i] = dp[i-1];
            if (s[i-1] != '0') {
                if (s[i-2] == '1')
                    dp[i] += dp[i-2];
                else if (s[i-2] == '2' && s[i-1] <= '6')
                    dp[i] += dp[i-2];
            } else {
                if (i == 1) {
                    dp[0] = 0;
                    dp[i] = 0;
                } else {
                    if (s[i-2] == '2' || s[i-2] == '1')
                        dp[i] = dp[i-2];
                    else
                        return 0;
                }
            }

//            printf("[%02d] dp %d\n", i, dp[i]);
        }

        return dp[size];
    }
};

int main(int argc, char **argv)
{
    Solution sol;

    cout<<sol.numDecodings("12")<<endl;
    cout<<sol.numDecodings("27")<<endl;
    cout<<sol.numDecodings("12632")<<endl;
    cout<<sol.numDecodings("0")<<endl;
    cout<<sol.numDecodings("300")<<endl;
    cout<<sol.numDecodings("110")<<endl;
    cout<<sol.numDecodings("00")<<endl;
    cout<<sol.numDecodings("100")<<endl;

    return 0;
}
