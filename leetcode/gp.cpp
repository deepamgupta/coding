// https://leetcode.com/problems/4sum/
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

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        
        
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

    vector<vector<int>> ans = Solution().fourSum(nums, target);
    for (vector<int> quad : ans)
    {
        for (int e : quad)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
