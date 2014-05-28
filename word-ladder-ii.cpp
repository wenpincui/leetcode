#include <vector>
#include <unordered_set>
#include <string>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ans;
        if (start == end)
            return ans;

        int length = 1;
        bool has_ans = false;

        queue<vector<string> > queue_push;
        queue<vector<string> > queue_pop;

        vector<string> s1;
        s1.push_back(start);
        queue_pop.push(s1);

        while (!queue_pop.empty()) {
            unordered_set<string> tmp_dict(dict);
            vector<string> foo = queue_pop.front();
            string bar = foo.back();

            for (vector<string>::iterator iter2 = foo.begin();
                 iter2 != foo.end(); iter2++)
                tmp_dict.erase(*iter2);

            queue_pop.pop();

            for (int i = 0; i < start.size(); i++) {
                for (int c = 'a'; c <= 'z'; c++) {
                    if (bar[i] == c)
                        continue;
                    char tmp = bar[i];
                    bar[i] = c;

                    if (find(foo.begin(), foo.end(), bar) != foo.end()) {
                        bar[i] = tmp;
                        continue;
                    }
                    if (bar == end) {
                        foo.push_back(bar);
                        ans.push_back(foo);
                        has_ans = true;
                    }
                    if (tmp_dict.count(bar) > 0) {
                        vector<string> tmp(foo);
                        tmp.push_back(bar);
                        queue_push.push(tmp);
                    }
                    bar[i] = tmp;
                }
            }
            if (queue_pop.empty() && !has_ans) {
                swap(queue_push, queue_pop);
                length++;
            }
        }

        if (!has_ans)
            ans.clear();
        return ans;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    unordered_set<string> dict;
    vector<vector<string> > ans;

    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    ans = sol.findLadders("hit", "cog", dict);

//    printf("ans size  %d\n", ans.size());
    for (vector<vector<string> >::iterator iter = ans.begin();
         iter != ans.end(); iter++) {
        for (vector<string>::iterator iter2 = (*iter).begin();
             iter2 != (*iter).end(); iter2++)
            cout<<*iter2<<" ";
        cout<<endl;
    }
}
