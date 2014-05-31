#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        vector<int> backup(numbers);
        sort(numbers.begin(), numbers.end());

        int left = 0;
        int right = numbers.size() -1;

        while (left < right) {
            if (left > 0 && numbers[left] == numbers[left-1]) {
                left++;
                continue;
            }
            if (right < numbers.size() - 1 && numbers[right] == numbers[right+1]) {
                right--;
                continue;
            }
            int sum = numbers[left] + numbers[right] - target;
            if (sum > 0)
                right--;
            else if (sum < 0)
                left++;
            else
                break;
        }

        if (left >= right)
            return ans;

        vector<int>::iterator iter = find(backup.begin(), backup.end(), numbers[left]);
        int ans1 = iter - backup.begin() + 1;
        if (numbers[left] == numbers[right])
            iter = find(iter + 1, backup.end(), numbers[right]);
        else
            iter = find(backup.begin(), backup.end(), numbers[right]);
        int ans2 = iter - backup.begin() + 1;
        ans.push_back(min(ans1, ans2));
        ans.push_back(max(ans1, ans2));

        return ans;
    }
};
