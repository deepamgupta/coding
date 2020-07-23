// https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1144/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int nums_size = nums.size();
        if (!nums_size)
            return -1;
        else if (nums_size == 1)
            return 0;
        else
        {
            int prefix_sum = 0;
            int postfix_sum = accumulate(nums.begin() + 1, nums.end(), 0);
            int pivot_index = 0;
            for (pivot_index = 0; pivot_index < nums_size && prefix_sum != postfix_sum; pivot_index++)
            {
                prefix_sum += nums[pivot_index];
                postfix_sum -= nums[pivot_index+1];
            }
            if (pivot_index < nums_size)
                return pivot_index;
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution s = Solution();
    cout << s.pivotIndex(nums) << "\n";
}