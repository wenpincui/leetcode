#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> >&ans, vector<int> &tmp,
             vector<int> &S, int size, int pos) {
        if (pos == size)
            ans.push_back(tmp);
        else {
            dfs(ans, tmp, S, size, pos + 1);
            tmp.push_back(S[pos]);
            dfs(ans, tmp, S, size, pos + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        vector<int> tmp;

        sort(S.begin(), S.end());
        dfs(ans, tmp, S, S.size(), 0);

        return ans;
    }
};

void print(vector<vector<int> > sets)
{
    for (int i = 0; i < sets.size(); i++) {
        vector<int> set = sets[i];
        for (int j = 0; j < set.size(); j++)
            printf("%d ", set[j]);
        printf("\n");
    }
}
int main(int argc, char **argv)
{
    vector<int> s;
    Solution sol;

    s.push_back(1);
    s.push_back(2);
    s.push_back(3);

    print(sol.subsets(s));
}
