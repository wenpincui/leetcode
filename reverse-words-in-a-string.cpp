#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int pos = 0;
        int start = 0;

        pre_process(s);
        while (s[pos] != '\0') {
            if (s[pos++] == ' ') {
                reverse(s, start, pos - 2);
                start = pos;
            }
        }
        reverse(s, start, pos - 1);
        reverse(s, 0, s.size() - 1);
    }

private:
    void pre_process(string &s) {
        int marker = 0;
        int fill_pointer = 0;

        while (s[marker] != '\0') {
            if (s[marker] == ' ') {
                marker++;
                while (s[marker] == ' ')
                    marker++;
                if (s[marker] == '\0') {
                    s.resize(fill_pointer);
                    return;
                }
                if (fill_pointer != 0)
                    s[fill_pointer++] = ' ';
            }
            s[fill_pointer++] = s[marker++];
        }

        s.resize(fill_pointer);
    }

    void reverse(string &s, int start, int end) {
        char tmp;
        while (start < end) {
            tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }
};

int main(int argc, char **argv)
{
    Solution *s = new Solution();
    string str;

    getline(cin, str);
    s->reverseWords(str);
    cout<<str<<endl;
}
