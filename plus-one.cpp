#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int>::iterator iter1, iter2;
        int need_new_elem = 0;

        iter1 = digits.end() - 1;
        if (*iter1 < 9) {
            (*iter1)++;
            return digits;
        } else {
            while (*iter1 == 9) {
                if (iter1 == digits.begin()) {
                    *iter1 = 0;
                    need_new_elem = 1;
                    break;
                }
                iter1--;
            };
        }

        (*iter1)++;
        for (iter2 = iter1 + 1; iter2 != digits.end(); iter2++)
            *iter2 = 0;

        if (need_new_elem)
            digits.push_back(0);

        return digits;
    }
};

int main(int argc, char **argv)
{
    vector<int> input;
    vector<int>::iterator iter;
    Solution *s = new Solution();

    input.push_back(8);
    input.push_back(9);

    s->plusOne(input);

    for (iter = input.begin(); iter != input.end(); iter++)
        cout << *iter << endl;

    return 0;
}
