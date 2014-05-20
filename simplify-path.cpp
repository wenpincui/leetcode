#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string ret;
        int slow = -1;
        int fast = 0;
        stack<string> tmp_stack;
        string dotdot("..");
        string dot(".");

        tmp_stack.push("/");
        while (1) {
            if (slow == path.size())
                break;

            if (path[fast] == '/' || fast == path.size()) {
                string elem = path.substr(slow + 1, fast - slow - 1);
                slow = fast;
                if (elem == "")
                    goto cont;
                if (elem == dotdot) {
                    if (tmp_stack.size() != 1)
                        tmp_stack.pop();
                    goto cont;
                } else if (elem == dot) {
                    goto cont;
                } else {
                    tmp_stack.push(elem);
                }
            }
        cont:
            if (fast == path.size())
                break;
            fast++;
        }

        if (tmp_stack.size() == 1)
            ret = "/";
        else {
            while (tmp_stack.size() != 1) {
                ret = "/" + tmp_stack.top() + ret;
                tmp_stack.pop();
            }
        }

//        cout<<"[ret]"<<ret<<endl;

        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    string t1("/home/");
    string t2("/a/./b/../../c/");
    string t3("/");
    string t4("/home///tt");

    cout<<sol.simplifyPath(t1)<<endl;
    cout<<sol.simplifyPath(t2)<<endl;
    cout<<sol.simplifyPath(t3)<<endl;
    cout<<sol.simplifyPath(t4)<<endl;
//    cout<<t1<<"-->"<<sol.simplifyPath(t1)<<endl;
//    cout<<t2<<"-->"<<sol.simplifyPath(t2)<<endl;

    return 0;
}
