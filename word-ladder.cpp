#include <vector>
#include <unordered_set>
#include <string>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
            return 1;

        int length = 1;

        queue<string> queue_push;
        queue<string> queue_pop;

        if (dict.count(start) > 0)
            dict.erase(start);
        if (dict.count(end) > 0)
            dict.erase(end);

        queue_pop.push(start);

        while (!queue_pop.empty()) {
            string bar = queue_pop.front();
            queue_pop.pop();
            for (int i = 0; i < start.size(); i++) {
                for (int c = 'a'; c <= 'z'; c++) {
                    if (bar[i] == c)
                        continue;
                    char tmp = bar[i];
                    bar[i] = c;
                    if (bar == end)
                        return length+1;
                    if (dict.count(bar) > 0) {
                        dict.erase(bar);
                        queue_push.push(bar);
                    }
                    bar[i] = tmp;
                }
            }
            if (queue_pop.empty()) {
                swap(queue_push, queue_pop);
                length++;
            }
        }

        return 0;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    unordered_set<string> dict;

    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    printf("%d\n", sol.ladderLength("hit", "cog", dict));
}
