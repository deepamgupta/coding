// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> req;

        // find in unordered_map best case -> O(1)

        for (int i = 0; i < n; ++i)
        {
            if (req.find(nums[i]) == req.end())
            {
                req[target - nums[i]] = i;
            }
            else
            {
                return {req[nums[i]], i};
            }
        }
        return {0, 0};
    }
};

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    vector<int> ans = Solution().twoSum(nums, target);
    cout << ans[0] << " " << ans[1];
    return 0;
}
