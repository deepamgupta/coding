// https://leetcode.com/problems/longest-consecutive-sequence/
#include <bits/stdc++.h>
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int maxLength = 0;
        for (int num : nums)
        {
            if (!mp[num])
            {
                int numsToLeft = mp.find(num - 1) != mp.end() ? mp[num - 1] : 0;
                int numsToRight = mp.find(num + 1) != mp.end() ? mp[num + 1] : 0;

                int totalConsecutiveNums = numsToLeft + 1 + numsToRight;

                mp[num] = totalConsecutiveNums;
                maxLength = max(maxLength, totalConsecutiveNums);

                mp[num - numsToLeft] = totalConsecutiveNums;
                mp[num + numsToRight] = totalConsecutiveNums;
            }
        }
        return maxLength;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    cout << Solution().longestConsecutive(nums);
}
