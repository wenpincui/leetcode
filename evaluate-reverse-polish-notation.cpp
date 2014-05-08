#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int add(int first, int sec) {
        return sec + first;
    }

    int sub(int first, int sec) {
        return first - sec;
    }

    int mul(int first, int sec) {
        return first * sec;
    }

    int div(int first, int sec) {
        return first/sec;
    }

    int evalRPN(vector<string> &tokens) {
        vector<string>::iterator iter;
        int stack[32];
        int sp = 0;

        for (iter = tokens.begin(); iter != tokens.end(); iter++) {
            if (*iter == "+")
                stack[sp - 2] = add(stack[--sp], stack[--sp]);
            else if (*iter == "-")
                stack[sp - 2] = sub(stack[--sp], stack[--sp]);
            else if (*iter == "*")
                stack[sp - 2] = mul(stack[--sp], stack[--sp]);
            else if (*iter == "/")
                stack[sp - 2] = div(stack[--sp], stack[--sp]);
            else
                stack[sp] = atoi((*iter).c_str());

            sp++;
        }

        return stack[0];
    }
};

int main(int argc, char **argv)
{
    vector<string> s;
    Solution *sol = new Solution();

    s.push_back("4");
    s.push_back("13");
    s.push_back("5");
    s.push_back("/");
    s.push_back("+");

    printf("ret %d\n", sol->evalRPN(s));

    return 0;
}
